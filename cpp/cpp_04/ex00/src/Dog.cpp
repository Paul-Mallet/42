/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:42:29 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/18 17:55:32 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal()
{
	const std::string ttype = ("Dog");

	std::cout << "Dog: Default Constructor" << std::endl;
	this->type = ttype;
}

Dog::Dog( std::string type ) : Animal()
{
	const std::string ttype = ("Dog");

	std::cout << "Dog: Parameterized Constructor" << std::endl;

	if (ttype.compare(type) == 0)
	{
		this->type = type;
	}
	else
	{
		std::cout << "Dog: Type is not a Dog" << std::endl;
		std::cout << "Dog: Dog Type set as default" << std::endl;
		this->type = ttype;
	}
}

Dog::Dog( Dog const &src ) : Animal()
{
	std::cout << "Dog: Copy Constructor" << std::endl;

	if (this != &src)
		this->type = src.type;
}

Dog::~Dog( void )
{
	std::cout << "Dog: Destructor" << std::endl;
}

Dog &Dog::operator=( Dog const &rhs )
{
	std::cout << "Dog: Copy Operator Assignment" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void Dog::makeSound( void ) const
{
	std::cout << "Dog->makeSound(): Bark bark !!!" << std::endl;
}