/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:35:03 by pamallet          #+#    #+#             */
/*   Updated: 2025/08/22 17:24:14 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap( std::string const &name ) : ClapTrap(name) {
	std::cout << "Parameterized inherited constructor called\n";
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
}

ScavTrap::~ScavTrap(){
	std::cout << "Default inherited destructor called\n";
}

// #TODO
void ScavTrap::attack( const std::string& target ) {
	if (this->_ep == 0)
	{
		std::cout << "ScavTrap " << this->_name << " has no energy to attack\n";
		return ;
	}
	else
		this->_ep--;

	std::cout << "ScavTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_ad << " points of damage!\n";
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name << " now in Gate keeper mode\n";
}
