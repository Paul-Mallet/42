/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 19:10:15 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/28 22:36:14 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include <iostream>
# include <string>
# include <map>
# include <sys/socket.h>

class Client;

class Channel {

	private:
		std::string _name;
		std::string _topic;

		// Listes de pointeurs vers les Clients
		std::map<int, Client*> _clients;
		std::map<int, Client*> _operators;

	public:
		Channel( void );
		Channel( std::string name );
		Channel( Channel const & other );
		~Channel();

		Channel & operator=( Channel const & rhs );

		// getters/setters
		std::string	getName( void ) const;
        std::string	getTopic( void ) const;
        void		setTopic( const std::string & newTopic );

		// Gestion des membres(Clients)
		void addClient( Client* client );
		void removeClient( int fd );
		bool isClientInChannel( int fd ) const;

		// Gestion des privilèges
        void addOperator( int fd );
        void removeOperator( int fd );
        bool isOperator( int fd ) const;

	    // Communication
        void broadcast( const std::string &msg, Client* exclude = NULL );

        // Utilitaires pour les réponses IRC (ex: liste des noms pour RPL_NAMREPLY)
        std::string	getNicknamesList( void ) const;
        size_t		getSize( void ) const;

};

#endif