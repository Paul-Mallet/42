/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:05:01 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/02 16:14:10 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main( int ac, char **av )
{
	if (ac < 1 || ac > 2) {
		std::cout << "Invalid args number\nex: ./convert <\"-42.f\">" << std::endl;
		return (1);
	}

	if (ac == 2) {
		/**
		 * @brief All tests based on user argument done in tests/
		 */
		ScalarConverter::convert(av[1]);
		return (0);
	}
	/**
	 * @brief Pseudo Literals tests
	 */
	std::cout << "===== Pseudo Literals tests =====" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;
	ScalarConverter::convert("nanf");
	std::cout << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << std::endl;
	ScalarConverter::convert("-inff");
	std::cout << std::endl;

	/**
	 * @brief Standard type (scalar) tests
	 */
	std::cout << "===== Standard type (scalar) tests =====" << std::endl;
	ScalarConverter::convert("a");
	std::cout << std::endl;
	ScalarConverter::convert("42");
	std::cout << std::endl;
	ScalarConverter::convert("42.42f");
	std::cout << std::endl;
	ScalarConverter::convert("43.f");
	std::cout << std::endl;
	ScalarConverter::convert("-42.42");
	std::cout << std::endl;

	/**
	 * @brief Absurd arguments tests
	 */
	std::cout << "===== Absurd arguments tests =====" << std::endl;
	ScalarConverter::convert("2147483648");
	std::cout << std::endl;
	ScalarConverter::convert("31");
	std::cout << std::endl;
	ScalarConverter::convert("043.8");
	std::cout << std::endl;
	ScalarConverter::convert("42.42ff");
	std::cout << std::endl;
	ScalarConverter::convert("-+42");
	std::cout << std::endl;
	ScalarConverter::convert("abc42");
	std::cout << std::endl;

	return (0);
}