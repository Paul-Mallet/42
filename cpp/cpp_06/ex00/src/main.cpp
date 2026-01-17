/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:05:01 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/17 12:45:35 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int	main( int ac, char **av )
{
	if (ac != 1)
		return (1);
	(void)av;

	int i;
	float f = 42.0000001f;
	double d;

	i = f;
	std::cout << i << std::endl;

	d = f;
	std::cout << d << std::endl;
	d = static_cast<double> (f);
	std::cout << d << std::endl;

	return (0);
}