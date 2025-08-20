/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:43:15 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/20 12:05:11 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

int main( void )
{
	Fixed a( 20.5f );
	Fixed b( 22.5f );

	std::cout << a.toInt() + b.toInt() << std::endl;
	std::cout << a.toFloat() + b.toFloat() << std::endl;
	return 0;
}