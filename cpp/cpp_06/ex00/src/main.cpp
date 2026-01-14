/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:04:30 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/14 11:46:36 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"
#include <iostream>
#include <typeinfo>

int	main( int ac, char **av )
{
	if (ac != 2) {
		std::cout << "Invalid parameters: \nex: ./converter 42" << std::endl;
		return (1);
	}

	int i = 1;
	float f = 1.0f;
	double d = 1.0;
	char t = 't';
	char* n = NULL;
	ScalarConverter* scalar = new ScalarConverter;
	ScalarConverterDerived* scalar_derived = new ScalarConverterDerived;
	ScalarConverter* scalar_dyn_base;
	ScalarConverterDerived* scalar_dyn_derived;

	std::cout << std::endl;

	scalar_dyn_derived = dynamic_cast<ScalarConverterDerived*> (scalar);
	if (scalar_dyn_derived == NULL || scalar_dyn_derived == 0)
		std::cout << "dynamic_cast failure from Base* to Derived*" << std::endl;
	else
		std::cout << "dynamic_cast success from Base* to Derived*" << std::endl;

	scalar_dyn_derived = dynamic_cast<ScalarConverterDerived*> (scalar_derived);
	if (scalar_dyn_derived == NULL || scalar_dyn_derived == 0)
		std::cout << "dynamic_cast failure from Base* to Derived*" << std::endl;
	else
		std::cout << "dynamic_cast success from Base* to Derived*" << std::endl;

	std::cout << std::endl;

	scalar_dyn_base = dynamic_cast<ScalarConverter*> (scalar_derived);
	if (scalar_dyn_base == NULL || scalar_dyn_base == 0)
		std::cout << "dynamic_cast failure from Derived* to Base*" << std::endl;
	else
		std::cout << "dynamic_cast success from Derived* to Base*" << std::endl;

	scalar_dyn_base = dynamic_cast<ScalarConverter*> (scalar);
	if (scalar_dyn_base == NULL || scalar_dyn_base == 0)
		std::cout << "dynamic_cast failure from Derived* to Base*" << std::endl;
	else
		std::cout << "dynamic_cast success from Derived* to Base*" << std::endl;

	std::cout << std::endl;

	std::cout << typeid(i).name() << std::endl;
	std::cout << typeid(f).name() << std::endl;
	std::cout << typeid(d).name() << std::endl;
	std::cout << typeid(t).name() << std::endl;
	std::cout << typeid(n).name() << std::endl;
	std::cout << typeid(scalar).name() << std::endl;

	scalar->convert(av[1]);

	std::cout << std::endl;

	delete scalar;
	delete scalar_derived;

	return (0);
}