/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 22:32:50 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/06 17:35:57 by pamallet         ###   ########.fr       */
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
	if (str.empty())
		std::cout << "Invalid firstname field: empty" << std::endl;
	else if (!isalphastr(str))
		std::cout << "Invalid firstname field: non alphabetic" << std::endl;
	else
		this->_firstname = str;
}

void Contact::setLastname( std::string str ) {
	if (str.empty())
		std::cout << "Invalid lastname field: empty" << std::endl;
	else if (!isalphastr(str))
		std::cout << "Invalid firstname field: non alphabetic" << std::endl;
	else
		this->_lastname = str;
}

void Contact::setNickname( std::string str ) {
	if (str.empty())
		std::cout << "Invalid nickname field: empty" << std::endl;
	else if (!isalphastr(str))
		std::cout << "Invalid firstname field: non alphabetic" << std::endl;
	else
		this->_nickname = str;
}

void Contact::setPhonenum( std::string str ) {
	if (str.empty())
		std::cout << "Invalid phone number field: empty" << std::endl;
	else if (!isdigitstr(str))
		std::cout << "Invalid firstname field: non digit" << std::endl;
	else
		this->_phonenumber = str;
}

// why empty? see how getline() really works #TODO
void Contact::setDarksecret( std::string str ) {
	if (str.empty())
		std::cout << "Invalid darkest secret field: empty" << std::endl;
	else
		this->_darksecret = str;
}

/*
	<string>
		std::getline(istream& is, string str): extract chars from is and stores them into str
			not precised delim = when encounter '\n'

*/
void Contact::addContact( void ) {
	std::string str;

	std::cout << "First name: ";
	std::getline(std::cin, str);
	setFirstname(str);

	std::cout << "Last name: ";
	std::getline(std::cin, str);
	setLastname(str);

	std::cout << "Nickname: ";
	std::getline(std::cin, str);
	setNickname(str);

	std::cout << "Phone number: ";
	std::getline(std::cin, str);
	setPhonenum(str);

	std::cout << "Darkest secret: ";
	std::getline(std::cin, str);
	setDarksecret(str);
	std::cout << std::endl;
}

void Contact::displayContactField( std::string Contact::*fieldPtr ) const {
	const std::string& field = this->*fieldPtr;

	std::cout << std::left << std::setw(9) << field.substr(0, 9);
	if (field.length() > 9)
		std::cout << ".";
	else
		std::cout << " ";
	std::cout << "|";
}

void Contact::displayContactStatus( void ) const {
	std::string Contact::*fields[3] = {
		&Contact::_firstname,
		&Contact::_lastname,
		&Contact::_nickname,
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
