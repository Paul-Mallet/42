/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:52:40 by pamallet          #+#    #+#             */
/*   Updated: 2025/12/08 23:11:08 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap() {
	std::cout << "FragTrap default constructor called\n";
	this->_name = "Scava";
	this->_hp = ClapTrap::_hp * 10;
	this->_ep = ClapTrap::_ep * 10;
	this->_ad = ClapTrap::_ad + 30;
}

FragTrap::FragTrap( std::string const &name ) : ClapTrap(name) {
	std::cout << "FragTrap parameterized constructor called\n";
	this->_hp = ClapTrap::_hp * 10;
	this->_ep = ClapTrap::_ep * 10;
	this->_ad = ClapTrap::_ad + 30;
}

FragTrap::FragTrap( FragTrap const &src ) : ClapTrap() {
	std::cout << "FragTrap copy constructor called\n";
	if (this != &src)
	{
		this->_name = src._name;
		this->_hp = src._hp_max;
		this->_ep = src._ep_max;
		this->_ad = src._ad;
	}
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap destructor called\n";
}

FragTrap &FragTrap::operator=( FragTrap const &rhs ) {
	std::cout << "FragTrap copy assignment operator called\n";
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return *this;
}

void FragTrap::highFivesGuys( void ) {
	std::cout << "FragTrap " << this->_name << " requests a positive high five!\n";
}
