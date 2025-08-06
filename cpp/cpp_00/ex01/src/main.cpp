/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:41:36 by pamallet          #+#    #+#             */
/*   Updated: 2025/08/06 14:57:52 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"

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
*/
int	main(void)
{
	PhoneBook	phonebook;
	std::string		input;

	std::cout << "Welcome to your PhoneBook !" << std::endl;
	while (input != "EXIT")
	{
		std::cin >> input;
		if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.searchContact();
	}
	return (0);
}
