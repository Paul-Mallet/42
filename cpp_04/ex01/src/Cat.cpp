/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:46:07 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/18 18:47:41 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat( void ) : Animal()
{
	const std::string ttype = ("Cat");

	std::cout << "Cat: Default Constructor" << std::endl;
	this->type = ttype;
}

Cat::Cat( std::string type ) : Animal()
{
	const std::string ttype = ("Cat");

	std::cout << "Cat: Parameterized Constructor" << std::endl;

	if (ttype.compare(type) == 0)
	{
		this->type = type;
	}
	else
	{
		std::cout << "Cat: Type is not a Cat" << std::endl;
		std::cout << "Cat: Cat Type set as default" << std::endl;
		this->type = ttype;
	}
}

Cat::Cat( Cat const &src ) : Animal()
{
	std::cout << "Cat: Copy Constructor" << std::endl;

	if (this != &src)
		this->type = src.type;
}

Cat::~Cat( void )
{
	std::cout << "Cat: Destructor" << std::endl;
}

Cat &Cat::operator=( Cat const &rhs )
{
	std::cout << "Cat: Copy Operator Assignment" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void Cat::makeSound( void ) const
{
	std::cout << "Cat->makeSound(): Miaou miaou !!!" << std::endl;
}