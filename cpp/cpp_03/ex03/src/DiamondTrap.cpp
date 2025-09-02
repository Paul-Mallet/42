/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 09:20:36 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/09/02 17:41:20 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) {
	std::cout << "Default inherited DiamondTrap constructor called\n";
	this->_name = "Diamonda";
	this->_hp = FragTrap::getHitPoint();
	this->_ep = ScavTrap::getEnergyPoint();
	this->_ad = FragTrap::getAttackDamage();
}

// diamond inheritance c++ -> learncpp.com
// direct assign attr: this->_hp = FragTrap::_hp;
// draw diamond inheritance VS 2ble single inheritance, then 1 join(U)
DiamondTrap::DiamondTrap( std::string const &name ) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) { //+ name(name)
	std::cout << "Parameterized inherited DiamondTrap constructor called\n";
	this->_name = name;
	this->_hp = FragTrap::getHitPoint();
	this->_ep = ScavTrap::getEnergyPoint();
	this->_ad = FragTrap::getAttackDamage();
}

DiamondTrap::DiamondTrap( DiamondTrap const &src ) : ClapTrap(src), ScavTrap(src), FragTrap(src) {
	std::cout << "Inherited DiamondTrap copy constructor called\n";
	if (this != &src)
	{
		this->_name = src._name;
		this->_hp = src._hp;
		this->_ep = src._ep;
		this->_ad = src._ad;
	}
}

DiamondTrap::~DiamondTrap() {
	std::cout << "Default inherited DiamondTrap destructor called\n";
}

DiamondTrap &DiamondTrap::operator=( DiamondTrap const &rhs ) {
	std::cout << "Inherited DiamondTrap copy assignment operator called\n";
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return *this;
}

void DiamondTrap::attack( const std::string& target ) {
	if (this->_ep == 0)
	{
		std::cout << "DiamondTrap " << this->_name << " has no energy to attack\n";
		return ;
	}
	else
		this->_ep--;
	std::cout << "DiamondTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_ad << " points of damage!\n";
}

void DiamondTrap::whoAmI( void ) {
    std::cout << "I am " << this->_name << " and my ClapTrap name is " 
    	<< ClapTrap::_name << std::endl;
}
