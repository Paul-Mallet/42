/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:01:57 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/20 18:47:47 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed( void ): _raw(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed( int const value ) {
	// std::cout << "Int constructor called\n";
	this->_raw = value * (1 << this->_fracb);
}

Fixed::Fixed( float const value ) {
	// std::cout << "Float constructor called\n";
	this->_raw = roundf(value * (1 << this->_fracb));
}

Fixed::Fixed( Fixed const &src ) {
	// std::cout << "Copy constructor called\n";
	// std::cout << "Copy assignment operator called\n";
	if (this != &src)
		this->_raw = src._raw;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

/*
	assignment operator
*/
Fixed &Fixed::operator=( Fixed const &rhs ) {
	// std::cout << "Copy assignment operator called\n";
	if (this != &rhs)
		this->_raw = rhs._raw;
	return *this;
}

/*
	comparison operators
*/
bool Fixed::operator>( Fixed const &rhs ) const {
	bool greater;

	// std::cout << "Greater than comparison operator called\n";
	if (this->_raw > rhs._raw)
		greater = true;
	else
		greater = false;
	return greater;
}

bool Fixed::operator<( Fixed const &rhs ) const {
	bool less;

	// std::cout << "Greater than comparison operator called\n";
	if (this->_raw < rhs._raw)
		less = true;
	else
		less = false;
	return less;
}

bool Fixed::operator>=( Fixed const &rhs ) const {
	bool gOrEq;

	// std::cout << "Greater than comparison operator called\n";
	if (this->_raw >= rhs._raw)
		gOrEq = true;
	else
		gOrEq = false;
	return gOrEq;
}

bool Fixed::operator<=( Fixed const &rhs ) const {
	bool lOrEq;

	// std::cout << "Greater than comparison operator called\n";
	if (this->_raw <= rhs._raw)
		lOrEq = true;
	else
		lOrEq = false;
	return lOrEq;
}

bool Fixed::operator==( Fixed const &rhs ) const {
	bool equal;

	// std::cout << "Equal to comparison operator called\n";
	if (this->_raw == rhs._raw)
		equal = true;
	else
		equal = false;
	return equal;
}

bool Fixed::operator!=( Fixed const &rhs ) const {
	bool notEqual;

	// std::cout << "Not equal to comparison operator called\n";
	if (this->_raw != rhs._raw)
		notEqual = true;
	else
		notEqual = false;
	return notEqual;
}

/*
	algorithmic operator
*/
Fixed Fixed::operator+( Fixed const &rhs ) const {
	Fixed addition;

	// std::cout << "Addition arithmetic operator called\n";
	addition.setRawBits(this->_raw + rhs._raw);
	return addition;
}

Fixed Fixed::operator-( Fixed const &rhs ) const {
	Fixed substract;

	// std::cout << "Substraction arithmetic operator called\n";
	substract.setRawBits(this->_raw - rhs._raw);
	return substract;
}

Fixed Fixed::operator*( Fixed const &rhs ) const {
	Fixed multi;

	std::cout << "Multiplication arithmetic operator called\n";
	multi.setRawBits((this->_raw * rhs._raw) >> this->_fracb);
	return multi;
}

Fixed Fixed::operator/( Fixed const &rhs ) const {
	Fixed division;

	// std::cout << "Division arithmetic operator called\n";
	division.setRawBits((this->_raw << this->_fracb) / rhs._raw);
	return division;
}

/*
	pre-increment operator
*/
Fixed &Fixed::operator++( void ) {
	++(this->_raw);
	return *this;
}

/*
	post-increment operator
*/
Fixed Fixed::operator++( int ) {
	Fixed res = *this;

	++(this->_raw);
	return res;
}

Fixed &Fixed::operator--( void ) {
	--(this->_raw);
	return *this;
}

Fixed Fixed::operator--( int ) {
	Fixed res = *this;

	--(this->_raw);
	return res;
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

Fixed &Fixed::min( Fixed &raw1, Fixed &raw2 ) {
	if (raw1 < raw2)
		return raw1;
	return raw2;
}

Fixed const &Fixed::min( Fixed const &raw1, Fixed const &raw2 ) {
	if (raw1 < raw2)
		return raw1;
	return raw2;
}

Fixed &Fixed::max( Fixed &raw1, Fixed &raw2 ) {
	if (raw1 > raw2)
		return raw1;
	return raw2;
}

Fixed const &Fixed::max( Fixed const &raw1, Fixed const &raw2 ) {
	if (raw1 > raw2)
		return raw1;
	return raw2;
}

std::ostream &operator<<( std::ostream &o, Fixed const &i ) {
	o << i.toFloat();
	return o;
}

const int Fixed::_fracb = 8;
