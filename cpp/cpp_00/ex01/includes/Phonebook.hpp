/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:10:40 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/03 23:17:23 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"
/* ???
You should be able to use each of your headers independently from others. Thus,
they must include all the dependencies they need. However, you must avoid the
problem of double inclusion by adding include guards. Otherwise, your grade will
be 0
*/

using std::cin;
using std::cout;
using std::setw;
using std::left;
using std::endl;

/*
	private specifier(auto scope)
	encapsulation with privacy
	inline class member(method)
	class Name {...} phonebook; = Name phonebook;
*/
class PhoneBook {
	private:
		Contact contacts[8];
		int addedContact;
		int maxContact;
	public:
		PhoneBook() : addedContact(0), maxContact(0) {};
		void addContact();
		void search();
		void searchIndex();
};

#endif