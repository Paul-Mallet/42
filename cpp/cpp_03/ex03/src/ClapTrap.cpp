/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:03:38 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/09/03 15:58:46 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("Clapa"), _hp(10), _ep(10), _ad(0) {
	std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap( std::string const &name ) : _name(name), _hp(10), _ep(10), _ad(0) {
	std::cout << "ClapTrap parameterized constructor called\n";
}

ClapTrap::ClapTrap( ClapTrap const &src ) {
	std::cout << "Claptrap copy constructor called\n";
	if (this != &src)
	{
		this->_name = src._name;
		this->_hp = src._hp;
		this->_ep = src._ep;
		this->_ad = src._ad;
	}
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called\n";
}

ClapTrap &ClapTrap::operator=( ClapTrap const &rhs ) {
	std::cout << "Copy assignment operator called\n";
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return *this;
}

std::string ClapTrap::getName( void ) const {
	return this->_name;
}

unsigned int ClapTrap::getHitPoint( void ) const {
	return this->_hp;
}

unsigned int ClapTrap::getEnergyPoint( void ) const {
	return this->_ep;
}

unsigned int ClapTrap::getAttackDamage( void ) const {
	return this->_ad;
}

void ClapTrap::attack( const std::string &target ) {
	if (this->_ep == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy to attack\n";
		return ;
	}
	else
		this->_ep--;

	std::cout << "ClapTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_ad << " points of damage!\n";
}

void ClapTrap::takeDamage( unsigned int amount ) {
	if (amount < this->_hp)
	{
		this->_hp -= amount;
		std::cout << "ClapTrap " << this->_name << " took "
			<< amount << " damage\n";
	}
	else
	{
		this->_hp = 0;
		std::cout << "ClapTrap " << this->_name << " took "
			<< amount << " damage\n";
		std::cout << "ClapTrap " << this->_name << " is KO\n";
	}
}

void ClapTrap::beRepaired( unsigned int amount ) {
	if (this->_ep == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy to repair itself\n";
		return ;
	}
	else
		this->_ep--;

	if ((this->_hp + amount) <= 10)
	{
		this->_hp += amount;
		std::cout << "ClapTrap " << this->_name << " healed of "
			<< amount << " hp\n";
	}
	else
		std::cout << "ClapTrap " << this->_name << " is full hp\n";
}

std::ostream &operator<<( std::ostream &o, ClapTrap const &i ) {
	o << i.getName();
	return o;
}
