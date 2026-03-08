/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 19:10:15 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/03/08 10:55:03 by paul_mallet      ###   ########.fr       */
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
		std::string 		_topicSetter;
        time_t      		_topicTime;
		bool                _topicProt;
		bool                _inviteOnly;
		std::string         _key;
		size_t              _limit;
		std::vector<int>    _invitedFds;

		std::map<int, Client*> _clients;
		std::map<int, Client*> _operators;

	public:
		Channel( void );
		Channel( std::string name );
		Channel( Channel const & other );
		~Channel();

		Channel & operator=( Channel const & rhs );

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

		void 		addInvite( int fd );
		void		removeInvite( int fd );
		bool 		isInvited( int fd ) const;

		std::string getModesString( void ) const;

		void addClient( Client* client );
		void removeClient( int fd );
		bool isClientInChannel( int fd ) const;

        void addOperator( int fd );
        void removeOperator( int fd );
        bool isOperator( int fd ) const;

        void broadcast( const std::string &msg, Client* exclude = NULL );

        std::string	getNicknamesList( void ) const;
        size_t		getSize( void ) const;

};

#endif