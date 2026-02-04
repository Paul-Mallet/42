/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:40:27 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/04 12:02:37 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main( void ) {
	// Span storage of capacity 2
	Span sp1(3);

	std::cout << "\n===== Shortest span exception =====" << std::endl;
	try {
		std::cout << sp1.shortestSpan() << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== Longest span exception =====" << std::endl;
	try {
		std::cout << sp1.longestSpan() << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== Fill span =====" << std::endl;
	std::cout << "addNumber(4)" << std::endl;
	sp1.addNumber(4);
	std::cout << "addNumber(11)" << std::endl;
	sp1.addNumber(11);
	std::cout << "addNumber(23)" << std::endl;
	sp1.addNumber(23);

	std::cout << "\n===== Full span exception =====" << std::endl;
	std::cout << "addNumber(23)" << std::endl;
	try {
		sp1.addNumber(42);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===== Span size compared to capacity Span _n =====" << std::endl;
	std::cout << sp1.getStorage().size() << std::endl;
	std::cout << sp1.getCapacity() << std::endl;

	std::cout << "\n===== Shortest span =====" << std::endl;
	std::cout << sp1.shortestSpan() << std::endl;

	std::cout << "\n===== Longest span =====" << std::endl;
	std::cout << sp1.longestSpan() << std::endl;

	return (0);
}