/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:58:35 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/25 09:21:26 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat( void ) : Animal() {
	std::cout << "Default Cat constructor called\n";
	this->type = "Cat";
}

Cat::Cat( std::string type ) : Animal() {
	std::cout << "Default Cat parameterized constructor called\n";
	this->type = type;
}

Cat::Cat( Cat const &src ) : Animal() {
	std::cout << "Default Cat copy constructor called\n";
	if (this != &src)
		this->type = src.type;
}

Cat::~Cat() {
	std::cout << "Default Cat destructor called\n";
}

Cat &Cat::operator=( Cat const &rhs ) {
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

void Cat::makeSound( void ) const {
	std::cout << "Miaou !\n";
}
