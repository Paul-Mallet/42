/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:10:40 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/19 19:10:19 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <ctype.h>
# include <climits>
# include "Contact.hpp"

# define BOOK_CAPACITY 8

/*
	private specifier(auto scope)
	encapsulation with privacy
	inline class member(method)
	class Name {...} phonebook; = Name phonebook;
*/
class PhoneBook {

	public:
		PhoneBook( void );
		~PhoneBook( void );

		void addContact( void );
		void searchContact( void ) const;
		void searchContactIndex( void ) const;

	private:
		Contact _contacts[8];
		int _addedContact;
		int _maxContact;

};

bool isalphastr( std::string str );
bool isdigitstr( std::string str );

#endif