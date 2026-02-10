/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:08:03 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/10 13:42:20 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main( int ac, char** av ) {

	if ( ac < 2 ) {
		std::cout << "Invalid arguments\nex1: ./PmergeMe 42 0 21 33 999"
				<< "\nex2: ./PmergeMe \"42 0 21 33 999\""
				<< "\nex3: ./PmergeMe ` shuf -i 1-100000 -n 3000 | tr \"\n\" " " `" << std::endl;
		return (1);
	}

	PmergeMe pmrg;
	try {
		pmrg.evaluate( ac, av );
	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}