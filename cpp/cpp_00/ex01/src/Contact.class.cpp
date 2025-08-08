/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 22:32:50 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/08 16:32:24 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"

Contact::Contact( void )
	: _firstname(""),
	  _lastname(""),
	  _nickname(""),
	  _phonenumber(""),
	  _darksecret("") {};

Contact::~Contact( void ) {};

std::string Contact::getFirstname( void ) const {
	return this->_firstname;
}

std::string Contact::getLastname( void ) const {
	return this->_lastname;
}

std::string Contact::getNickname( void ) const {
	return this->_nickname;
}

std::string Contact::getPhonenum( void ) const {
	return this->_phonenumber;
}

std::string Contact::getDarksecret( void ) const {
	return this->_darksecret;
}

void Contact::setFirstname( std::string str ) {
	while (1)
	{
		std::cout << "First name: ";
		std::getline(std::cin, str);
		if (std::cin.eof())
			break ;
		if (std::cin.fail())
			std::cout << "Invalid firstname field. Try again" << std::endl;
		if (std::cin.bad())
			break ;
		if (str.empty())
			std::cout << "Invalid firstname field: empty" << std::endl;
		else if (!isalphastr(str))
			std::cout << "Invalid firstname field: non alphabetic" << std::endl;
		else
		{
			this->_firstname = str;
			break ;
		}
	}
}

void Contact::setLastname( std::string str ) {
	while (1)
	{
		std::cout << "Last name: ";
		std::getline(std::cin, str);
		if (std::cin.eof())
			break ;
		if (std::cin.fail())
			std::cout << "Invalid lastname field. Try again" << std::endl;
		if (std::cin.bad())
			break ;
		if (str.empty())
			std::cout << "Invalid lastname field: empty" << std::endl;
		else if (!isalphastr(str))
			std::cout << "Invalid larstname field: non alphabetic" << std::endl;
		else
		{
			this->_lastname = str;
			break ;
		}
	}
}

void Contact::setNickname( std::string str ) {
	while (1)
	{
		std::cout << "Nickname: ";
		std::getline(std::cin, str);
		if (std::cin.eof())
			break ;
		if (std::cin.fail())
			std::cout << "Invalid nickname field. Try again" << std::endl;
		if (std::cin.bad())
			break ;
		if (str.empty())
			std::cout << "Invalid nickname field: empty" << std::endl;
		else if (!isalphastr(str))
			std::cout << "Invalid nickname field: non alphabetic" << std::endl;
		else
		{
			this->_nickname = str;
			break ;
		}
	}
}

void Contact::setPhonenum( std::string str ) {
	while (1)
	{
		std::cout << "Phone number: ";
		std::getline(std::cin, str);
		if (std::cin.eof())
			break ;
		if (std::cin.fail())
			std::cout << "Invalid phone number field. Try again" << std::endl;
		if (std::cin.bad())
		break ;
		if (str.empty())
			std::cout << "Invalid phone number field: empty" << std::endl;
		else if (!isdigitstr(str))
			std::cout << "Invalid phone number field: non digit" << std::endl;
		else
		{
			this->_phonenumber = str;
			break ;
		}
	}
}

void Contact::setDarksecret( std::string str ) {
	while (1)
	{
		std::cout << "Darkest secret: ";
		std::getline(std::cin, str);
		if (std::cin.eof())
			break ;
		if (std::cin.fail())
			std::cout << "Invalid darkest secret field. Try again" << std::endl;
		if (std::cin.bad())
		break ;
		if (str.empty())
			std::cout << "Invalid darkest secret field: empty" << std::endl;
		else
		{
			this->_darksecret = str;
			break ;
		}
	}
}

/*
	<string>
		std::getline(istream& is, string str): extract chars from is and stores them into str
			not precised delim = when encounter '\n'

*/
void Contact::addContact( void ) {
	std::string str;

	std::cout << std::endl << "Add a contact" << std::endl;
	setFirstname(str);
	if (this->_firstname.empty())
		return ;
	setLastname(str);
	if (this->_lastname.empty())
		return ;
	setNickname(str);
	if (this->_nickname.empty())
		return ;
	setPhonenum(str);
	if (this->_phonenumber.empty())
		return ;
	setDarksecret(str);
	std::cout << std::endl;
}

void Contact::displayContactField( std::string field ) const {
	std::cout << std::left << std::setw(9) << field.substr(0, 9);
	if (field.length() > 9)
		std::cout << ".";
	else
		std::cout << " ";
	std::cout << "|";
}

void Contact::displayContactStatus( void ) const {
	std::string fields[3] = {
		this->_firstname,
		this->_lastname,
		this->_nickname,
	};
	for (int i = 0; i < 3; ++i)
		displayContactField(fields[i]);
}

void Contact::displayContactInfos( void ) const {
	std::cout << "First name: " << this->_firstname << std::endl;
	std::cout << "Last name: " << this->_lastname << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phonenumber << std::endl;
	std::cout << "Darkest secret: " << this->_darksecret << std::endl;
}
