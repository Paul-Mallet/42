/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:43:27 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/25 09:21:20 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type("Fish") {
	std::cout << "Default WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal( std::string type ) : type(type) {
	std::cout << "Default WrongAnimal parameterized constructor called\n";
}

WrongAnimal::WrongAnimal( WrongAnimal const &src ) {
	std::cout << "Default WrongAnimal copy constructor called\n";
	if (this != &src)
		this->type = src.type;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Default WrongAnimal destructor called\n";
}

WrongAnimal &WrongAnimal::operator=( WrongAnimal const &rhs ) {
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

std::string WrongAnimal::getType( void ) const {
	return this->type;
}

void WrongAnimal::makeSound( void ) const {
	std::cout << "Blop...\n";
}