/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:40:27 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/05 11:11:45 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

static void displaySpan( Span const & span ) {
	for(unsigned int i = 0; i < span.getStorage().size(); ++i) {
		std::cout << "span[" << i << "]: " << span.getStorage()[i] << std::endl;
	}
};

int main( void ) {
	// Span storage of capacity 2
	Span sp1(3);
	Span sp2(10001);
	Span sp3(10);
	Span sp4(5);

	// Tests with sp1
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
	std::cout << "addNumber(11)" << std::endl;
	sp1.addNumber(11);
	std::cout << "addNumber(23)" << std::endl;
	sp1.addNumber(23);
	std::cout << "addNumber(4)" << std::endl;
	sp1.addNumber(-4);
	displaySpan(sp1);

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

	// Tests with sp2
	std::cout << "addNumber(0) to (10000)" << std::endl;
	for (unsigned int i = 0; i < 10001; ++i)
		sp2.addNumber(i);
	std::cout << "sp2[0]: " << sp2.getStorage()[0] << std::endl;
	std::cout << "sp2[10000]: " << sp2.getStorage()[10000] << std::endl;

	// Tests with sp3
	std::cout << "\n===== Fill span with 10 element =====" << std::endl;
	std::cout << "insertNumbers(0, 0, 10);" << std::endl;
	try {
		int arr[] = { 14, 44, 0, -22, 55, 86, 73, 62, 3, 99 };
		sp3.insertNumbers(arr, arr + 10);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	displaySpan(sp3);

	std::cout << "\n===== Full span exception =====" << std::endl;
	std::cout << "insertNumbers(10, 0, 10);" << std::endl;
	try {
		int arr[] = { 56, 17, 0, 22, 55, -86, 73, 62, 3, 99 };
		sp3.insertNumbers(arr, arr + 10);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	// Tests with Istream and Input Iterators
	std::cout << "\n===== Fill span with 5 element =====" << std::endl;
	try {
		std::istringstream iss("10 20 30 40 50");
		std::istream_iterator<unsigned int> it(iss);
		std::istream_iterator<unsigned int> ite;
		sp4.insertNumbers(it, ite);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	displaySpan(sp4);

	return (0);
}