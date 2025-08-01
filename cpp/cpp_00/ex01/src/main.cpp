/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:41:36 by pamallet          #+#    #+#             */
/*   Updated: 2025/08/01 13:56:44 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

/*
|-----------------PHONEBOOK-----------------|
|INDEX     |FIRSTNAME |LASTNAME  |NICKNAME  |
|0         |paul      |mallet    |pamallet  |
|1         |jean-pier.|chateau   |pchateau  |
|-------------------------------------------|
to 8...
*/

/*
<iostream>: stream() object
	std::cin -> input stream, "ADD", "SEARCH" & "EXIT", rest is ignored
	std::cout -> output...
<string>: [TODO]
	std:: [TODO]
<iomanip>: format output(phonebook's table align columns)
	std::setw(10) << '.' -> output field width strict to 10 ex: "|" << "some info." << "|"
	std::[TODO]
access specifiers = access rights for instances
	private: owner class scope,
	protected: new instance + owner class scope,
	public: accessible anywhere it is visible
Rules:
	program run -> 3 cmds(ADD, SEARCH, EXIT)
*/
int	main(void)
{
	// Contact		contact;
	// PhoneBook	phonebook;
	string	str;

	cout << "Welcome to your PhoneBook !" << endl;
	while (str != "EXIT")
	{
		cin >> str;
		if (str == "ADD")
			cout << "test" << endl;
			// phonebook.add(str);
	}
	return (0);
}
