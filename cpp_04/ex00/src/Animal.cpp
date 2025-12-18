/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:49:52 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/18 17:55:10 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal( void ): type("Animal")
{
	std::cout << "Animal: Default Constructor" << std::endl;
}

Animal::Animal( std::string type )
{
	const std::string ttype ("Animal");

	std::cout << "Animal: Parameterized Constructor" << std::endl;
	if (ttype.compare(type) == 0)
		this->type = type;
	else
	{
		std::cout << "Animal: Type is not an Animal" << std::endl;
		std::cout << "Animal: Animal Type set as default" << std::endl;
		this->type = ttype;
	}
}

Animal::Animal( Animal const &src )
{
	std::cout << "Animal: Copy Contrustor" << std::endl;
	if (this != &src)
		this->type = src.type;
}

Animal::~Animal( void )
{
	std::cout << "Animal: Destructor" << std::endl;
}

Animal &Animal::operator=( Animal const &rhs )
{
	std::cout << "Animal: Copy Operator Assignment" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

std::string Animal::getType( void ) const
{
	std::cout << "Animal->type: " << this->type << std::endl;
	return (this->type);
}

void Animal::makeSound( void ) const
{
	std::cout << "Animal->makeSound(): Imperceptible Sound..." << std::endl;
}

std::ostream &operator<<( std::ostream &o, Animal const &i)
{
	return (o << i.getType());
}