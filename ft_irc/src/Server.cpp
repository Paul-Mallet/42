/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:53:55 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/03/08 10:52:50 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include "Client.hpp"
#include "Channel.hpp"

Server::Server( void ) : _port(6667), _pwd("password") {}

Server::Server( int port, std::string pwd ) : _port(port), _pwd(pwd) {}

Server::Server( Server const & other ) : _port(other._port), _pwd(other._pwd) {}

Server::~Server() {
    std::map<int, Client*>::iterator it;
    for (it = this->_clients.begin(); it != this->_clients.end(); ++it) {
        int fd = it->first;
        Client* client = it->second;

        close(fd);
        delete client;
        std::cout << "Client sur FD " << fd << " nettoyé." << std::endl;
    }
    this->_clients.clear();

    std::map<std::string, Channel*>::iterator itc;
    for (itc = this->_channels.begin(); itc != this->_channels.end(); ++itc) {
        delete itc->second;
        std::cout << "Channel " << itc->first << " nettoyé." << std::endl;
    }
    this->_channels.clear();

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
	this->_fd = socket(AF_INET6, SOCK_STREAM, 0);
	if (this->_fd < 0)
		throw (SocketException());

    int enable = 1;
    if (setsockopt(this->_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable))) {
        throw (SetSocketOptionException());
    }

	int opt = 0;
	if (setsockopt(this->_fd, IPPROTO_IPV6, IPV6_V6ONLY, &opt, sizeof(opt)) < 0) {
		throw (SetSocketOptionException());
    }

	sockaddr_in6	sin6 = {};
	sin6.sin6_family = AF_INET6;
	sin6.sin6_port = htons(static_cast<uint16_t>(this->_port));
	sin6.sin6_addr = in6addr_any;

	if (fcntl(this->_fd, F_SETFL, O_NONBLOCK) < 0)
		throw (FcntlFailedException());

	if (bind(this->_fd, reinterpret_cast<sockaddr*>(&sin6), sizeof(sin6)) < 0)
		throw (BindFailedException());

	if (listen(this->_fd, 5) < 0)
		throw (ListenFailedException());

    struct pollfd server_pfd;
    server_pfd.fd = this->_fd;
    server_pfd.events = POLLIN;
    server_pfd.revents = 0;

    this->_pollFds.push_back(server_pfd);
}

void Server::sendReply( int fd, const std::string & msg ) {
    std::string fullMsg = msg + "\r\n";
    send(fd, fullMsg.c_str(), fullMsg.size(), 0);
}

void Server::_handlePass( Client * client, std::vector<std::string> args ) {
    if (client->getIsRegistered()) {
        sendReply(client->getFd(), ":localhost 462 :You may not reregister");
        return;
    }

    if (args.empty()) {
        sendReply(client->getFd(), ":localhost 461 PASS :Not enough parameters");
        return;
    }

    if (args[0] == this->_pwd) {
        client->setHasPassedPassword(true);
        std::cout << "FD " << client->getFd() << " a réussi l'étape PASS." << std::endl;
    } else {
        sendReply(client->getFd(), ":localhost 464 :Password mismatch");
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

    if (!std::isalpha(nick[0]))
        return (false);

    std::string charset = "-[]\\`^{}";

    for (size_t i = 0; i < nick.size(); ++i) {
        if (!std::isalnum(nick[i]) && charset.find(nick[i]) == std::string::npos)
            return (false);
    }
    return (true);
}

void Server::_checkRegistration( Client *client ) {
    if (client->getIsRegistered())
        return;

    if (client->getHasPassedPassword() && !client->getNickname().empty() && !client->getUsername().empty()) {
        client->setIsRegistered(true);

        std::string welcome = ":localhost 001 " + client->getNickname() + " :Welcome to the IRC Network!";
        sendReply(client->getFd(), welcome);

        std::cout << "Client " << client->getNickname() << " est maintenant enregistré !" << std::endl;
    }
}

void Server::_handleNick( Client * client, std::vector<std::string> args ) {
    if (!client->getHasPassedPassword()) {
        sendReply(client->getFd(), ":localhost 451 :You have not registered (need PASS)");
        return ;
    }

    if (args.empty()) {
        sendReply(client->getFd(), ":localhost 431 :No nickname given");
        return ;
    }

    std::string newNick = args[0];

    if (!this->_isValidNick(newNick)) {
        sendReply(client->getFd(), ":localhost 432 * " + newNick + " :Erroneous nickname");
        return ;
    }

    if (this->_isNickTaken(newNick)) {
        sendReply(client->getFd(), ":localhost 433 * " + newNick + " :Nickname is already in use");
        return ;
    }

    std::string oldNick = client->getNickname();

    if (client->getIsRegistered()) {
        std::string msg = ":" + oldNick + " NICK " + newNick;
        sendReply(client->getFd(), msg);
    }
    client->setNickname(newNick);

    this->_checkRegistration(client);
}

std::vector<std::string> Server::_splitMessage( std::string msg ) {
    std::vector<std::string> args;

    size_t trailingPos = msg.find(" :");
    std::string trailing;

    if (trailingPos != std::string::npos) {
        trailing = msg.substr(trailingPos + 2);
        msg = msg.substr(0, trailingPos);
    }

    std::stringstream ss(msg);
    std::string word;
    while (ss >> word)
        args.push_back(word);

    if (trailingPos != std::string::npos)
        args.push_back(trailing);

    return (args);
}

void Server::_handleUser( Client * client, std::vector<std::string> args ) {
    if (!client->getHasPassedPassword()) {
        sendReply(client->getFd(), ":localhost 451 :You have not registered (need PASS)");
        return ;
    }

    if (args.size() < 4) {
        sendReply(client->getFd(), ":localhost 461 USER :Not enough parameters");
        return ;
    }

    if (client->getIsRegistered()) {
        sendReply(client->getFd(), ":localhost 462 :You may not reregister");
        return ;
    }

    client->setUsername(args[0]);
    client->setRealname(args[3]);

    std::cout << "FD " << client->getFd() << " a réglé son username : " << args[0] << std::endl;

    this->_checkRegistration(client);
}

void Server::_handlePing( Client * client, std::vector<std::string> args ) {
    if (args.empty()) {
        std::string errorMsg = ":localhost 461 " + client->getNickname() + " PING :Not enough parameters";
        sendReply(client->getFd(), errorMsg);
        return;
    }
    std::string pong = ":localhost PONG localhost :" + args[0] + "\r\n";
    send(client->getFd(), pong.c_str(), pong.length(), 0);

    std::cout << "PONG envoyé au FD " << client->getFd() << std::endl;
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

    Channel * chan = this->_channels[target];

    if (!chan->isClientInChannel(client->getFd())) {
        sendReply(client->getFd(), ":localhost 404 " + target + " :Cannot send to channel");
        return;
    }

    std::string fullMsg = ":" + client->getNickname() + "!" + client->getUsername() 
                        + "@" + client->getHostname() + " PRIVMSG " + target + " :" + msg;
    chan->broadcast(fullMsg, client);
}

void Server::_handlePrivmsg( Client * client, std::vector<std::string> args) {
    if (!client->getIsRegistered()) {
        sendReply(client->getFd(), ":localhost 451 :You have not registered");
        return ;
    }

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

    if (targetNick[0] == '#') {
        this->_handleChannelMsg(client, targetNick, msg);
        return ;
    }

    Client * targetClient = this->_findClientByNick(targetNick);
    if (!targetClient) {
        sendReply(client->getFd(), ":localhost 401 " + targetNick + " :No such nick/channel");
        return ;
    }

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

    if (channelName[0] != '#') {
        sendReply(client->getFd(), ":localhost 403 " + channelName + " :No such channel");
        return ;
    }

    Channel * channel;
    bool isNew = false;
    if (this->_channels.find(channelName) == this->_channels.end()) {
        channel = new Channel(channelName);
        this->_channels[channelName] = channel;
        isNew = true;
    } else {
        channel = this->_channels[channelName];
    }

    if (!isNew) {
        if (channel->isInviteOnly() && !channel->isInvited(client->getFd())) {
            sendReply(client->getFd(), ":localhost 473 " + client->getNickname() + " " + channelName + " :Cannot join channel (+i)");
            return ;
        }

        if (!channel->getKey().empty() && providedKey != channel->getKey()) {
            sendReply(client->getFd(), ":localhost 475 " + client->getNickname() + " " + channelName + " :Cannot join channel (+k)");
            return ;
        }

        if (channel->getLimit() > 0 && channel->getSize() >= channel->getLimit()) {
            sendReply(client->getFd(), ":localhost 471 " + client->getNickname() + " " + channelName + " :Cannot join channel (+l)");
            return ;
        }
    }

    channel->addClient(client);

    channel->removeInvite(client->getFd());

    std::string joinMsg = ":" + client->getNickname() + "!" + client->getUsername() 
                        + "@" + client->getHostname() + " JOIN " + channelName;
    channel->broadcast(joinMsg);

    if (!channel->getTopic().empty())
        sendReply(client->getFd(), ":localhost 332 " + client->getNickname() + " " + channelName + " :" + channel->getTopic());

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

        std::string partMsg = ":" + client->getNickname() + "!" + client->getUsername()
                            + "@" + client->getHostname() + " PART " + name + " :" + reason;

        chan->broadcast(partMsg);
        chan->removeClient(client->getFd());

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

    if (this->_channels.find(channelName) == this->_channels.end()) {
        sendReply(client->getFd(), ":localhost 403 " + channelName + " :No such channel");
        return ;
    }
    Channel *chan = _channels[channelName];

    if (!chan->isClientInChannel(client->getFd())) {
        sendReply(client->getFd(), ":localhost 442 " + channelName + " :You're not on that channel");
        return ;
    }
    if (!chan->isOperator(client->getFd())) {
        sendReply(client->getFd(), ":localhost 482 " + channelName + " :You're not channel operator");
        return ;
    }

    Client *targetClient = this->_findClientByNick(targetNick);
    if (!targetClient || !chan->isClientInChannel(targetClient->getFd())) {
        sendReply(client->getFd(), ":localhost 441 " + targetNick + " " + channelName + " :They aren't on that channel");
        return ;
    }

    std::string kickMsg = ":" + client->getNickname() + "!" + client->getUsername() 
                        + "@" + client->getHostname() + " KICK " + channelName 
                        + " " + targetNick + " :" + reason;

    chan->broadcast(kickMsg);

    chan->removeClient(targetClient->getFd());

    if (chan->getSize() == 0) {
        this->_channels.erase(channelName);
        delete chan;
    }
}

void Server::_disconnectClient( int fd ) {
    std::cout << "Déconnexion du client sur le FD " << fd << std::endl;

    close(fd);

    if (this->_clients.count(fd)) {
        delete this->_clients[fd];
        this->_clients.erase(fd);
    }

    for (std::vector<struct pollfd>::iterator it = this->_pollFds.begin(); it != this->_pollFds.end(); ++it) {
        if (it->fd == fd) {
            this->_pollFds.erase(it);
            break ;
        }
    }
}

void Server::_handleQuit(Client *client, std::vector<std::string> args) {
    std::string reason = "";
    if (args.empty())
        reason = "Client Quit";
    else
        reason = args[0];

    if (client->getIsRegistered()) {
        std::string quitMsg = ":" + client->getNickname() + "!" + client->getUsername()
                            + "@" + client->getHostname() + " QUIT :Quit: " + reason;

        std::map<std::string, Channel*>::iterator it = this->_channels.begin();
        while (it != this->_channels.end()) {
            Channel * chan = it->second;

            if (chan->isClientInChannel(client->getFd())) {
                chan->broadcast(quitMsg, client);
                chan->removeClient(client->getFd());
                if (chan->getSize() == 0) {
                    delete chan;
                    this->_channels.erase(it++);
                    continue ;
                }
            }
            ++it;
        }
    }
    client->setShouldDisconnect(true);
}

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

    if (args.size() == 1) {
        if (chan->getTopic().empty()) {
            sendReply(client->getFd(), ":localhost 331 " + client->getNickname() + " " + targetChan + " :No topic is set");
        } else {
            sendReply(client->getFd(), ":localhost 332 " + client->getNickname() + " " + targetChan + " :" + chan->getTopic());
            std::stringstream ss;
            ss << ":localhost 333 " << client->getNickname() << " " << targetChan << " " << chan->getTopicSetter() << " " << chan->getTopicTime();
            sendReply(client->getFd(), ss.str());
        }
        return ;
    }

    if (!chan->isClientInChannel(client->getFd())) {
        sendReply(client->getFd(), ":localhost 442 " + client->getNickname() + " " + targetChan + " :You're not on that channel");
        return ;
    }

    if (chan->hasTopicProt() && !chan->isOperator(client->getFd())) {
        sendReply(client->getFd(), ":localhost 482 " + client->getNickname() + " " + targetChan + " :You're not channel operator");
        return ;
    }

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

    if (this->_channels.find(channelName) == this->_channels.end()) {
        sendReply(client->getFd(), ":localhost 403 " + client->getNickname() + " " + channelName + " :No such channel");
        return ;
    }
    Channel * chan = this->_channels[channelName];

    if (!chan->isClientInChannel(client->getFd())) {
        sendReply(client->getFd(), ":localhost 442 " + client->getNickname() + " " + channelName + " :You're not on that channel");
        return ;
    }

    if (chan->isInviteOnly() && !chan->isOperator(client->getFd())) {
        sendReply(client->getFd(), ":localhost 482 " + client->getNickname() + " " + channelName + " :You're not channel operator");
        return ;
    }

    Client * targetClient = _findClientByNick(targetNick);
    if (!targetClient) {
        sendReply(client->getFd(), ":localhost 401 " + client->getNickname() + " " + targetNick + " :No such nick/channel");
        return ;
    }

    if (chan->isClientInChannel(targetClient->getFd())) {
        sendReply(client->getFd(), ":localhost 443 " + client->getNickname() + " " + targetNick + " " + channelName + " :is already on channel");
        return ;
    }

    chan->addInvite(targetClient->getFd());
    sendReply(client->getFd(), ":localhost 341 " + client->getNickname() + " " + targetNick + " " + channelName);

    std::string inviteMsg = ":" + client->getNickname() + "!" + client->getUsername() + "@" + client->getHostname() + " INVITE " + targetNick + " " + channelName;
    sendReply(targetClient->getFd(), inviteMsg);
}

void Server::_handleMode( Client * client, std::vector<std::string> args ) {
    if (args.size() < 1) {
        sendReply(client->getFd(), ":localhost 461 MODE :Not enough parameters");
        return ;
    }

    std::string target = args[0];
    if (target[0] != '#')
        return; 

    if (this->_channels.find(target) == this->_channels.end()) {
        sendReply(client->getFd(), ":localhost 403 " + target + " :No such channel");
        return ;
    }

    Channel * chan = this->_channels[target];
    if (args.size() == 1) {
        sendReply(client->getFd(), ":localhost 324 " + client->getNickname() + " " + target + " " + chan->getModesString());
        return ;
    }

    if (!chan->isOperator(client->getFd())) {
        sendReply(client->getFd(), ":localhost 482 " + target + " :You're not channel operator");
        return ;
    }

    std::string modes = args[1];
    size_t argIdx = 2;
    bool adding = true;
    std::string appliedModes = "";

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
            case 'i':
                chan->setInviteOnly(adding);
                appliedModes += "i";
                break ;
            case 't':
                chan->setTopicProt(adding);
                appliedModes += "t";
                break ;
            case 'k':
                if (adding && argIdx < args.size()) {
                    chan->setKey(args[argIdx++]);
                    appliedModes += "k";
                } else if (!adding) {
                    chan->setKey(""); 
                    appliedModes += "k";
                }
                break ;
            case 'l':
                if (adding && argIdx < args.size()) {
                    chan->setLimit(std::atoi(args[argIdx++].c_str()));
                    appliedModes += "l";
                } else if (!adding) {
                    chan->setLimit(0);
                    appliedModes += "l";
                }
                break ;
            case 'o':
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
            default:
                sendReply(client->getFd(), ":localhost 472 " + std::string(1, c) + " :is unknown mode char");
                break ;
        }
    }

    std::string notify = ":" + client->getNickname() + " MODE " + target + " " + appliedModes;
    chan->broadcast(notify);
}

void Server::_processCommand( Client * client, std::string cmd ) {
    if (cmd.empty())
        return ;

    std::string commandName = "";
    std::vector<std::string> args;
    std::stringstream ss(cmd);

    if (!(ss >> commandName))
        return ;

    for (size_t i = 0; i < commandName.size(); i++)
        commandName[i] = std::toupper(commandName[i]);

    std::string arg;
    while (ss >> arg) {
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

    if (commandName == "CAP") {
        sendReply(client->getFd(), ":localhost CAP * LS :");
        return ;
    }
    // 2. Dispatcher (vers les fonctions specifiques)
    else if (commandName == "PASS")
        this->_handlePass(client, args);
    else if (commandName == "NICK")
        this->_handleNick(client, args);
    else if (commandName == "USER")
        this->_handleUser(client, args);
    else if (commandName == "PING")
        this->_handlePing(client, args);
    else if (commandName == "QUIT")
        this->_handleQuit(client, args);
    else if (client->getIsRegistered()) {
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
    }
}

bool isRunning = true;

void handle_sigint(int sig) {
    (void)sig;
    isRunning = false;
}

void Server::start( void ) {
    std::cout << "Serveur lancé..." << std::endl;
	signal(SIGINT, handle_sigint);
    while (isRunning) {
        int poll_count = poll(this->_pollFds.data(), this->_pollFds.size(), -1);

		if (poll_count < 0) {
			if (errno == EINTR)
				continue ;
			break ;
		}

		for (size_t i = 0; i < this->_pollFds.size(); i++) {
			if (this->_pollFds[i].revents & POLLIN) {

				if (this->_pollFds[i].fd == this->_fd) {
                    struct sockaddr_storage client_addr = {};
                    socklen_t addr_len = sizeof(client_addr);
                    int client_fd = accept(this->_fd, (struct sockaddr*)&client_addr, &addr_len);

					if (client_fd >= 0) {
                        char ip_str[INET6_ADDRSTRLEN];

                        if (client_addr.ss_family == AF_INET) {
                            struct sockaddr_in *s = (struct sockaddr_in *)&client_addr;
                            inet_ntop(AF_INET, &s->sin_addr, ip_str, sizeof(ip_str));
                        } else {
                            struct sockaddr_in6 *s = (struct sockaddr_in6 *)&client_addr;
                            inet_ntop(AF_INET6, &s->sin6_addr, ip_str, sizeof(ip_str));
                        }

                        std::string host = ip_str;
                        if (host.find("::ffff:") == 0)
                            host = host.substr(7);
						fcntl(client_fd, F_SETFL, O_NONBLOCK);

						struct pollfd client_pfd = {client_fd, POLLIN, 0};
						this->_pollFds.push_back(client_pfd);

                        this->_clients[client_fd] = new Client(client_fd, host);
						std::cout << "Nouveau client connecté sur FD: " << client_fd << std::endl;
					}
				}
				else {
					char buffer[512];
                    int fd = this->_pollFds[i].fd;
					int bytes_received = recv(fd, buffer, sizeof(buffer) - 1, 0);

					if (bytes_received <= 0) {
                        _handleQuit(this->_clients[_pollFds[i].fd], std::vector<std::string>());
                        _disconnectClient(this->_pollFds[i].fd);
                        --i;
                        continue ;
                    } else {
						buffer[bytes_received] = '\0';
                        std::cout << "msg reçu du FD " << fd << " : " << buffer << std::endl;
						Client* client = this->_clients[fd];

                        try {
                            client->addRawData(buffer);

                            std::string cmd;
                            bool clientDropped = false;

                            while (!(cmd = client->getNextCommand()).empty()) {
                                this->_processCommand(client, cmd);

                                if (client->getShouldDisconnect()) {
                                    this->_disconnectClient(_pollFds[i].fd);
                                    clientDropped = true;
                                    break ;
                                }
                            }

                            if (clientDropped) {
                                --i;
                                continue ;
                            }
                        } catch (std::exception & e) {
                            std::cerr << "Erreur Client FD " << fd << ": " << e.what() << std::endl;
                            std::string errorMsg = "ERROR: Closing Link: Buffer overflow (Stuck Buffer)\r\n";
                            send(fd, errorMsg.c_str(), errorMsg.length(), 0);
						    std::cerr << "Client sur FD " << fd << " déconnecté." << std::endl;

                            close(fd);
                            delete this->_clients[fd];
                            this->_clients.erase(fd);
                            this->_pollFds.erase(this->_pollFds.begin() + i);
                            i--;
                        }
					}
				}
			}
		}
    }
}