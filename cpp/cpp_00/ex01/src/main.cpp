/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:41:36 by pamallet          #+#    #+#             */
/*   Updated: 2025/08/03 23:16:41 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

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
Norm:
	extern classes, 1 class / file.cpp/.hpp -> phonebook.hpp + phonebook.cpp + main.cpp
*/
int	main(void)
{
	PhoneBook	phonebook;
	Contact		contact;
	string		input;

	cout << "Welcome to your PhoneBook !" << endl;
	while (input != "EXIT")
	{
		cin >> input;
		if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.search();
	}
	return (0);
}
