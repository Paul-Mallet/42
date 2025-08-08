/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:54:32 by pamallet          #+#    #+#             */
/*   Updated: 2025/08/08 11:38:43 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon ) : _name(name), _weapon(weapon) {
	std::cout << this->_name << " spawned and takes its " << this->_weapon.getType() << std::endl;
};

HumanA::~HumanA( void ) {
	std::cout << this->_name << " died and drops its " << this->_weapon.getType() << std::endl;
};

void HumanA::attack( void ) {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
};
