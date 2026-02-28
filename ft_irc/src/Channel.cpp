/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:59:47 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/28 22:37:37 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"
#include "Client.hpp"

Channel::Channel( void ) : _name("Default"), _topic("") {}

Channel::Channel( std::string name ) : _name(name), _topic("") {}

Channel::Channel( Channel const & src ) {
	*this = src;
}

Channel::~Channel() {}

Channel & Channel::operator=( Channel const & rhs ) {
    if (this != &rhs) {
        this->_name = rhs._name;
        this->_topic = rhs._topic;
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

void Channel::removeClient(int fd) {
    _clients.erase(fd);
    _operators.erase(fd); // On le retire aussi des OPs s'il l'était
}

void Channel::broadcast(const std::string &msg, Client* exclude) {
    std::string packet = msg + "\r\n";
    std::map<int, Client*>::iterator it;

    for (it = this->_clients.begin(); it != this->_clients.end(); ++it) {
        if (exclude && it->second == exclude)
            continue ;
        send(it->first, packet.c_str(), packet.size(), 0);
    }
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
    return list;
}

bool Channel::isOperator( int fd ) const {
    return (this->_operators.find(fd) != this->_operators.end());
}

std::string Channel::getName() const {
	return (this->_name);
}

std::string	Channel::getTopic( void ) const {
    return (this->_topic);
}

void		Channel::setTopic( const std::string & newTopic ) {
    this->_topic = newTopic;
}

size_t Channel::getSize() const {
	return (this->_clients.size());
}