/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:10:40 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/01 14:35:50 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

/*
	RESOLUTION STRATEGY
	1. Phonebook
	- contacts[8]
	- if 9th -> [0], 10th -> [1] = inf loop
	- "ADD" -> 
	- "SEARCH" -> display 4 cols first, then cin() for index
		- index displays -> 1 info / line(5), without truncation
	- "EXIT" -> delete[] ?, exit main cin() loop
	2. Contact
	- firstname, lastname, nickname, phonenum, secret
		- + index after created(auto add, reset [0] to [7])
	- none by default(constructor), but need 5 declarations in Contact
	- at program run, create PhoneBook, but 0 Contact
		- "ADD" = create 1 contact
	- if user CTRL + C to stop before end of contact
		- (= empty fields(1 of 5 string))
		- not added to contacts[8]
	QUESTIONS
	1. if I set myself with cin() class vars values they need to be public?
	2. private functions means cannot call them outside?
*/

/*
	ADD -> Contact(cin / string) -> fill Contact -> add to PhoneBook
*/
// class Contact {
// 	string infos[5];
// 	string firstname;
// 	string lastname;
// 	string nickname;
// 	string phonenumber;
// 	string darkestsecret;
// 	public:
// 		//function members
// };

/*
	private specifier(auto scope)
	encapsulation with privacy
	inline class member(method)
	class Name {...} phonebook; = Name phonebook;
*/
// class PhoneBook {
// 	private:
// 		Contact contacts[8];
// 	public:
// 		void add(contacts) {
// 			//...
// 		};
// 		void search(string) {
// 			//...
// 		};
// 		void exit(PhoneBook[8] phonebook) {
// 			//...
// 			//delete[] phonebook;
// 		};
// };

#endif