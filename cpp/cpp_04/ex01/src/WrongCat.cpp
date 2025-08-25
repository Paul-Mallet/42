/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:58:35 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/25 09:21:32 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal() {
	std::cout << "Default WrongCat constructor called\n";
	this->type = "Cat";
}

WrongCat::WrongCat( std::string type ) : WrongAnimal() {
	std::cout << "Default WrongCat parameterized constructor called\n";
	this->type = type;
}

WrongCat::WrongCat( WrongCat const &src ) : WrongAnimal() {
	std::cout << "Default WrongCat copy constructor called\n";
	if (this != &src)
		this->type = src.type;
}

WrongCat::~WrongCat() {
	std::cout << "Default WrongCat destructor called\n";
}

WrongCat &WrongCat::operator=( WrongCat const &rhs ) {
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

void WrongCat::makeSound( void ) const {
	std::cout << "Miaou !\n";
}
