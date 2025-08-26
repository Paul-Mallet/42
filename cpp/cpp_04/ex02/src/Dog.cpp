/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:58:35 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/26 08:49:36 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog( void ) : Animal() {
	std::cout << "Default Dog constructor called\n";
	this->type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog( std::string type ) : Animal() {
	std::cout << "Default Dog parameterized constructor called\n";
	this->type = type;
	this->_brain = new Brain();
}

Dog::Dog( Dog const &src ) : Animal() {
	std::cout << "Default Dog copy constructor called\n";
	if (this != &src)
	{
		this->type = src.type;
		this->_brain = new Brain(*src._brain);
	}
}

Dog::~Dog() {
	std::cout << "Default Dog destructor called\n";
	delete this->_brain;
}

Dog &Dog::operator=( Dog const &rhs ) {
	if (this != &rhs)
	{
		this->type = rhs.type;
		delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
	}
	return *this;
}

void Dog::makeSound( void ) const {
	std::cout << "Bark !!!\n";
}
