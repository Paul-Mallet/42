/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 23:58:22 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/03 19:37:43 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main( void ) {
	// ===== Init variables =====
	int value;
	int arr[] = { 1, 2, 3 };
	std::vector<int> v(arr, (arr + sizeof(arr) / sizeof(int)));

	// ===== Sizeof array & vector =====
	std::cout << "===== Sizeof array & vector =====" << std::endl;
	std::cout << "sizeof(int): " << sizeof(int) << std::endl;
	std::cout << "sizeof(arr): " << sizeof(arr) << "\n" << std::endl;

	// ===== Size & capacity vector =====
	std::cout << "===== Size & capacity vector =====" << std::endl;
	std::cout << "sizeof(v): " << sizeof(v) << std::endl;
	std::cout << "v.size(): " << v.size() << std::endl;
	std::cout << "v.capacity(): " << v.capacity() << "\n" << std::endl;

	// ===== easyfind template with correct value tests =====
	std::cout << "===== Function template with correct value tests =====" << std::endl;
	value = ::easyfind(v, 3);
	std::cout << "value: " << value << "\n" << std::endl;

	// ===== easyfind template after pushing_back values tests =====
	std::cout << "===== Function template after pushing_back values tests =====" << std::endl;
	v.push_back(5);
	std::cout << "v.size(): " << v.size() << std::endl;
	std::cout << "v.capacity(): " << v.capacity() << std::endl;
	value = ::easyfind(v, 5);
	std::cout << "value: " << value << "\n" << std::endl;

	// ===== easyfind with out of bound value tests =====
	try {
		std::cout << "===== Function template with out of bound value tests =====" << std::endl;
		value = ::easyfind(v, 6);
		std::cout << value << std::endl;
		std::cout << "value: " << value << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}