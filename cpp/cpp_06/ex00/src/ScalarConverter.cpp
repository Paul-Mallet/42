/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:48:04 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/14 11:41:51 by paul_mallet      ###   ########.fr       */
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
	// cannot throw here, will stop other prints !
	(void)literal;

	// authorized headers which handle numeric limits and special values

	// 1. detect type of the literal
	// ex: 42.0f = float, 42 = int, 42.0 = double, 'a' = char
	// if contains no digits + '.', but can have 'f' = char
	// if contains no '.' + 'f' = int
	// if contains '.' + 'f' = float
	// if contains '.' only = double

	// 2. convert it to its actual type
	// if conversion does not make any sense or overflows, display "impossible"

	// 3. convert it explicitly to its 3 other types
	// if conversion does not make any sense or overflows, display "impossible"

	// 4. display results in correct order
	// float -> -inff, +inff, nanf
	// double -> -inf, +inf, nan
	std::cout << "char: " << std::endl;
	std::cout << "int: " << std::endl;
	std::cout << "float: " << std::endl;
	std::cout << "double: " << std::endl;
}

// see where to implement it, if possible
const char* ScalarConverter::NonDisplayableCharException::what( void ) const throw() {
	return ("Non displayable");
}

// test
ScalarConverterDerived::~ScalarConverterDerived() {
	std::cout << "Destructor - ScalarConverterDerived" << std::endl;
};