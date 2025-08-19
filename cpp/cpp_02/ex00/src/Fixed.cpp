/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:07:21 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/19 11:41:51 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed( void ) {
	std::cout << "Default constructor called.\n";
}

Fixed::Fixed( int fp ) : _fp(0) {
	std::cout << "Parameterized constructor called.\n";
}

Fixed::Fixed( Fixed const &src ) {
	std::cout << "Copy constructor called.\n";
}

Fixed::~Fixed() {
	std::cout << "Destructor called.\n";
}

Fixed &Fixed::operator=( Fixed const &rhs ) {
	std::cout << "Assignement operator called.\n";
	if (this != &rhs)
		this->_fp = rhs.getRawBits(); //assign private attr with getter
	return *this;
}

int Fixed::getRawBits( void ) const {
	//...
}

void Fixed::setRawBits( int const raw ) {
	//...
}

std::ostream &operator<<( std::ostream &o, Fixed const &i ) {
	o << "The value of raw bits is: " << i.getRawBits() << std::endl;
}