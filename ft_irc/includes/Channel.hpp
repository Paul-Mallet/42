/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 19:10:15 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/03/01 09:43:22 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <vector>
# include <map>
# include <sys/socket.h>
# include <ctime>

class Client;

class Channel {

	private:
		std::string 		_name;
		std::string 		_topic;
		std::string 		_topicSetter; // Nickname de celui qui l'a mis
        time_t      		_topicTime;   // Timestamp du changement
		bool                _topicProt;    // Mode +t
		bool                _inviteOnly;   // Mode +i
		std::string         _key;          // Mode +k (vide si pas de pass)
		size_t              _limit;        // Mode +l (0 si pas de limite)
		std::vector<int>    _invitedFds;   // Liste des FDs invités (pour +i)

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
		std::string getTopicSetter( void ) const;
        time_t		getTopicTime( void ) const;
		bool 		isInviteOnly( void ) const;
		bool 		hasTopicProt( void ) const;
		std::string getKey( void ) const;
		size_t		getLimit( void ) const;

		void 		setInviteOnly(bool v);
		void 		setTopicProt(bool v);
		void 		setKey(std::string k);
		void 		setLimit(size_t l);
		void		setTopic( const std::string & newTopic, const std::string & setter );

		// Gestion des invitations (pour le mode +i)
		void 		addInvite( int fd );
		void		removeInvite( int fd );
		bool 		isInvited( int fd ) const;

		// Méthode pour le numeric 324 (MODE #chan)
		std::string getModesString( void ) const;

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