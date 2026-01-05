/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:46:07 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/22 11:12:34 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat( void ) : AAnimal("Cat")
{
	const std::string ttype = ("Cat");

	std::cout << "Cat: Default Constructor" << std::endl;
	this->_brain = new Brain();
	this->type = ttype;
}

Cat::Cat( std::string type ) : AAnimal(type)
{
	const std::string ttype = ("Cat");

	std::cout << "Cat: Parameterized Constructor" << std::endl;

	this->_brain = new Brain();
	if (ttype.compare(type) == 0)
		this->type = type;
	else
	{
		std::cout << "Cat: Type is not a Cat" << std::endl;
		std::cout << "Cat: Cat Type set as default" << std::endl;
		this->type = ttype;
	}
}

Cat::Cat( Cat const &src ) : AAnimal(src.type)
{
	std::cout << "Cat: Copy Constructor" << std::endl;

	this->_brain = new Brain();
	*(this->_brain) = *(src._brain);
	this->type = src.type;
}

Cat::~Cat( void )
{
	delete (this->_brain);
	std::cout << "Cat: Destructor" << std::endl;
}

Cat &Cat::operator=( Cat const &rhs )
{
	std::cout << "Cat: Copy Operator Assignment" << std::endl;
	if (this != &rhs)
	{
		delete this->_brain;
		this->_brain = new Brain();
		*(this->_brain) = *(rhs._brain);
		this->type = rhs.type;
	}
	return (*this);
}

AAnimal* Cat::clone( void ) {
	return (new Cat(*this));
}

std::string const Cat::getIdea( unsigned int i ) {
	if (i >= MAX_IDEAS || this->_brain->ideas[i].empty())
		return ("");
	return (this->_brain->ideas[i]);
}

void Cat::setIdea( std::string idea, unsigned int i ) {
	if (i >= MAX_IDEAS)
	{
		std::cout << "This idea is too far away for this " << this->getType() << std::endl;
		return ;
	}
	this->_brain->ideas[i] = idea;
}

void Cat::makeSound( void ) const
{
	std::cout << "Cat->makeSound(): Miaou miaou !!!" << std::endl;
}