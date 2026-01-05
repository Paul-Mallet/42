/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:49:52 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/22 10:50:39 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"
#include "../includes/Cat.hpp"

AAnimal::AAnimal( void ): type("AAnimal")
{
	std::cout << "AAnimal: Default Constructor" << std::endl;
}

AAnimal::AAnimal( std::string type )
{
	const std::string ttype ("AAnimal");

	std::cout << "AAnimal: Parameterized Constructor" << std::endl;
	if (ttype.compare(type) == 0)
		this->type = type;
	else
	{
		std::cout << "AAnimal: Type is not an AAnimal" << std::endl;
		std::cout << "AAnimal: AAnimal Type set as default" << std::endl;
		this->type = ttype;
	}
}

AAnimal::AAnimal( AAnimal const &src )
{
	std::cout << "AAnimal: Copy Contrustor" << std::endl;
	if (this != &src)
		this->type = src.type;
}

AAnimal::~AAnimal( void )
{
	std::cout << "AAnimal: Destructor" << std::endl;
}

AAnimal &AAnimal::operator=( AAnimal const &rhs )
{
	std::cout << "AAnimal: Copy Operator Assignment" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

std::string const AAnimal::getType( void ) const
{
	return (this->type);
}

void AAnimal::makeSound( void ) const
{
	std::cout << "AAnimal->makeSound(): Imperceptible Sound..." << std::endl;
}

std::ostream &operator<<( std::ostream &o, AAnimal const &i)
{
	return (o << i.getType());
}