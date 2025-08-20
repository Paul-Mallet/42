/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:43:15 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/20 18:48:41 by pamallet         ###   ########.fr       */
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
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c( Fixed( 5.05f ) / Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::max( a, c ) << std::endl;

	return 0;
}