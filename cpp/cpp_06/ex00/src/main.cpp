/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:04:30 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/12 11:50:34 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/ScalarConverter.hpp"
#include <iostream>
#include <typeinfo>

int	main( int ac, char **av )
{
	if (ac != 1)
		return (1);
	(void)av;

	int i = 1;
	float f = 1.0f;
	double d = 1.0;
	char t = 't';
	char* n = NULL;
	// ScalarConverter* scalar = new ScalarConverter;

	std::cout << typeid(i).name() << std::endl;
	std::cout << typeid(f).name() << std::endl;
	std::cout << typeid(d).name() << std::endl;
	std::cout << typeid(t).name() << std::endl;
	std::cout << typeid(n).name() << std::endl;
	// std::cout << typeid(scalar).name() << std::endl;

	return (0);
}