/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:10:40 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/01 13:56:17 by paul_mallet      ###   ########.fr       */
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