/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:53:55 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/03/07 14:40:30 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include "Client.hpp"
#include "Channel.hpp"

Server::Server( void ) : _port(6667), _pwd("password") {}

Server::Server( int port, std::string pwd ) : _port(port), _pwd(pwd) {}

Server::Server( Server const & other ) : _port(other._port), _pwd(other._pwd) {}

Server::~Server() {
    // 1. Fermer et free tous les clients restants
    std::map<int, Client*>::iterator it;
    for (it = this->_clients.begin(); it != this->_clients.end(); ++it) {
        int fd = it->first;
        Client* client = it->second;

        close(fd);
        delete client;
        std::cout << "Client sur FD " << fd << " nettoyé." << std::endl;
    }
    this->_clients.clear();

    // 2. Fermer les channels
    std::map<std::string, Channel*>::iterator itc;
    for (itc = this->_channels.begin(); itc != this->_channels.end(); ++itc) {
        delete itc->second;
        std::cout << "Channel " << itc->first << " nettoyé." << std::endl;
    }
    this->_channels.clear();

    // 3. Fermer le socket listening du serveur
    if (this->_fd != -1) {
        close(this->_fd);
        std::cout << "Socket serveur FD " << this->_fd << " fermé." << std::endl;
    }
    std::cout << "\nArrêt du serveur..." << std::endl;
}

Server & Server::operator=( Server const & rhs ) {
    if (this != &rhs) {
        this->_port = rhs._port;
        this->_pwd = rhs._pwd;
    }
    return (*this);
}

int Server::getFd( void ) const {
    return (this->_fd);
}

void Server::setFd( int newFd ) {
	this->_fd = newFd;
}

long getPort( char ** av ) {
	long port = std::strtol(av[1], NULL, 10);
	if (port < 1024 || port > 65535)
		throw (BadPortException());
	return (port);
}

void Server::init( void ) {
    // 1. Socket server
	this->_fd = socket(AF_INET6, SOCK_STREAM, 0); //only IPv4 (AF_INET)
	if (this->_fd < 0)
		throw (SocketException()); //-1, errno

    // 0 accepte v4
    int enable = 1;
    if (setsockopt(this->_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable))) {
        throw (SetSocketOptionException());
    }
    
    // 0 accepte v6
	int opt = 0;
    // IPPROTO_IPV6, IPV6_V6ONLY
	if (setsockopt(this->_fd, IPPROTO_IPV6, IPV6_V6ONLY, &opt, sizeof(opt)) < 0) {
		throw (SetSocketOptionException()); //-1, errno
    }

	// 2. Set sockaddr_in
	sockaddr_in6	sin6 = {};
	sin6.sin6_family = AF_INET6;
	sin6.sin6_port = htons(static_cast<uint16_t>(this->_port));	// short 16bytes uint16_t for IPv4
	sin6.sin6_addr = in6addr_any;	// IP address (32-bit)

	// 3. fcntl()
	if (fcntl(this->_fd, F_SETFL, O_NONBLOCK) < 0)
		throw (FcntlFailedException());

	// 4. bind()
	if (bind(this->_fd, reinterpret_cast<sockaddr*>(&sin6), sizeof(sin6)) < 0)
		throw (BindFailedException());

	// 5. listen()
	if (listen(this->_fd, 5) < 0)
		throw (ListenFailedException());

    // C'EST ICI : On prepare le premier elem pour poll
    struct pollfd server_pfd;
    server_pfd.fd = this->_fd;
    server_pfd.events = POLLIN;
    server_pfd.revents = 0; // Toujours mettre a 0 au début, laisse OS gerer

    this->_pollFds.push_back(server_pfd);
}

void Server::sendReply( int fd, const std::string & msg ) {
    std::string fullMsg = msg + "\r\n"; // IRC demande toujours \r\n
    send(fd, fullMsg.c_str(), fullMsg.size(), 0);
}

// === SERVER COMMANDS ===

void Server::_handlePass( Client * client, std::vector<std::string> args ) {
    // 1. verif si deja register
    if (client->getIsRegistered()) {
        sendReply(client->getFd(), ":localhost 462 :You may not reregister");
        return;
    }

    // 2. vreif si l'argument existe
    if (args.empty()) {
        sendReply(client->getFd(), ":localhost 461 PASS :Not enough parameters");
        return;
    }

    // 3. verif le mot de passe
    if (args[0] == this->_pwd) {
        client->setHasPassedPassword(true);
        std::cout << "FD " << client->getFd() << " a réussi l'étape PASS." << std::endl;
    } else {
        sendReply(client->getFd(), ":localhost 464 :Password mismatch");
        // Optionnel : on peut decide de deco ici apres X tentatives
    }
}

bool Server::_isNickTaken( const std::string& nick ) {
    std::map<int, Client*>::iterator it;
    for (it = _clients.begin(); it != _clients.end(); ++it) {
        if (it->second->getNickname() == nick)
            return (true);
    }
    return (false);
}

bool Server::_isValidNick( const std::string& nick ) {
    if (nick.empty() || nick.size() > 9)
        return (false);

    // Le premier chars ne peut pas etre un chiffre ou un tiret
    if (!std::isalpha(nick[0]))
        return (false);

    // Liste des chars spe autorized par la RFC
    std::string charset = "-[]\\`^{}";

    for (size_t i = 0; i < nick.size(); ++i) {
        if (!std::isalnum(nick[i]) && charset.find(nick[i]) == std::string::npos)
            return (false);
    }
    return (true);
}

void Server::_checkRegistration( Client *client ) {
    // Si already register, on ne refait pas le Welcome
    if (client->getIsRegistered())
        return;

    // Si les trois conditions sont reuni
    if (client->getHasPassedPassword() && !client->getNickname().empty() && !client->getUsername().empty()) {
        client->setIsRegistered(true);

        // Envoi du msg de bienvenue (RPL_WELCOME 001)
        std::string welcome = ":localhost 001 " + client->getNickname() + " :Welcome to the IRC Network!";
        sendReply(client->getFd(), welcome);

        std::cout << "Client " << client->getNickname() << " est maintenant enregistré !" << std::endl;
    }
}

void Server::_handleNick( Client * client, std::vector<std::string> args ) {
    // 1. secure : Doit avoir fait PASS d'abord
    if (!client->getHasPassedPassword()) {
        sendReply(client->getFd(), ":localhost 451 :You have not registered (need PASS)");
        return ;
    }

    // 2. Erreur : Pas d'argument
    if (args.empty()) {
        sendReply(client->getFd(), ":localhost 431 :No nickname given");
        return ;
    }

    std::string newNick = args[0];

    // 3. Spe. chars and length checks
    if (!_isValidNick(newNick)) {
        sendReply(client->getFd(), ":localhost 432 * " + newNick + " :Erroneous nickname");
        return ;
    }

    // 4. Erreur : Nickname deja use
    if (_isNickTaken(newNick)) {
        sendReply(client->getFd(), ":localhost 433 * " + newNick + " :Nickname is already in use");
        return ;
    }

    // 5. success : On met a jour le client
    std::string oldNick = client->getNickname();

    if (client->getIsRegistered()) {
        // Si deja register, on notifie le changement : :AncienNick NICK NouveauNick
        std::string msg = ":" + oldNick + " NICK " + newNick;
        sendReply(client->getFd(), msg);
        // Note : Plus tard, il faudra envoyer ce msg a tous les gens sur les memes channels - #TODO
    }
    client->setNickname(newNick);

    // 6. verif de l'enregistrement final
    this->_checkRegistration(client);
}

std::vector<std::string> Server::_splitMessage( std::string msg ) {
    std::vector<std::string> args;

    // 1. On cherche si un ':' existe pour le "trailing"
    size_t trailingPos = msg.find(" :");
    std::string trailing;

    if (trailingPos != std::string::npos) {
        // On recup tout ce qui est apres " :"
        trailing = msg.substr(trailingPos + 2);
        // On ne garde que la partie avant le " :" pour le split normal
        msg = msg.substr(0, trailingPos);
    }

    // 2. Split classique par espaces pour le debut
    std::stringstream ss(msg);
    std::string word;
    while (ss >> word)
        args.push_back(word);

    // 3. On rajoute le trailing a la fin s'il existait
    if (trailingPos != std::string::npos)
        args.push_back(trailing);

    return (args);
}

void Server::_handleUser( Client * client, std::vector<std::string> args ) {
    // 1. secure : PASS d'abord
    if (!client->getHasPassedPassword()) {
        sendReply(client->getFd(), ":localhost 451 :You have not registered (need PASS)");
        return ;
    }

    // 2. Erreur : On attend 4 arguments (username, hostname, servername, realname)
    if (args.size() < 4) {
        sendReply(client->getFd(), ":localhost 461 USER :Not enough parameters");
        return ;
    }

    // 3. Erreur : deja register
    if (client->getIsRegistered()) {
        sendReply(client->getFd(), ":localhost 462 :You may not reregister");
        return ;
    }

    // 4. On stocke les infos
    client->setUsername(args[0]);
    // args[1] et args[2] sont souvent ignored par les serveurs modernes mais requis
    client->setRealname(args[3]); // "Name Test" grace au parser

    std::cout << "FD " << client->getFd() << " a réglé son username : " << args[0] << std::endl;

    // 5. Tentative d'enregistrement final
    this->_checkRegistration(client);
}

Client* Server::_findClientByNick( const std::string & nick ) {
    std::map<int, Client*>::iterator it;
    for (it = this->_clients.begin(); it != this->_clients.end(); ++it) {
        if (it->second->getNickname() == nick)
            return it->second;
    }
    return (NULL);
}

void Server::_handleChannelMsg( Client * client, std::string target, std::string msg) {
    if (this->_channels.find(target) == _channels.end()) {
        sendReply(client->getFd(), ":localhost 401 " + target + " :No such nick/channel");
        return;
    }

    Channel *chan = _channels[target];

    // Optionnel : verif si le client est dans le channel
    if (!chan->isClientInChannel(client->getFd())) {
        sendReply(client->getFd(), ":localhost 404 " + target + " :Cannot send to channel");
        return;
    }

    // On broadcast a tout le monde SAUF a l'envoyeur
    std::string fullMsg = ":" + client->getNickname() + "!" + client->getUsername() 
                        + "@" + client->getHostname() + " PRIVMSG " + target + " :" + msg;
    chan->broadcast(fullMsg, client);
}

void Server::_handlePrivmsg( Client * client, std::vector<std::string> args) {
    // 1. secure : doit etre register
    if (!client->getIsRegistered()) {
        sendReply(client->getFd(), ":localhost 451 :You have not registered");
        return ;
    }

    // 2. verif les arguments
    if (args.size() < 1) {
        sendReply(client->getFd(), ":localhost 411 :No recipient given (PRIVMSG)");
        return ;
    }
    if (args.size() < 2) {
        sendReply(client->getFd(), ":localhost 412 :No text to send");
        return ;
    }

    std::string targetNick = args[0];
    std::string msg = args[1];

    // 3.1. Cas particulier : msg a un Channel (on verra ça apres)
    if (targetNick[0] == '#') {
        this->_handleChannelMsg(client, targetNick, msg);
        return ;
    }

    // 3.2. msg a un utilisateur (Private msg)
    Client * targetClient = this->_findClientByNick(targetNick);
    if (!targetClient) {
        sendReply(client->getFd(), ":localhost 401 " + targetNick + " :No such nick/channel");
        return ;
    }

    // 4. Envoi du msg formate
    // Format : :Nick!User@Host PRIVMSG Target :msg
    std::string fullMsg = ":" + client->getNickname() + "!" + client->getUsername() 
                        + "@" + client->getHostname() + " PRIVMSG " + targetNick + " :" + msg;
    sendReply(targetClient->getFd(), fullMsg);
}

void Server::_handleJoin( Client * client, std::vector<std::string> args ) {
    if (!client->getIsRegistered()) {
        sendReply(client->getFd(), ":localhost 451 :You have not registered");
        return ;
    }

    if (args.empty()) {
        sendReply(client->getFd(), ":localhost 461 JOIN :Not enough parameters");
        return ;
    }

    std::string channelName = args[0];
    std::string providedKey = "";

    if (args.size() > 1)
        providedKey = args[1];
    else
        providedKey = "";

    // Un channel doit commencer par #
    if (channelName[0] != '#') {
        sendReply(client->getFd(), ":localhost 403 " + channelName + " :No such channel");
        return ;
    }

    // 1. Trouver ou creer le channel
    Channel * channel;
    bool isNew = false;
    if (this->_channels.find(channelName) == this->_channels.end()) {
        channel = new Channel(channelName);
        this->_channels[channelName] = channel;
        isNew = true;
    } else {
        channel = this->_channels[channelName];
    }

    // --- debut verif des modes (uniquement si le chan n'est pas nouveau) ---
    if (!isNew) {
        // A. verif de l'INVITE ONLY (+i)
        if (channel->isInviteOnly() && !channel->isInvited(client->getFd())) {
            sendReply(client->getFd(), ":localhost 473 " + client->getNickname() + " " + channelName + " :Cannot join channel (+i)");
            return ;
        }

        // B. verif de la CLÉ (+k)
        if (!channel->getKey().empty() && providedKey != channel->getKey()) {
            sendReply(client->getFd(), ":localhost 475 " + client->getNickname() + " " + channelName + " :Cannot join channel (+k)");
            return ;
        }

        // C. verif de la LIMITE (+l)
        if (channel->getLimit() > 0 && channel->getSize() >= channel->getLimit()) {
            sendReply(client->getFd(), ":localhost 471 " + client->getNickname() + " " + channelName + " :Cannot join channel (+l)");
            return ;
        }
    }

    // 2. Ajouter le client au channel
    channel->addClient(client);

    // 2.1 Delete le client #test
    channel->removeInvite(client->getFd());

    // 3. Notifier tout le monde (format: :nick!user@host JOIN #channel)
    std::string joinMsg = ":" + client->getNickname() + "!" + client->getUsername() 
                        + "@" + client->getHostname() + " JOIN " + channelName;
    channel->broadcast(joinMsg);

    // 4. Envoyer le topic (RPL_TOPIC 332)
    if (!channel->getTopic().empty())
        sendReply(client->getFd(), ":localhost 332 " + client->getNickname() + " " + channelName + " :" + channel->getTopic());

    // 5. Envoyer la liste des membres (RPL_NAMREPLY 353 + RPL_ENDOFNAMES 366)
    sendReply(client->getFd(), ":localhost 353 " + client->getNickname() + " = " + channelName + " :" + channel->getNicknamesList());
    sendReply(client->getFd(), ":localhost 366 " + client->getNickname() + " " + channelName + " :End of /NAMES list.");
}

std::vector<std::string> Server::_splitByComma( std::string str ) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, ',')) {
        if (!item.empty())
            tokens.push_back(item);
    }
    return (tokens);
}

void Server::_handlePart( Client * client, std::vector<std::string> args ) {
    if (!client->getIsRegistered()) {
        sendReply(client->getFd(), ":localhost 451 :You have not registered");
        return ;
    }

    if (args.empty()) {
        sendReply(client->getFd(), ":localhost 461 PART :Not enough parameters");
        return ;
    }

    // separe les channels par la virgule (si tu geres les multis)
    std::vector<std::string> channelNames = this->_splitByComma(args[0]);
    std::string reason = "";

    if (args.size() > 1)
        reason = args[1];
    else
        reason = "Leaving";

    for (size_t i = 0; i < channelNames.size(); ++i) {
        std::string name = channelNames[i];

        if (_channels.find(name) == _channels.end()) {
            sendReply(client->getFd(), ":localhost 403 " + name + " :No such channel");
            continue ;
        }

        Channel * chan = this->_channels[name];
        if (!chan->isClientInChannel(client->getFd())) {
            sendReply(client->getFd(), ":localhost 442 " + name + " :You're not on that channel");
            continue ;
        }

        // 1. Notifier tout le monde : :nick!user@host PART #channel :reason
        std::string partMsg = ":" + client->getNickname() + "!" + client->getUsername() 
                            + "@" + client->getHostname() + " PART " + name + " :" + reason;
        chan->broadcast(partMsg); // On broadcast à TOUT LE MONDE, incluant celui qui part

        // 2. Retirer le client du channel
        chan->removeClient(client->getFd());

        // 3. Si le channel est vide, on le detruit
        if (chan->getSize() == 0) {
            std::cout << "Channel " << name << " est vide, suppression." << std::endl;
            this->_channels.erase(name);
            delete (chan);
        }
    }
}

void Server::_handleKick(Client *client, std::vector<std::string> args) {
    if (args.size() < 2) {
        sendReply(client->getFd(), ":localhost 461 KICK :Not enough parameters");
        return ;
    }

    std::string channelName = args[0];
    std::string targetNick = args[1];
    std::string reason = "";
    if (args.size() > 2)
        reason = args[2];
    else
        reason = "No reason given";

    // 1. Le channel existe-t-il ?
    if (this->_channels.find(channelName) == this->_channels.end()) {
        sendReply(client->getFd(), ":localhost 403 " + channelName + " :No such channel");
        return ;
    }
    Channel *chan = _channels[channelName];

    // 2. L'auteur est-il sur le channel et est-il OP ?
    if (!chan->isClientInChannel(client->getFd())) {
        sendReply(client->getFd(), ":localhost 442 " + channelName + " :You're not on that channel");
        return ;
    }
    if (!chan->isOperator(client->getFd())) {
        sendReply(client->getFd(), ":localhost 482 " + channelName + " :You're not channel operator");
        return ;
    }

    // 3. La cible existe-t-elle sur le serveur ?
    Client *targetClient = this->_findClientByNick(targetNick);
    if (!targetClient || !chan->isClientInChannel(targetClient->getFd())) {
        sendReply(client->getFd(), ":localhost 441 " + targetNick + " " + channelName + " :They aren't on that channel");
        return ;
    }

    // 4. Tout est OK : previent tout le monde avant d'expulser
    // Format : :Auteur!User@Host KICK #channel Cible :Raison
    std::string kickMsg = ":" + client->getNickname() + "!" + client->getUsername() 
                        + "@" + client->getHostname() + " KICK " + channelName 
                        + " " + targetNick + " :" + reason;

    chan->broadcast(kickMsg); // previent tout le monde (y compris la cible)

    // 5. Expulsion physique
    chan->removeClient(targetClient->getFd());

    // 6. Optionnel : si le channel est vide, on le delete
    if (chan->getSize() == 0) {
        this->_channels.erase(channelName);
        delete chan;
    }
}

void Server::_disconnectClient( int fd ) {
    std::cout << "Déconnexion du client sur le FD " << fd << std::endl;

    // 1. Fermer le socket
    close(fd);

    // 2. Suppr de la map des clients
    if (this->_clients.count(fd)) {
        delete this->_clients[fd];
        this->_clients.erase(fd);
    }

    // 3. Suppr du tableau pollfds pour que poll() ne le surveille plus
    for (std::vector<struct pollfd>::iterator it = this->_pollFds.begin(); it != this->_pollFds.end(); ++it) {
        if (it->fd == fd) {
            this->_pollFds.erase(it);
            break;
        }
    }
}

void Server::_handleQuit(Client *client, std::vector<std::string> args) {
    // 1. Preparer le message de raison
    std::string reason = "";
    if (args.empty())
        reason = "Client Quit";
    else
        reason = args[0];

    // 2. Si le client etait enregistre, on prévient les autres
    if (client->getIsRegistered()) {
        std::string quitMsg = ":" + client->getNickname() + "!" + client->getUsername()
                            + "@" + client->getHostname() + " QUIT :Quit: " + reason;

        // 2.1 Parcourir tous les channels pour notifier et supprimer
        std::map<std::string, Channel*>::iterator it = this->_channels.begin();
        while (it != this->_channels.end()) {
            Channel * chan = it->second;

            if (chan->isClientInChannel(client->getFd())) {
                // Notifier les autres membres du channel
                chan->broadcast(quitMsg, client);
                // Retirer le client
                chan->removeClient(client->getFd());
                // Si le channel est vide après son départ, on le supprime
                if (chan->getSize() == 0) {
                    delete chan;
                    this->_channels.erase(it++); // it++ pour ne pas invalider l'itérateur, envoie copy a erase, pour permettre ++it apres
                    continue ;
                }
            }
            ++it;
        }
    }
    // 3. Envoyer un dernier message au client (optionnel)
    // sendReply(client->getFd(), "ERROR :Closing Link: " + client->getNickname() + " (" + reason + ")");

    // 4. Marquer le client pour deconnexion
    // fait pas "delete client" ici directement car on est en plein milieu
    // de la boucle de lecture/poll. creer une methode de nettoyage
    // this->_disconnectClient(client->getFd());
    // Au lieu de _disconnectClient(client->getFd());
    client->setShouldDisconnect(true);
}

// date -d @1772351837 to see
void Server::_handleTopic(Client *client, std::vector<std::string> args) {
    if (args.empty()) {
        sendReply(client->getFd(), ":localhost 461 " + client->getNickname() + " TOPIC :Not enough parameters");
        return ;
    }

    std::string targetChan = args[0];
    if (this->_channels.find(targetChan) == this->_channels.end()) {
        sendReply(client->getFd(), ":localhost 403 " + client->getNickname() + " " + targetChan + " :No such channel");
        return ;
    }

    Channel * chan = this->_channels[targetChan];

    // CAS 1 : Consultation du Topic (ex: TOPIC #channel)
    if (args.size() == 1) {
        if (chan->getTopic().empty()) {
            sendReply(client->getFd(), ":localhost 331 " + client->getNickname() + " " + targetChan + " :No topic is set");
        } else {
            // 332: Le texte du topic
            sendReply(client->getFd(), ":localhost 332 " + client->getNickname() + " " + targetChan + " :" + chan->getTopic());
            // 333: Qui l'a mis et quand (format: nick!user@host timestamp)
            std::stringstream ss;
            ss << ":localhost 333 " << client->getNickname() << " " << targetChan << " " << chan->getTopicSetter() << " " << chan->getTopicTime();
            sendReply(client->getFd(), ss.str());
        }
        return ;
    }

    // CAS 2 : modif du Topic (ex: TOPIC #channel :nouveau sujet)
    // Verif si le client est dans le channel
    if (!chan->isClientInChannel(client->getFd())) {
        sendReply(client->getFd(), ":localhost 442 " + client->getNickname() + " " + targetChan + " :You're not on that channel");
        return ;
    }

    // Verif les droits si le mode +t est actif
    if (chan->hasTopicProt() && !chan->isOperator(client->getFd())) {
        sendReply(client->getFd(), ":localhost 482 " + client->getNickname() + " " + targetChan + " :You're not channel operator");
        return ;
    }

    // Mise a jour et Broadcast
    std::string newTopic = args[1];
    chan->setTopic(newTopic, client->getNickname());

    std::string topicNotify = ":" + client->getNickname() + "!" + client->getUsername() + "@" + client->getHostname() + " TOPIC " + targetChan + " :" + newTopic;
    chan->broadcast(topicNotify);
}

void Server::_handleInvite(Client *client, std::vector<std::string> args) {
    if (args.size() < 2) {
        sendReply(client->getFd(), ":localhost 461 " + client->getNickname() + " INVITE :Not enough parameters");
        return ;
    }

    std::string targetNick = args[0];
    std::string channelName = args[1];

    // 1. Le channel existe-t-il ?
    if (this->_channels.find(channelName) == this->_channels.end()) {
        sendReply(client->getFd(), ":localhost 403 " + client->getNickname() + " " + channelName + " :No such channel");
        return ;
    }
    Channel * chan = this->_channels[channelName];

    // 2. L'auteur est-il sur le channel ?
    if (!chan->isClientInChannel(client->getFd())) {
        sendReply(client->getFd(), ":localhost 442 " + client->getNickname() + " " + channelName + " :You're not on that channel");
        return ;
    }

    // 3. Si le mode +i est actif, l'auteur doit être OP
    if (chan->isInviteOnly() && !chan->isOperator(client->getFd())) {
        sendReply(client->getFd(), ":localhost 482 " + client->getNickname() + " " + channelName + " :You're not channel operator");
        return ;
    }

    // 4. La cible existe t elle sur le serveur ?
    Client * targetClient = _findClientByNick(targetNick);
    if (!targetClient) {
        sendReply(client->getFd(), ":localhost 401 " + client->getNickname() + " " + targetNick + " :No such nick/channel");
        return ;
    }

    // 5. La cible est elle deja sur le channel ?
    if (chan->isClientInChannel(targetClient->getFd())) {
        sendReply(client->getFd(), ":localhost 443 " + client->getNickname() + " " + targetNick + " " + channelName + " :is already on channel");
        return ;
    }

    // --- TOUT EST OK ---
    // Ajouter a la liste des invites du channel
    chan->addInvite(targetClient->getFd());

    // Envoyer la confirmation a l'expediteur (RPL_INVITING 341)
    sendReply(client->getFd(), ":localhost 341 " + client->getNickname() + " " + targetNick + " " + channelName);

    // Envoyer l'invitation a la cible (Format : :titi!user@host INVITE toto #channel)
    std::string inviteMsg = ":" + client->getNickname() + "!" + client->getUsername() + "@" + client->getHostname() + " INVITE " + targetNick + " " + channelName;
    sendReply(targetClient->getFd(), inviteMsg);
}

void Server::_handleMode( Client * client, std::vector<std::string> args ) {
    if (args.size() < 1) {
        sendReply(client->getFd(), ":localhost 461 MODE :Not enough parameters");
        return ;
    }

    std::string target = args[0];
    // On ne gere que les modes de CHANNEL (#) pour le sujet
    if (target[0] != '#') return; 

    if (this->_channels.find(target) == this->_channels.end()) {
        sendReply(client->getFd(), ":localhost 403 " + target + " :No such channel");
        return ;
    }
    Channel *chan = this->_channels[target];

    // Cas : MODE #channel (Demande d'affichage des modes actuels)
    if (args.size() == 1) {
        sendReply(client->getFd(), ":localhost 324 " + client->getNickname() + " " + target + " " + chan->getModesString());
        return ;
    }

    // Verif : Seuls les OPs peuvent changer les modes
    if (!chan->isOperator(client->getFd())) {
        sendReply(client->getFd(), ":localhost 482 " + target + " :You're not channel operator");
        return ;
    }

    std::string modes = args[1];
    size_t argIdx = 2; // Index pour les parametres (+k, +o, +l)
    bool adding = true;
    std::string appliedModes = ""; // Pour le broadcast final

    for (size_t i = 0; i < modes.length(); ++i) {
        char c = modes[i];
        if (c == '+') {
            adding = true;
            appliedModes += "+";
            continue ;
        }
        if (c == '-') {
            adding = false;
            appliedModes += "-";
            continue ;
        }

        switch (c) {
            case 'i': // Mode invite-only
                chan->setInviteOnly(adding);
                appliedModes += "i";
                break ;
            case 't': // Mode TOPIC
                chan->setTopicProt(adding);
                appliedModes += "t";
                break ;
            case 'k': // Mode KEY
                if (adding && argIdx < args.size()) {
                    chan->setKey(args[argIdx++]);
                    appliedModes += "k";
                } else if (!adding) {
                    chan->setKey(""); 
                    appliedModes += "k";
                }
                break ;
            case 'l': // Mode LIMIT
                if (adding && argIdx < args.size()) {
                    chan->setLimit(std::atoi(args[argIdx++].c_str()));
                    appliedModes += "l";
                } else if (!adding) {
                    chan->setLimit(0);
                    appliedModes += "l";
                }
                break ;
            case 'o': // Mode OPERATOR
                if (argIdx < args.size()) {
                    Client * targetUser = this->_findClientByNick(args[argIdx++]);
                    if (targetUser && chan->isClientInChannel(targetUser->getFd())) {
                        if (adding)
                            chan->addOperator(targetUser->getFd());
                        else
                            chan->removeOperator(targetUser->getFd());
                        appliedModes += "o";
                    }
                }
                break ;
            default: // Mode inconnu
                sendReply(client->getFd(), ":localhost 472 " + std::string(1, c) + " :is unknown mode char");
                break ;
        }
    }

    // Broadcast du changement (important pour les clients IRC)
    std::string notify = ":" + client->getNickname() + " MODE " + target + " " + appliedModes;
    chan->broadcast(notify);
}

void Server::_processCommand( Client * client, std::string cmd ) {
    if (cmd.empty())
        return ;

    // 1. Decoupage de la ligne
    std::vector<std::string> args;
    std::string commandName;
    std::stringstream ss(cmd);

    ss >> commandName; // Le premier mot est la commande

    // On transforme la commande en MAJUSCULES (standard IRC)
    for (size_t i = 0; i < commandName.size(); i++)
        commandName[i] = std::toupper(commandName[i]);

    // On recup le reste des arguments
    std::string arg;
    while (ss >> arg) {
        // Gestion du "trailing" (si un argument commence par ':')
        if (arg[0] == ':') {
            std::string trailing;
            std::getline(ss, trailing);
            args.push_back(arg.substr(1) + trailing);
            break;
        }
        args.push_back(arg);
    }

    std::cout << "CMD: " << commandName << " | ARGS: ";
    for(size_t i = 0; i < args.size(); i++) 
        std::cout << "[" << args[i] << "] ";
    std::cout << std::endl;

    // 2. Dispatcher (vers les fonctions specifiques)
    if (commandName == "PASS")
        this->_handlePass(client, args);
    else if (commandName == "NICK")
        this->_handleNick(client, args);
    else if (commandName == "USER")
        this->_handleUser(client, args);
    else if (commandName == "QUIT")
        this->_handleQuit(client, args);
    else if (client->getIsRegistered()) {
        // commandes ne sont accessibles que si le client est logged
        if (commandName == "JOIN")
            this->_handleJoin(client, args);
        else if (commandName == "PRIVMSG")
            this->_handlePrivmsg(client, args);
        else if (commandName == "PART")
            this->_handlePart(client, args);
        else if (commandName == "KICK")
            this->_handleKick(client, args);
        else if (commandName == "TOPIC")
            this->_handleTopic(client, args);
        else if (commandName == "INVITE")
            this->_handleInvite(client, args);
        else if (commandName == "MODE")
            this->_handleMode(client, args);
    } else {
        // Optionnel : Envoyer une erreur "Not registered"
    }
}

bool isRunning = true;

void handle_sigint(int sig) {
    (void)sig;
    isRunning = false; // On change le flag global
}

void Server::start( void ) {
    std::cout << "Serveur lancé..." << std::endl;
	signal(SIGINT, handle_sigint);
    while (isRunning) {
        // ici que poll() va utiliser _pollFds
        int poll_count = poll(this->_pollFds.data(), this->_pollFds.size(), -1);

		if (poll_count < 0) {
			if (errno == EINTR)
				continue ; // Si poll a ete interrompu par un signal, on recommence
			break ; // Erreur grave
		}

		for (size_t i = 0; i < this->_pollFds.size(); i++) {
			if (this->_pollFds[i].revents & POLLIN) {

				if (this->_pollFds[i].fd == this->_fd) {
					// --- CAS A : new connexion, create 1 client ---
                    struct sockaddr_storage client_addr = {}; // ipv4 et ipv6
                    socklen_t addr_len = sizeof(client_addr);
                    int client_fd = accept(this->_fd, (struct sockaddr*)&client_addr, &addr_len);

					if (client_fd >= 0) {
                        char ip_str[INET6_ADDRSTRLEN]; // Buffer assez grand pour IPv6

                        if (client_addr.ss_family == AF_INET) {
                            // IPv4
                            struct sockaddr_in *s = (struct sockaddr_in *)&client_addr;
                            inet_ntop(AF_INET, &s->sin_addr, ip_str, sizeof(ip_str));
                        } else {
                            // IPv6
                            struct sockaddr_in6 *s = (struct sockaddr_in6 *)&client_addr;
                            inet_ntop(AF_INET6, &s->sin6_addr, ip_str, sizeof(ip_str));
                        }

                        // creer l'objet Client et l'ajouter à la map, recup l'IP 127.0.0.1
                        std::string host = ip_str;
						// new socket en NON-BLOQUANT
						fcntl(client_fd, F_SETFL, O_NONBLOCK);

                        // L'ajouter au tableau pour poll
						struct pollfd client_pfd = {client_fd, POLLIN, 0};
						this->_pollFds.push_back(client_pfd);

                        this->_clients[client_fd] = new Client(client_fd, host);
						std::cout << "Nouveau client connecté sur FD: " << client_fd << std::endl;
					}
				}
				else {
					// --- CAS B : msg from client already created ---
					char buffer[512]; // Taille standard pour une commande / msg IRC
                    int fd = this->_pollFds[i].fd;
					int bytes_received = recv(fd, buffer, sizeof(buffer) - 1, 0);

					if (bytes_received <= 0) {
                        _handleQuit(this->_clients[_pollFds[i].fd], std::vector<std::string>());
                        _disconnectClient(this->_pollFds[i].fd);
                        --i; // IMPORTANT : reculer l'index car on a suppr un element du vecteur
                        continue ; // On passe au FD suivant
                    } else {
						buffer[bytes_received] = '\0';
                        std::cout << "msg reçu du FD " << fd << " : " << buffer << std::endl; // rm after tests successfully done
						Client* client = this->_clients[fd];

                        try {
                            // 1. On donne les data brutes au client + broken pipe handling
                            client->addRawData(buffer);

                            // 2. On recup TOUTES les commandes completes presentes dans son buffer
                            std::string cmd;
                            bool clientDropped = false;

                            while (!(cmd = client->getNextCommand()).empty()) {
                                this->_processCommand(client, cmd);

                                // Si la commande etait QUIT, on marque le client
                                if (client->getShouldDisconnect()) {
                                    this->_disconnectClient(_pollFds[i].fd);
                                    clientDropped = true;
                                    break ; // On sort du WHILE des commandes
                                }
                            }

                            if (clientDropped) {
                                --i; // recule l'index car le vecteur _pollFds a retreci
                                continue ; // passe au client suivant dans le FOR de poll
                            }
                        } catch (std::exception & e) {
                            // Si addRawData lance une exception (ex: buffer trop gros)
                            std::cerr << "Erreur Client FD " << fd << ": " << e.what() << std::endl;
                            std::string errorMsg = "ERROR: Closing Link: Buffer overflow (Stuck Buffer)\r\n";
                            send(fd, errorMsg.c_str(), errorMsg.length(), 0);
						    std::cerr << "Client sur FD " << fd << " déconnecté." << std::endl;

                            // Deconnexion forcee pour proteger le serveur
                            close(fd);
                            delete this->_clients[fd];
                            this->_clients.erase(fd);
                            this->_pollFds.erase(this->_pollFds.begin() + i);
                            i--;
                        }

						// Ici, devra appeler Parser de commandes (PASS, NICK, etc.)
					}
				}
			}
		}
    }
}