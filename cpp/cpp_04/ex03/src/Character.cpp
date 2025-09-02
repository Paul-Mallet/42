/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:29:02 by pamallet          #+#    #+#             */
/*   Updated: 2025/09/02 10:32:51 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character( void ) : _name("random") {
    std::cout << "Character default constructor called" << std::endl;
	for(int i = 0; i < 4; ++i)
		this->_slot[i] = NULL;
}

Character::Character( std::string const &name ) : _name(name) {
    std::cout << "Character parameterized constructor called" << std::endl;
	for(int i = 0; i < 4; ++i)
		this->_slot[i] = NULL;
}

Character::Character( Character const &src ) {
    std::cout << "Character copy constructor called" << std::endl;
	if (this != &src)
	{
		for(int i = 0; i < 4; ++i)
			this->_slot[i] = NULL;
		copyInventory(src);
	}
}

Character::~Character() {
    std::cout << "Character destructor called" << std::endl;
	clearInventory();
}

Character &Character::operator=(Character const &rhs ) {
	std::cout << "Character assignment operator called" << std::endl;
    if (this != &rhs)
    {
		this->_name = rhs._name;
		clearInventory();
		copyInventory(rhs);
	}
    return *this;
}

std::string const &Character::getName( void ) const {
	return this->_name;
}

void Character::equip( AMateria *m ) {
	if (!m)
	{
		std::cout << "Cannot equip a NULL materia\n";
		return ;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (this->_slot[i] == NULL)
		{
			this->_slot[i] = m;
			return ;
		}
	}
	std::cout << this->_name << " inventory's is full, cannot equip "
		<< m->getType() << std::endl;
}

void Character::unequip( int idx ) {
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid slot index, cannot unequip\n";
		return ;
	}
	if (!this->_slot[idx])
	{
		std::cout << "Already empty slot, cannot unequip non-existent materia\n";
		return ;
	}
	std::cout << _name << " unequipped "
		<< _slot[idx]->getType() << " from slot " << idx << std::endl;
    _slot[idx] = NULL;
}

void Character::use( int idx, ICharacter &target ) {
	if (idx < 0 || idx > 3)
	{
        std::cout << "Invalid slot index: " << idx << std::endl;
        return;
    }
	if (!this->_slot[idx])
	{
		std::cout << "Empty slot, cannot use non-existent materia\n";
		return ;
	}
	_slot[idx]->use(target);
}

void Character::clearInventory( void ) {
    for (int i = 0; i < 4; i++) {
        if (_slot[i] != NULL) {
            delete _slot[i];
            _slot[i] = NULL;
        }
    }
}

void Character::copyInventory( Character const &src ) {
	for (int i = 0; i < 4; i++) {
        if (src._slot[i] != NULL)
            _slot[i] = src._slot[i]->clone();
        else
            _slot[i] = NULL;
    }
}
