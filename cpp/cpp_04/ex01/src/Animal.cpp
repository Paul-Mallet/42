/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:43:27 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/25 09:21:13 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : type("Fish") {
	std::cout << "Default Animal constructor called\n";
}

Animal::Animal( std::string type ) : type(type) {
	std::cout << "Default Animal parameterized constructor called\n";
}

Animal::Animal( Animal const &src ) {
	std::cout << "Default Animal copy constructor called\n";
	if (this != &src)
		this->type = src.type;
}

Animal::~Animal() {
	std::cout << "Default Animal destructor called\n";
}

Animal &Animal::operator=( Animal const &rhs ) {
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

std::string Animal::getType( void ) const {
	return this->type;
}

void Animal::makeSound( void ) const {
	std::cout << "Blop...\n";
}