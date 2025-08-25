/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:58:35 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/25 09:21:23 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog( void ) : Animal() {
	std::cout << "Default Dog constructor called\n";
	this->type = "Dog";
}

Dog::Dog( std::string type ) : Animal() {
	std::cout << "Default Dog parameterized constructor called\n";
	this->type = type;
}

Dog::Dog( Dog const &src ) : Animal() {
	std::cout << "Default Dog copy constructor called\n";
	if (this != &src)
		this->type = src.type;
}

Dog::~Dog() {
	std::cout << "Default Dog destructor called\n";
}

Dog &Dog::operator=( Dog const &rhs ) {
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

void Dog::makeSound( void ) const {
	std::cout << "Bark !!!\n";
}
