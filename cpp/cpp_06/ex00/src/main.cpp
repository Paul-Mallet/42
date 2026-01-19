/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:05:01 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/19 18:26:38 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"
# include <typeinfo>

int	main( int ac, char **av )
{
	if (ac != 2)
		return (1);

	// ScalarConverter scalar;
	// ScalarConverter* scal2 = new ScalarConverter;

	ScalarConverter::convert(av[1]);

	return (0);
}