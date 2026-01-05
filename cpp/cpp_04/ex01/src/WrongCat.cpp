/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:46:07 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/18 19:06:35 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal()
{
	const std::string ttype = ("WrongCat");

	std::cout << "WrongCat: Default Constructor" << std::endl;
	this->type = ttype;
}

WrongCat::WrongCat( std::string type ) : WrongAnimal()
{
	const std::string ttype = ("WrongCat");

	std::cout << "WrongCat: Parameterized Constructor" << std::endl;

	if (ttype.compare(type) == 0)
	{
		this->type = type;
	}
	else
	{
		std::cout << "WrongCat: Type is not a WrongCat" << std::endl;
		std::cout << "WrongCat: WrongCat Type set as default" << std::endl;
		this->type = ttype;
	}
}

WrongCat::WrongCat( WrongCat const &src ) : WrongAnimal()
{
	std::cout << "WrongCat: Copy Constructor" << std::endl;

	if (this != &src)
		this->type = src.type;
}

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat: Destructor" << std::endl;
}

WrongCat &WrongCat::operator=( WrongCat const &rhs )
{
	std::cout << "WrongCat: Copy Operator Assignment" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void WrongCat::makeSound( void ) const
{
	std::cout << "WrongCat->makeSound(): Miaou miaou !!!" << std::endl;
}