/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:41:36 by pamallet          #+#    #+#             */
/*   Updated: 2025/08/07 14:47:51 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"

/*
<iostream>: stream() object
	std::cin -> input stream, "ADD", "SEARCH" & "EXIT", rest is ignored
	std::cout -> output...
	std::endl -> new line(independent from curr OS)
	std::eof -> end of file input check
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

	std::cout << "Welcome to the PhoneBook !" << std::endl;
	std::cout << std::endl << "Type ADD, SEARCH or EXIT" << std::endl;
	while (std::getline(std::cin, input))
	{
		if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.searchContact();
		else if (input == "EXIT")
			break ;
		if (!std::cin.eof())
			std::cout << std::endl << "Type ADD, SEARCH or EXIT" << std::endl;
	}
	return (0);
}
