/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:07:21 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/19 18:38:23 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

/*
	fixed-point number:
		int -> accurate GOOD(5 === 5) / precision BAD(5/2 = 2)
		float -> looks like real number, not every fraction can be represented exactly in bin(1/3)
			 seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm    meaning
			31                              0    bit #
		fixed-point -> GOOD in both but not implemented in languages
			8.8 format (left = 8 for int, right = 8 for fractional part)
			10101111.01011111
			[int][fx-p][frac]
*/
Fixed::Fixed( void ) : _raw(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed( Fixed const &src ) {
	std::cout << "Copy constructor called\n";
	if (this != &src)
		this->_raw = src._raw;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

Fixed &Fixed::operator=( Fixed const &rhs ) {
	std::cout << "Copy assignment operator called\n";
	this->getRawBits();
	if (this != &rhs)
		this->_raw = rhs._raw;
	return *this;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called\n";
	if (this->_raw)
		std::cout << this->_raw;
	return this->_raw;
}

void Fixed::setRawBits( int const raw ) {
	this->_raw = raw;
}

// std::ostream &operator<<( std::ostream &o, Fixed const &i ) {
// 	return o << i; //?
// }