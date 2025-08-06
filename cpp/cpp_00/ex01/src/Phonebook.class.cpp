/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 22:33:57 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/06 17:44:40 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"

PhoneBook::PhoneBook( void ): addedContact(0), maxContact(0) {
	std::cout << "Phonebook successfully created." << std::endl;
};

PhoneBook::~PhoneBook( void ) {
	std::cout << "Phonebook successfully destroyed." << std::endl;
};

void PhoneBook::addContact( void ) {
	Contact contact;

	contact = contacts[addedContact % BOOK_CAPACITY];
	contact.addContact();

	if (contact.getFirstname().empty() || contact.getLastname().empty()
		|| contact.getNickname().empty() || contact.getPhonenum().empty()
		|| contact.getDarksecret().empty())
		std::cout << "Contact not saved." << std::endl;
	else
	{
		std::cout << "Contact saved." << std::endl;
		if (maxContact < BOOK_CAPACITY)
			maxContact++;
		addedContact++;
	}
}

void PhoneBook::searchContact( void ) const {
	int	i;

	i = -1;
	std::cout << "|-----------------PHONEBOOK-----------------|" << std::endl;
	std::cout << "|INDEX     |FIRSTNAME |LASTNAME  |NICKNAME  |" << std::endl;
	while (++i < maxContact)
	{
		std::cout << "|" << std::left << std::setw(10) << i << "|";
		contacts[i].displayContactStatus();
		std::cout << std::endl;
	}
	std::cout << "|-------------------------------------------|" << std::endl;

	if (maxContact == 0)
		std::cout << "The Phonebook is empty. Please ADD a contact." << std::endl;
	else
		searchContactIndex();
}

void PhoneBook::searchContactIndex( void ) const {
	std::string input;
	int i;

	while (std::getline(std::cin, input))
	{
		i = input[0] - '0';
		if (input == "EXIT")
			break ;
		if (!isdigit(input[0]))
			std::cout << "Invalid input. Please enter a digit available in the phonebook." << std::endl;
		else
		{
			if (i < 0 || i >= maxContact)
				std::cout << "Index not found in the Phonebook." << std::endl;
			else
				contacts[i].displayContactInfos();
		}
	}
};
