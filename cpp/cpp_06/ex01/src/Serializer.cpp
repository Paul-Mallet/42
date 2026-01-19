/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:24:19 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/19 09:30:49 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

Serializer::Serializer( void ) {
	std::cout << "Default Constructor - Serializer" << std::endl;
}

Serializer::Serializer( Serializer const &src ) {
	std::cout << "Copy constructor - Serializer" << std::endl;
	(void)src;
}

Serializer::~Serializer() {
	std::cout << "Destructor - Serializer" << std::endl;
}

Serializer &Serializer::operator=( Serializer const &rhs ) {
	std::cout << "Copy Assignment Operator - Serializer" << std::endl;
	(void)rhs;
	return (*this);
}

uintptr_t Serializer::serialize( Data* ptr ) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize( uintptr_t raw ) {
	return (reinterpret_cast<Data*>(raw));
}