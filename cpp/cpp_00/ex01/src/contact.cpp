/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 22:32:50 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/03 22:33:05 by paul_mallet      ###   ########.fr       */
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
