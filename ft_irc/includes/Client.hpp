/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 19:06:48 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/28 18:26:47 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <string>

class Server; 
class Channel;

class Client {

	private:
		int         _fd;
		std::string _nickname;
		std::string _username;
		std::string _hostname;
		std::string _realname;
		bool		_hasPassedPassword;
		bool        _isRegistered; // A passé PASS, NICK et USER
		std::string _buffer;

	public:
		Client( void );
		Client( int fd, std::string host );
		Client( Client const & src );
		~Client();

		Client & operator=(Client const & rhs);

		// Getters / Setters
		int			getFd( void ) const;
		std::string getNickname( void ) const;
		std::string getUsername( void ) const;
		std::string getHostname( void ) const;
		std::string getRealname( void ) const;
		bool		getIsRegistered( void ) const;
		bool		getHasPassedPassword( void ) const;
		void		setNickname( const std::string & newNickname );
		void		setUsername( const std::string & newUsername );
		void		setRealname( const std::string & newRealname );
		void 		setIsRegistered( bool valid );
		void 		setHasPassedPassword( bool valid );

		// Ajoute les octets reçus au buffer
		void		addRawData(const std::string& data);
		// Extrait et renvoie la prochaine commande complète (finit par \n)
        // Renvoie une chaîne vide si aucune commande n'est complète
		std::string	getNextCommand();

};

class StuckBufferException: public std::exception {
	virtual const char * what( void ) const throw() {
		return ("Client buffer exceeded maximum safety limit.");
	};
};

#endif