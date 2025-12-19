/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:42:29 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/19 18:15:05 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal()
{
	const std::string ttype = ("Dog");

	std::cout << "Dog: Default Constructor" << std::endl;
	this->_brain = new Brain();
	this->type = ttype;
}

Dog::Dog( std::string type ) : Animal()
{
	const std::string ttype = ("Dog");

	std::cout << "Dog: Parameterized Constructor" << std::endl;

	if (ttype.compare(type) == 0)
	{
		this->_brain = new Brain();
		this->type = type;
	}
	else
	{
		std::cout << "Dog: Type is not a Dog" << std::endl;
		std::cout << "Dog: Dog Type set as default" << std::endl;
		this->_brain = new Brain();
		this->type = ttype;
	}
}

Dog::Dog( Dog const &src ) : Animal()
{
	std::cout << "Dog: Copy Constructor" << std::endl;

	if (this != &src)
	{
		this->_brain = new Brain();
		*(this->_brain) = *(src._brain);
		this->type = src.type;
	}
}

Dog::~Dog( void )
{
	delete this->_brain;
	std::cout << "Dog: Destructor" << std::endl;
}

Dog &Dog::operator=( Dog const &rhs )
{
	std::cout << "Dog: Copy Operator Assignment" << std::endl;
	if (this != &rhs)
	{
		this->_brain = new Brain();
		*(this->_brain) = *(rhs._brain);
		// this->_brain = rhs._brain; //shallow copy
		this->type = rhs.type;
	}
	return (*this);
}

void Dog::makeSound( void ) const
{
	std::cout << "Dog->makeSound(): Bark bark !!!" << std::endl;
}