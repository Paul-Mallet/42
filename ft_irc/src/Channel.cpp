/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:59:47 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/03/01 09:42:19 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"
#include "Client.hpp"

Channel::Channel( void ) : _name("Default"), _topic(""), _topicProt(false), _inviteOnly(false), _limit(0) {}

Channel::Channel( std::string name ) : _name(name), _topic(""), _topicProt(false), _inviteOnly(false), _limit(0) {}

Channel::Channel( Channel const & src ) {
	*this = src;
}

Channel::~Channel() {}

Channel & Channel::operator=( Channel const & rhs ) {
    if (this != &rhs) {
        this->_name = rhs._name;
        this->_topic = rhs._topic;
        this->_inviteOnly = rhs._inviteOnly;
        this->_topicProt = rhs._topicProt;
        this->_limit = rhs._limit;
        this->_clients.clear();
        this->_operators.clear();
    }
    return (*this);
}

void Channel::addClient( Client * client ) {
    if (!client) return;
    int fd = client->getFd();

    // Si c'est le tout premier client, il devient automatiquement Opérateur
    if (_clients.empty()) {
        _operators[fd] = client;
        std::cout << "Client " << client->getNickname() << " est le premier : promu OP de " << _name << std::endl;
    }

    this->_clients[fd] = client;
}

void Channel::removeClient( int fd ) {
    _clients.erase(fd);
    _operators.erase(fd); // On le retire aussi des OPs s'il l'était
}

bool Channel::isClientInChannel( int fd ) const {
    // La méthode find() d'une map retourne un itérateur vers l'élément, 
    // ou vers end() si la clé n'existe pas.
    if (this->_clients.find(fd) != this->_clients.end()) {
        return (true);
    }
    return (false);
}

void Channel::broadcast( const std::string & msg, Client * exclude ) {
    std::string packet = msg + "\r\n";
    std::map<int, Client*>::iterator it;

    for (it = this->_clients.begin(); it != this->_clients.end(); ++it) {
        // Si exclude est NULL, on envoie à tout le monde (ex: pour un JOIN)
        // Si exclude est défini, on l'évite (ex: pour un PRIVMSG)
        if (exclude && it->second == exclude)
            continue ;
        send(it->first, packet.c_str(), packet.size(), 0);
    }
}

std::string Channel::getModesString( void ) const {
    std::string modes = "+";
    std::string params = "";

    if (_inviteOnly) modes += "i";
    if (_topicProt)  modes += "t";
    if (!_key.empty()) {
        modes += "k";
        params += " " + _key;
    }
    if (_limit > 0) {
        modes += "l";
        std::stringstream ss;
        ss << " " << _limit;
        params += ss.str();
    }
    return (modes + params);
}

// Génère la liste des pseudos pour la réponse 353 (RPL_NAMREPLY)
// Format : "titi @toto tata" (le @ indique un opérateur)
std::string Channel::getNicknamesList() const {
    std::string list = "";
    std::map<int, Client*>::const_iterator it;

    for (it = this->_clients.begin(); it != this->_clients.end(); ++it) {
        if (isOperator(it->first))
            list += "@";
        list += it->second->getNickname();
        if (it != --this->_clients.end())
            list += " ";
    }
    return (list);
}

void Channel::addOperator(int fd) {
    if (_clients.count(fd)) // On ne peut être OP que si on est dans le channel
        this->_operators[fd] = this->_clients[fd];
}

void Channel::removeOperator(int fd) {
    this->_operators.erase(fd);
}

bool Channel::isOperator( int fd ) const {
    return (this->_operators.find(fd) != this->_operators.end());
}

void Channel::addInvite( int fd ) {
    // On vérifie si déjà invité pour éviter les doublons
    for (size_t i = 0; i < this->_invitedFds.size(); ++i) {
        if (_invitedFds[i] == fd)
            return ;
    }
    this->_invitedFds.push_back(fd);
}

void Channel::removeInvite( int fd ) {
    for (std::vector<int>::iterator it = this->_invitedFds.begin(); it != this->_invitedFds.end(); ++it) {
        if (*it == fd) {
            this->_invitedFds.erase(it);
            break ;
        }
    }
}

bool Channel::isInvited( int fd ) const {
    for (size_t i = 0; i < this->_invitedFds.size(); ++i) {
        if (this->_invitedFds[i] == fd)
            return (true);
    }
    return (false);
}

std::string Channel::getName() const {
	return (this->_name);
}

std::string	Channel::getTopic( void ) const {
    return (this->_topic);
}

std::string Channel::getTopicSetter( void ) const {
    return (this->_topicSetter);
}

time_t Channel::getTopicTime( void ) const {
    return (this->_topicTime);
}

bool Channel::isInviteOnly( void ) const {
    return (this->_inviteOnly);
}

bool Channel::hasTopicProt( void ) const {
    return (this->_topicProt);
}

std::string Channel::getKey( void ) const {
    return (this->_key);
}

size_t Channel::getLimit( void ) const {
    return (this->_limit);
}

void Channel::setInviteOnly(bool v) {
    this->_inviteOnly = v;
}

void Channel::setTopicProt(bool v) {
    this->_topicProt = v;
}

void Channel::setKey(std::string k) {
    this->_key = k;
}

void Channel::setLimit(size_t l) {
    this->_limit = l;
}

void Channel::setTopic( const std::string &newTopic, const std::string &setter ) {
    this->_topic = newTopic;
    this->_topicSetter = setter;
    this->_topicTime = time(NULL); // Récupère l'heure actuelle
}

size_t Channel::getSize() const {
	return (this->_clients.size());
}