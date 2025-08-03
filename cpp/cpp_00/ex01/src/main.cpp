/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:41:36 by pamallet          #+#    #+#             */
/*   Updated: 2025/08/03 12:35:19 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void Contact::add() {
	cout << "First name: ";
	cin >> infos[0];
	cout << "Last name: ";
	cin >> infos[1];
	cout << "Nickname: ";
	cin >> infos[2];
	cout << "Phone number: ";
	cin >> infos[3];
	cout << "Darkest secret: ";
	cin >> infos[4];
	cout << endl;
	if (!infos[0].empty() && !infos[1].empty()
		&& !infos[2].empty() && !infos[3].empty()
		&& !infos[4].empty())
		cout << "Contact saved." << endl;
	else
		cout << "Empty field(s) not allowed. Contact not saved." << endl;
}

void Contact::display() {
	cout << "First name: " << infos[0] << endl;
	cout << "Last name: " << infos[1] << endl;
	cout << "Nickname: " << infos[2] << endl;
	cout << "Phone number: " << infos[3] << endl;
	cout << "Darkest secret: " << infos[4] << endl;
}

void PhoneBook::addContact() {
	contacts[addedContact % 8].add();
	if (maxContact < 8)
		maxContact++;
	addedContact++;
	cout << maxContact << endl;
	cout << addedContact << endl;
}

void PhoneBook::search() {
	int	i;
	int	j;

	i = -1;
	cout << "|-----------------PHONEBOOK-----------------|" << endl;
	cout << "|INDEX     |FIRSTNAME |LASTNAME  |NICKNAME  |" << endl;
	while (++i < maxContact)
	{
		j = -1;
		cout << "|" << left << setw(10) << i << "|";
		while (++j < 3)
		{
			cout << left << setw(9) << contacts[i].infos[j].substr(0, 9);
			if (contacts[i].infos[j].length() > 9)
				cout << ".";
			else
				cout << " ";
			cout << "|";
		}
		cout << endl;
	}
	cout << "|-------------------------------------------|" << endl;
	if (maxContact != 0)
		searchIndex();
}

void PhoneBook::searchIndex() {
	int i;

	cin >> i;
	if (!contacts[i].infos[0].empty())
		contacts[i].display();
	else
		cerr << "Index not found in the Phonebook." << endl;
};

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
