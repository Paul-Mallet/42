/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:54:32 by pamallet          #+#    #+#             */
/*   Updated: 2025/08/16 12:11:38 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : _type(type) {
	std::cout << this->_type << " forged" << std::endl;
};

Weapon::~Weapon( void ) {
	std::cout << std::endl << this->_type << " disassembled" << std::endl << std::endl;
};

const std::string &Weapon::getType( void ) {
	if (!this->_type.empty())
		return this->_type;
	return "nothing"; //must be alloc to ref it...
};

void Weapon::setType( std::string newType ) {
	std::cout << std::endl << this->_type << " disassembled" << std::endl;
	this->_type = newType;
	std::cout << this->_type << " forged instead" << std::endl << std::endl;
};
