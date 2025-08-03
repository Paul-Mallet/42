/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 22:33:57 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/03 22:45:09 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void PhoneBook::addContact() {
	contacts[addedContact % 8].add();
	if (maxContact < 8)
		maxContact++;
	addedContact++;
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
	string input;
	int i;

	cin >> input;
	if (input.length() == 1 && input[0] >= '0' && input[0] <= '9')
	{
		i = input[0] - '0';
		if (i >= 0 && i <= maxContact 
            && !contacts[i].infos[0].empty())
		contacts[i].display();
		else
			cout << "Index not found in the Phonebook." << endl;
	}
	else
		cout << "Invalid input. Please enter a single digit." << endl;
};
