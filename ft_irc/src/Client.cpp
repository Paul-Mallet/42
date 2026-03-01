/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 20:07:44 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/28 23:33:55 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

Client::Client(void) :
	_fd(-1),
	_nickname(""),
	_username(""),
	_hostname(""),
	_realname(""),
	_hasPassedPassword(false),
	_isRegistered(false),
    _shouldDisconnect(false),
	_buffer("") {}

Client::Client(int fd, std::string host) :
	_fd(fd),
	_nickname(""),
	_username(""),
	_hostname(host),
	_realname(""),
	_hasPassedPassword(false),
	_isRegistered(false),
    _shouldDisconnect(false),
	_buffer("") {}

Client::Client(Client const & src) {
    *this = src;
}

Client::~Client() {
    // Note : On ne ferme pas forcément le _fd ici si le serveur 
    // s'en occupe déjà, pour éviter des doubles close().
}

Client & Client::operator=(Client const & rhs) {
    if (this != &rhs) {
        this->_fd = rhs._fd;
        this->_nickname = rhs._nickname;
        this->_username = rhs._username;
        this->_hostname = rhs._hostname;
        this->_realname = rhs._realname;
        this->_hasPassedPassword = rhs._hasPassedPassword;
        this->_isRegistered = rhs._isRegistered;
        this->_shouldDisconnect = rhs._shouldDisconnect;
        this->_buffer = rhs._buffer;
    }
    return (*this);
}

int Client::getFd( void ) const {
	return (this->_fd);
}

std::string Client::getNickname( void ) const {
	return (this->_nickname);
}

std::string Client::getUsername( void ) const {
	return (this->_username);
}

std::string Client::getHostname( void ) const {
	return (this->_hostname);
}

std::string Client::getRealname( void ) const {
	return (this->_realname);
}

bool Client::getHasPassedPassword( void ) const {
	return (this->_hasPassedPassword);
}

bool Client::getIsRegistered( void ) const {
	return (this->_isRegistered);
}

bool Client::getShouldDisconnect() const {
	return (this->_shouldDisconnect);
}

void	Client::setNickname( const std::string & newNickname ) {
	this->_nickname = newNickname;
}

void	Client::setUsername( const std::string & newUsername ) {
	this->_username = newUsername;
}

void	Client::setRealname( const std::string & newRealname ) {
	this->_realname = newRealname;
}

void Client::setHasPassedPassword( bool valid ) {
    this->_hasPassedPassword = valid;
}

void Client::setIsRegistered( bool valid ) {
    this->_isRegistered = valid;
}

void Client::setShouldDisconnect(bool status) {
    this->_shouldDisconnect = status;
}

void Client::addRawData(const std::string& data) {
    std::string filteredData;
    // ctrl + D flush output buffer, low bandwidth" ou une "partial data" : le serveur reçoit des petits morceaux de texte sans \n
    for (size_t i = 0; i < data.size(); ++i) {
        // On ne garde que les caractères imprimables OU le retour à la ligne
        if (data[i] >= 32 || data[i] == '\n' || data[i] == '\r') {
            filteredData += data[i];
        }
    }
    if (this->_buffer.size() + filteredData.size() > 512)
        throw (StuckBufferException());
    this->_buffer += filteredData;
}

std::string Client::getNextCommand() {
    size_t pos = this->_buffer.find("\n");

    if (pos == std::string::npos)
        return (""); // Pas encore de message complet, concat to _buffer until find "\n"

    // Extraction de la ligne jusqu'au \n
    std::string cmd = this->_buffer.substr(0, pos);
    // Nettoyage du \r (IRC utilise \r\n, mais certains clients envoient juste \n)
    if (!cmd.empty() && cmd[cmd.size() - 1] == '\r')
        cmd.erase(cmd.size() - 1);

    // On supprime la cmde traitée du buffer (incluant le \n)
    this->_buffer.erase(0, pos + 1);
    return (cmd);
}