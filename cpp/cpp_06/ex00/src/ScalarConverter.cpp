/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:48:04 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/13 13:59:56 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ) {
	std::cout << "Default Constructor - ScalarConverter" << std::endl;
}

ScalarConverter::ScalarConverter( ScalarConverter const &src ) {
	std::cout << "Copy Constructor - ScalarConverter" << std::endl;
	(void)src;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "Destructor - ScalarConverter" << std::endl;
}

ScalarConverter &ScalarConverter::operator=( ScalarConverter const &rhs ) {
	std::cout << "Copy Assignment - ScalarConverter" << std::endl;
	(void)rhs;
	return (*this);
}

void ScalarConverter::convert( std::string literal ) {
	// static / dynamic cast vars?
	(void)literal;
	std::cout << "char: " << std::endl;
	std::cout << "int: " << std::endl;
	std::cout << "float: " << std::endl;
	std::cout << "double: " << std::endl;
}