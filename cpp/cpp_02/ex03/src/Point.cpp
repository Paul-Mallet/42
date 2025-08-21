/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:58:00 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/21 12:09:55 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

Point::Point( void ) : _x(0), _y(0) {
	// std::cout << "Default constructor called\n";
}

Point::Point( float const x, float const y ) : _x(x), _y(y) {
	// std::cout << "Parameterized constructor called\n";
}

Point::Point( Point const &src) : _x(src._x), _y(src._y) {
	// std::cout << "Copy constructor called\n";
}

Point::~Point() {
	// std::cout << "Destructor called\n";
}

Point &Point::operator=( Point const &rhs ) {
	if (this != &rhs)
	{
		this->_x = rhs._x;
		this->_y = rhs._y;
	}
	return *this;
}

Fixed Point::getX( void ) const {
	return this->_x;
}

Fixed Point::getY( void ) const {
	return this->_y;
}