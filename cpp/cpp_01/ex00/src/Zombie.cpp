/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:10:15 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/16 11:51:14 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie( void ) {
	std::cout << "A zombie spawned." << std::endl;
}

Zombie::Zombie( std::string name ) : _name(name) {
	std::cout << "Zombie " << this->_name << " spawned." << std::endl;
}

Zombie::~Zombie( void ) {
	std::cout << this->_name << " killed" << std::endl;
}

void Zombie::setName(std::string name) {
	this->_name = name;
	std::cout << this->_name << " has been named." << std::endl;
}

std::string const Zombie::getName( void ) {
	return this->_name;
}

void Zombie::announce( void ) {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
