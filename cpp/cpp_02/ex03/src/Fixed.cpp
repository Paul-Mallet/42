/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:01:57 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/21 11:38:59 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed( void ): _raw(0) {
	// std::cout << "Default constructor called\n";
}

Fixed::Fixed( int const value ) {
	this->_raw = value * (1 << this->_fracb);
}

Fixed::Fixed( float const value ) {
	this->_raw = roundf(value * (1 << this->_fracb));
}

Fixed::Fixed( Fixed const &src ) {
	if (this != &src)
		this->_raw = src._raw;
}

Fixed::~Fixed() {
	// std::cout << "Destructor called\n";
}

/*
	assignment operator
*/
Fixed &Fixed::operator=( Fixed const &rhs ) {
	if (this != &rhs)
		this->_raw = rhs._raw;
	return *this;
}

/*
	comparison operators
*/
bool Fixed::operator>( Fixed const &rhs ) const {
	bool greater;

	if (this->_raw > rhs._raw)
		greater = true;
	else
		greater = false;
	return greater;
}

bool Fixed::operator<( Fixed const &rhs ) const {
	bool less;

	if (this->_raw < rhs._raw)
		less = true;
	else
		less = false;
	return less;
}

bool Fixed::operator>=( Fixed const &rhs ) const {
	bool gOrEq;

	if (this->_raw >= rhs._raw)
		gOrEq = true;
	else
		gOrEq = false;
	return gOrEq;
}

bool Fixed::operator<=( Fixed const &rhs ) const {
	bool lOrEq;

	if (this->_raw <= rhs._raw)
		lOrEq = true;
	else
		lOrEq = false;
	return lOrEq;
}

bool Fixed::operator==( Fixed const &rhs ) const {
	bool equal;

	if (this->_raw == rhs._raw)
		equal = true;
	else
		equal = false;
	return equal;
}

bool Fixed::operator!=( Fixed const &rhs ) const {
	bool notEqual;

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

	addition.setRawBits(this->_raw + rhs._raw);
	return addition;
}

Fixed Fixed::operator-( Fixed const &rhs ) const {
	Fixed substract;

	substract.setRawBits(this->_raw - rhs._raw);
	return substract;
}

Fixed Fixed::operator*( Fixed const &rhs ) const {
	Fixed multi;

	multi.setRawBits((this->_raw * rhs._raw) >> this->_fracb);
	return multi;
}

Fixed Fixed::operator/( Fixed const &rhs ) const {
	Fixed division;

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

/*
	Binary Space Partitioning:
		know if a point is in a triangle area in euclidian space
		A PAB/ABC >= 0 + PBC/ABC >= 0 + PAC/ABC >= 0 === 1
		Triangle area: (base * height) / 2;
		area Shoelase: |( p[0] * (va[1] - vb[1])) + a[0] * (vp[1] - vb[1]) + b[0] * (p[1] - a[1]) )| / 2;
		*/
bool Fixed::BSP( Fixed p[2], Fixed va[2], Fixed vb[2], Fixed vc[2] ) {
	Fixed areaABC;
	Fixed areaPAB;
	Fixed areaPBC;
	Fixed areaPAC;

	areaABC = (va[0] * (vb[1] - vc[1]) + vb[0] * (vc[1] - va[1]) + vc[0] * (va[1] - vb[1]));
	if (areaABC < 0)
		areaABC = areaABC * Fixed(-1);
	areaPAB = (p[0] * (va[1] - vb[1]) + va[0] * (vb[1] - p[1]) + vb[0] * (p[1] - va[1]));
	if (areaPAB < 0)
		areaPAB = areaPAB * Fixed(-1);
	areaPBC = (p[0] * (vb[1] - vc[1]) + vb[0] * (vc[1] - p[1]) + vc[0] * (p[1] - vb[1]));
	if (areaPBC < 0)
		areaPBC = areaPBC * Fixed(-1);
	areaPAC = (p[0] * (va[1] - vc[1]) + va[0] * (vc[1] - p[1]) + vc[0] * (p[1] - va[1]));
	if (areaPAC < 0)
		areaPAC = areaPAC * Fixed(-1);

	return ((areaPAB >= 0 && areaPBC >= 0 && areaPAC >= 0) && (areaPAB + areaPBC + areaPAC == areaABC));
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
