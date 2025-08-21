/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:43:15 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/21 20:56:59 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

int main( void )
{
	Point p(0.3f, 0.3f);
	Point a(1.0f, 1.0f);
	Point b(2.0f, 1.0f);
	Point c(1.0f, 2.0f);

	std::cout << bsp( a, b, c, p ) << std::endl;

	return 0;
}
