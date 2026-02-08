/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:39:12 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/08 07:35:00 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main( int ac, char** av ) {
	if (ac != 2) {
		std::cout << "Invalid arguments\nex: ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl;
		return (1);
	}

	/**
	 * @brief Calculate the parsed argument while applying the RPN.
	 */
	RPN rpn;
	try {
		std::string expression(av[1]);

		rpn.evaluate( expression );
	} catch (std::exception & e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return (0);
}