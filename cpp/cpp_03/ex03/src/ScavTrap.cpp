/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:35:03 by pamallet          #+#    #+#             */
/*   Updated: 2025/08/24 11:18:44 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap() {
	std::cout << "Default inherited SvacTrap constructor called\n";
	this->_name = "Scava";
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
}

ScavTrap::ScavTrap( std::string const &name ) : ClapTrap(name) {
	std::cout << "Parameterized inherited SvacTrap constructor called\n";
	this->_name = name;
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
}

ScavTrap::ScavTrap( ScavTrap const &src ) : ClapTrap(src) {
	std::cout << "Inherited SvacTrap copy constructor called\n";
	if (this != &src)
	{
		this->_name = src._name;
		this->_hp = src._hp;
		this->_ep = src._ep;
		this->_ad = src._ad;
	}
}

ScavTrap::~ScavTrap(){
	std::cout << "Default inherited ScavTrap destructor called\n";
}

ScavTrap &ScavTrap::operator=( ScavTrap const &rhs ) {
	std::cout << "Inherited ScavTrap copy assignment operator called\n";
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return *this;
}

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
