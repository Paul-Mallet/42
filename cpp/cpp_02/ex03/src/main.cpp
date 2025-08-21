/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:43:15 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/21 11:45:46 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

// int main( void )
// {
// 	Fixed a( 20.5f );
// 	Fixed b( 22.52f );
// 	std::cout << a.toInt() + b.toInt() << std::endl;
// 	std::cout << a.toFloat() + b.toFloat() << std::endl;
// 	std::cout << a.toFloat() - b.toFloat() << std::endl;
// 	std::cout << a.toFloat() * b.toFloat() << std::endl;
// 	std::cout << a.toFloat() / b.toFloat() << std::endl;
// 	if (a.toFloat() > b.toFloat())
// 		std::cout << "(>)a > b" << std::endl;
// 	else
// 		std::cout << "(>)a < b" << std::endl;
// 	if (a.toFloat() < b.toFloat())
// 		std::cout << "(<)a < b" << std::endl;
// 	else
// 		std::cout << "(<)a > b" << std::endl;
// 	if (a.toFloat() >= b.toFloat())
// 		std::cout << "(>=)a >= b" << std::endl;
// 	else
// 		std::cout << "(>=)a <= b" << std::endl;
// 	if (a.toFloat() <= b.toFloat())
// 		std::cout << "(<=)a <= b" << std::endl;
// 	else
// 		std::cout << "(<=)a >= b" << std::endl;
// 	if (a.toFloat() == b.toFloat())
// 		std::cout << "(==)a == b" << std::endl;
// 	else
// 		std::cout << "(==)a != b" << std::endl;
// 	if (a.toFloat() != b.toFloat())
// 		std::cout << "(!=)a != b" << std::endl;
// 	else
// 		std::cout << "(!=)a == b" << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << b-- << std::endl;
// 	std::cout << --b << std::endl;
// 	std::cout << std::endl;
// 	std::cout << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	std::cout << Fixed::min( a, b ) << std::endl;
// 	return 0;
// }
int main( void )
{
	Fixed p[2];
	Fixed a[2];
	Fixed b[2];
	Fixed c[2];

	p[0] = 1.1f;
	p[1] = 0.52f;
	a[0] = 0;
	a[1] = 0;
	b[0] = 1;
	b[1] = 2;
	c[0] = 2;
	c[1] = 1;

	std::cout << "p(" << p[0] << "; " << p[1] << ")" << std::endl;
	std::cout << "a(" << a[0] << "; " << a[1] << ")" << std::endl;
	std::cout << "b(" << b[0] << "; " << b[1] << ")" << std::endl;
	std::cout << "c(" << c[0] << "; " << c[1] << ")" << std::endl;

	std::cout << Fixed::BSP( p, a, b, c ) << std::endl;

	return 0;
}
