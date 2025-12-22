/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:49:52 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/18 19:05:47 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ): type("WrongAnimal")
{
	std::cout << "WrongAnimal: Default Constructor" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type )
{
	const std::string ttype ("WrongAnimal");

	std::cout << "WrongAnimal: Parameterized Constructor" << std::endl;
	if (ttype.compare(type) == 0)
		this->type = type;
	else
	{
		std::cout << "WrongAnimal: Type is not an WrongAnimal" << std::endl;
		std::cout << "WrongAnimal: WrongAnimal Type set as default" << std::endl;
		this->type = ttype;
	}
}

WrongAnimal::WrongAnimal( WrongAnimal const &src )
{
	std::cout << "WrongAnimal: Copy Contrustor" << std::endl;
	if (this != &src)
		this->type = src.type;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "WrongAnimal: Destructor" << std::endl;
}

WrongAnimal &WrongAnimal::operator=( WrongAnimal const &rhs )
{
	std::cout << "WrongAnimal: Copy Operator Assignment" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

std::string WrongAnimal::getType( void ) const
{
	std::cout << "WrongAnimal->type: " << this->type << std::endl;
	return (this->type);
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << "WrongAnimal->makeSound(): Imperceptible Sound..." << std::endl;
}

std::ostream &operator<<( std::ostream &o, WrongAnimal const &i)
{
	return (o << i.getType());
}