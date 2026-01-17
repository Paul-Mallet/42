/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 10:49:38 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/17 12:09:21 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ) {
	std::cout << "Default Constructor - ScalarConverter" << std::endl;
}

ScalarConverter::ScalarConverter( ScalarConverter const &src ) {
	std::cout << "Copy constructor - ScalarConverter" << std::endl;
	(void)src;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "Destructor - ScalarConverter" << std::endl;
}

ScalarConverter &ScalarConverter::operator=( ScalarConverter const &rhs ) {
	std::cout << "Copy Assignment Operator - ScalarConverter" << std::endl;
	(void)rhs;
	return (*this);
}

void ScalarConverter::convert( std::string literal ) {
	// void* type;

	// 1. detect literal type
	std::cout << typeid(literal).name() << std::endl;
	// type = typeid(literal).name();

	// 2. convert literal type to its actual detected
	// int i = static_cast<int> (literal);

	// 3. convert explicitly(4 operators) in 3 others

	// 4. display results in correct way
}

// std::ostream &operator<<( std::ostream &o, ScalarConverter &i ) {
// 	o << i.convert( "test" ) << std::endl; // convert() must not return void
// 	return (o);
// }