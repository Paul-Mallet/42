/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:05:01 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/29 10:55:35 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main( int ac, char **av )
{
	if (ac != 2) {
		std::cout << "Invalid args number\nex: ./convert \"-42.f\"" << std::endl;
		return (1);
	}

	/**
	 * @brief All tests done in tests/
	 */
	ScalarConverter::convert(av[1]);

	return (0);
}