/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:54:32 by pamallet          #+#    #+#             */
/*   Updated: 2025/08/17 09:20:40 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name), _weapon(NULL) {
	std::cout << this->_name << " spawned" << std::endl;
}

HumanB::~HumanB( void ) {
	if (this->_weapon)
		std::cout << this->_name << " died and drops its " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " died and has no weapon" << std::endl;
}

void HumanB::setWeapon( Weapon &weapon ) {
	this->_weapon = &weapon;
	if (this->_weapon)
		std::cout << this->_name << " takes a " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " drops its weapon" << std::endl;
}

void HumanB::attack( void ) {
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " attacks with their hands" << std::endl;
}
