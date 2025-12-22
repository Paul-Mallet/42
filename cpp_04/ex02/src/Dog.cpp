/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:42:29 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/22 10:38:21 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog( void ) : AAnimal("Dog")
{
	const std::string ttype = ("Dog");

	std::cout << "Dog: Default Constructor" << std::endl;
	this->_brain = new Brain();
	this->type = ttype;
}

Dog::Dog( std::string type ) : AAnimal(type) //type?
{
	const std::string ttype = ("Dog");

	std::cout << "Dog: Parameterized Constructor" << std::endl;

	this->_brain = new Brain();
	if (ttype.compare(type) == 0)
		this->type = type;
	else
	{
		std::cout << "Dog: Type is not a Dog" << std::endl;
		std::cout << "Dog: Dog Type set as default" << std::endl;
		this->type = ttype;
	}
}

Dog::Dog( Dog const &src ) : AAnimal(src.type)
{
	std::cout << "Dog: Copy Constructor" << std::endl;

	this->_brain = new Brain();
	*(this->_brain) = *(src._brain);
	this->type = src.type;
}

Dog::~Dog( void )
{
	delete (this->_brain);
	std::cout << "Dog: Destructor" << std::endl;
}

Dog &Dog::operator=( Dog const &rhs )
{
	std::cout << "Dog: Copy Operator Assignment" << std::endl;
	if (this != &rhs)
	{
		delete this-> _brain;
		this->_brain = new Brain();
		*(this->_brain) = *(rhs._brain);
		this->type = rhs.type;
	}
	return (*this);
}

AAnimal* Dog::clone( void ) {
	return (new Dog(*this));
}

std::string const Dog::getIdea( unsigned int i ) {
	if (i >= MAX_IDEAS || this->_brain->ideas[i].empty())
		return ("");
	return (this->_brain->ideas[i]);
}

void Dog::setIdea( std::string idea, unsigned int i ) {
	if (i >= MAX_IDEAS)
		std::cout << "This idea is too far away for this " << this->getType() << std::endl;
	this->_brain->ideas[i] = idea;
}

void Dog::makeSound( void ) const
{
	std::cout << "Dog->makeSound(): Bark bark !!!" << std::endl;
}