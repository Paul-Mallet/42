/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 23:58:22 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/03 14:08:00 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main( void ) {
	// ===== Init variables =====
	int arr[3] = { 1, 2, 3 };
	std::vector<int>::iterator it;
	std::vector<int> v(arr, (arr + sizeof(arr) / sizeof(int)));

	// ===== Sizeof array & vector =====
	std::cout << "Sizeof array & vector" << std::endl;
	std::cout << "sizeof(int): " << sizeof(int) << std::endl;
	std::cout << "sizeof(arr): " << sizeof(arr) << "\n" << std::endl;

	// ===== Size & capacity vector =====
	std::cout << "Size & capacity vector" << std::endl;
	std::cout << "sizeof(v): " << sizeof(v) << std::endl;
	std::cout << "v.size(): " << v.size() << std::endl;
	std::cout << "v.capacity(): " << v.capacity() << "\n" << std::endl;

	// ===== easyfind template with correct value tests =====
	std::cout << "easyfind with correct value tests" << std::endl;
	it = ::easyfind(v, 3);
	std::cout << "*it: " << *it << "\n" << std::endl;

	// ===== easyfind template after pushing_back values tests =====
	std::cout << "easyfind template after pushing_back values tests" << std::endl;
	v.push_back(5);
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;
	it = ::easyfind(v, 5);
	std::cout << "*it: " << *it << "\n" << std::endl;

	// ===== easyfind with out of bound value tests =====
	std::cout << "easyfind with out of bound value tests" << std::endl;
	it = ::easyfind(v, 6);
	std::cout << *it << std::endl;
	std::cout << "*it: " << *it << std::endl;

	return (0);
}