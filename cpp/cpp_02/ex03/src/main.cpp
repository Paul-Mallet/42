/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:43:15 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/21 16:59:02 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

int main( void )
{
	Point p(0.0f, 10.10f);
	Point a;
	Point b(10.10f, 0.0f);
	Point c(0.0f, 10.10f);

	std::cout << bsp( a, b, c, p ) << std::endl;

	return 0;
}
