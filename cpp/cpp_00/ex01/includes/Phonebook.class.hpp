/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:10:40 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/06 15:26:31 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <ctype.h>
# include "Contact.class.hpp"

/*
	private specifier(auto scope)
	encapsulation with privacy
	inline class member(method)
	class Name {...} phonebook; = Name phonebook;
*/
class PhoneBook {
	private:
		Contact contacts[8];
		int addedContact; //better as static? NO! cause only 1 instance of phonebook needed
		int maxContact;

	public:
		PhoneBook( void );
		~PhoneBook( void );

		void addContact( void );
		void searchContact( void ) const;
		void searchContactIndex( void ) const;
};

bool isalphastr( std::string str );
bool isdigitstr( std::string str );

#endif