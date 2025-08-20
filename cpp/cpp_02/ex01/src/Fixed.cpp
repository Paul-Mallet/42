/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:01:57 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/20 14:38:27 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed( void ) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed( int const value ) {
	std::cout << "Int constructor called\n";
	this->_raw = value * (1 << this->_fracb);
}

Fixed::Fixed( float const value ) {
	std::cout << "Float constructor called\n";
	this->_raw = roundf(value * (1 << this->_fracb));
}

Fixed::Fixed( Fixed const &src ) {
	std::cout << "Copy constructor called\n";
	std::cout << "Copy assignment operator called\n";
	if (this != &src)
		this->_raw = src._raw;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

Fixed &Fixed::operator=( Fixed const &rhs ) {
	std::cout << "Copy assignment operator called\n";
	if (this != &rhs)
		this->_raw = rhs._raw;
	return *this;
}

int Fixed::getRawBits( void ) const {
	return this->_raw;
}

void Fixed::setRawBits( int const raw ) {
	this->_raw = raw;
}

int Fixed::toInt( void ) const {
	int i;

	i = this->_raw / (1 << this->_fracb);
	return i;
}

float Fixed::toFloat( void ) const {
	float f;

	f = (this->_raw * 1.0f) / (1 << this->_fracb);
	return f;
}

std::ostream &operator<<( std::ostream &o, Fixed const &i ) {
	o << i.toFloat();
	return o;
}

const int Fixed::_fracb = 8;
