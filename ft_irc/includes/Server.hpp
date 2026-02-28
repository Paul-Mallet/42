/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:53:16 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/28 22:46:59 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <exception>
# include <cstdlib>
# include <vector>
# include <map>
# include <cerrno>

# include <unistd.h> // close
# include <sys/socket.h> // socket, setsockopt, listen, accept, send, recv
# include <sys/types.h> // getaddrinfo, freeaddrinfo
# include <netdb.h>
# include <netinet/in.h> // sockaddr_in struct, inet_addr [avoid, use getaddrinfo instead]
# include <arpa/inet.h> // inet_ntop, ...
# include <signal.h> // signal, sig, ...
# include <sys/stat.h> // fstat
# include <fcntl.h>
# include <poll.h>

class Client; 
class Channel;

class Server {

	private:
		int			_port;
		std::string	_pwd;
		int 		_fd;

		std::vector<struct pollfd>		_pollFds;
		std::map<int, Client*>    		_clients;
		std::map<std::string, Channel*> _channels;

		void _processCommand( Client * client, std::string cmd );

		void _handlePass( Client * client, std::vector<std::string> args );
		void _handleNick( Client * client, std::vector<std::string> args );
		void _handleUser( Client * client, std::vector<std::string> args );
		void _handlePrivmsg( Client * client, std::vector<std::string> args );
		void _handleJoin(Client *client, std::vector<std::string> args);

		bool	_isValidNick( const std::string & nick );
		bool	_isNickTaken( const std::string & nick );
		std::vector<std::string> _splitMessage( std::string msg );
		void	_checkRegistration( Client * client );
		Client*	_findClientByNick( const std::string & nick );
		void	_handleChannelMsg( Client * client, std::string target, std::string msg );

	public:
		Server( void );
		Server( int port, std::string pwd );
		Server( Server const & other );
		~Server();

		Server & operator=( Server const & rhs );

		int		getFd( void ) const;
		void	setFd( int newFd );

		void	init( void );
		void	start( void );
		void	sendReply( int fd, const std::string & msg );

};

class SocketException: public std::exception {
	virtual const char * what( void ) const throw() {
		return ("Socket creation failed.");
	};
};

class SetSocketOptionException: public std::exception {
	virtual const char * what( void ) const throw() {
		return ("Set socket option failed.");
	};
};

class FcntlFailedException: public std::exception {
	virtual const char * what( void ) const throw() {
		return ("Set socket option failed.");
	};
};

class BindFailedException: public std::exception {
	virtual const char * what( void ) const throw() {
		return ("Bind failed.");
	};
};

class ListenFailedException: public std::exception {
	virtual const char * what( void ) const throw() {
		return ("Listen failed.");
	};
};

#endif