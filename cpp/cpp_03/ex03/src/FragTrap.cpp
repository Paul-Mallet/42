/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:52:40 by pamallet          #+#    #+#             */
/*   Updated: 2025/08/24 11:20:03 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap() {
	std::cout << "Default inherited FragTrap constructor called\n";
	this->_name = "Fraga";
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
}

FragTrap::FragTrap( std::string const &name ) : ClapTrap(name) {
	std::cout << "Parameterized inherited FragTrap constructor called\n";
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
}

/*
	need base class constructor in copy constructor init list
	With virtual inheritance, the compiler needs explicit instruction
	on how to initialize the virtual base class (ClapTrap)
*/
FragTrap::FragTrap( FragTrap const &src ) : ClapTrap(src) {
	std::cout << "Inherited FragTrap copy constructor called\n";
	if (this != &src)
	{
		this->_name = src._name;
		this->_hp = src._hp;
		this->_ep = src._ep;
		this->_ad = src._ad;
	}
}

FragTrap::~FragTrap(){
	std::cout << "Default inherited FragTrap destructor called\n";
}

FragTrap &FragTrap::operator=( FragTrap const &rhs ) {
	std::cout << "Inherited FragTrap copy assignment operator called\n";
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return *this;
}

// Not ask for attack() msg modif
void FragTrap::highFivesGuys( void ) {
	std::cout << "FragTrap " << this->_name << " requests a positive high five!\n";
}
