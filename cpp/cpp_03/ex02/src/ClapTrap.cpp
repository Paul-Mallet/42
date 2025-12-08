/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:03:38 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/08 23:05:47 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("Clapa"), _hp(10), _ep(10), _ad(0), _hp_max(10), _ep_max(10) {
	std::cout << "Default ClapTrap constructor called\n";
}

ClapTrap::ClapTrap( std::string const &name ) : _name(name), _hp(10), _ep(10), _ad(0), _hp_max(10), _ep_max(10) {
	std::cout << "Parameterized ClapTrap constructor called\n";
}

ClapTrap::ClapTrap( ClapTrap const &src ) {
	std::cout << "Copy ClapTrap constructor called\n";
	if (this != &src)
	{
		this->_name = src._name;
		this->_hp = src._hp_max;
		this->_ep = src._ep_max;
		this->_ad = src._ad;
	}
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor ClapTrap called\n";
}

ClapTrap &ClapTrap::operator=( ClapTrap const &rhs ) {
	std::cout << "Copy assignment ClapTrap operator called\n";
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
	if (this->_hp == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is KO and can't attack\n";
		return ;
	}
	else
		this->_ep--;

	std::cout << "ClapTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_ad << " points of damage!\n";
}

void ClapTrap::takeDamage( unsigned int amount ) {
	int	max = 1000000;
	int	min = 0;
	int	amnt = (int)amount;
	if (amnt > max)
	{
		std::cout << "Damage too high, max amount capped\n";
		this->_hp = 0;
		std::cout << "ClapTrap " << this->_name << " took " << max << " damage\n";
		std::cout << "ClapTrap " << this->_name << " is KO\n";
		return ;
	}
	if (amnt < min)
	{
		std::cout << "Damage too low, min amount capped\n";
		std::cout << "ClapTrap " << this->_name << " took " << min << " damage\n";
		return ;
	}
	if ((unsigned int)amnt < this->_hp)
	{
		this->_hp -= amnt;
		std::cout << "ClapTrap " << this->_name << " took " << amnt << " damage\n";
	}
	else
	{
		this->_hp = 0;
		std::cout << "ClapTrap " << this->_name << " took " << amnt << " damage\n";
		std::cout << "ClapTrap " << this->_name << " is KO\n";
	}
}

void ClapTrap::beRepaired( unsigned int amount ) {
	if (this->_ep == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy to repair itself\n";
		return ;
	}
	if (this->_hp == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is KO and can't repair itself\n";
		return ;
	}
	else
		this->_ep--;
	if (this->_hp == this->_hp_max)
	{
		std::cout << "ClapTrap " << this->_name << " is already full hp\n";
		return;
	}
	this->_hp += amount;
	std::cout << "ClapTrap " << this->_name << " healed of " << amount << " hp\n";
	if (this->_hp > this->_hp_max)
		this->_hp = this->_hp_max;
}

std::ostream &operator<<( std::ostream &o, ClapTrap const &i ) {
	o << i.getName();
	return o;
}
