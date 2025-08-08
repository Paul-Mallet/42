/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 22:33:57 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/08 15:58:37 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"

PhoneBook::PhoneBook( void ): _addedContact(0), _maxContact(0) {
	std::cout << "Phonebook successfully created." << std::endl;
};

PhoneBook::~PhoneBook( void ) {
	std::cout << "Phonebook successfully destroyed." << std::endl;
};

void PhoneBook::addContact( void ) {
	Contact &contact = _contacts[_addedContact % BOOK_CAPACITY];

	contact.addContact();
	if (contact.getFirstname().empty() || contact.getLastname().empty()
		|| contact.getNickname().empty() || contact.getPhonenum().empty()
		|| contact.getDarksecret().empty())
		std::cout << "Contact not saved." << std::endl;
	else
	{
		std::cout << "Contact saved." << std::endl;
		if (_maxContact < BOOK_CAPACITY)
			_maxContact++;
		_addedContact++;
	}
}

void PhoneBook::searchContact( void ) const {
	int	i;

	i = -1;
	std::cout << std::endl << "|-----------------PHONEBOOK-----------------|" << std::endl;
	std::cout << "|INDEX     |FIRSTNAME |LASTNAME  |NICKNAME  |" << std::endl;
	while (++i < _maxContact)
	{
		std::cout << "|" << std::left << std::setw(10) << i << "|";
		_contacts[i].displayContactStatus();
		std::cout << std::endl;
	}
	std::cout << "|-------------------------------------------|" << std::endl;

	if (_maxContact == 0)
		std::cout << "The Phonebook is empty. Please ADD a contact." << std::endl << std::endl;
	else
		searchContactIndex();
}

void PhoneBook::searchContactIndex( void ) const {
	int i;
	std::string input;

	std::cout << std::endl << "Type an INDEX or EXIT: " << std::endl;
	while (1)
	{
		std::getline(std::cin, input);
		if (std::cin.eof())
			break ;
		if (std::cin.bad())
			break ;
		i = input[0] - '0';
		if (input == "EXIT")
			break ;
		if (!isdigit(input[0]))
			std::cout << "Invalid input. Please enter an INDEX available in the phonebook." << std::endl;
		if (std::cin.fail())
			std::cout << "Invalid input. Please enter an INDEX available in the phonebook." << std::endl;
		else
		{
			if (i < 0 || i >= _maxContact || input.length() > 1)
				std::cout << "INDEX not found in the Phonebook." << std::endl;
			else
				_contacts[i].displayContactInfos();
		}
		std::cout << std::endl << "Type an INDEX or EXIT: " << std::endl;
	}
};
