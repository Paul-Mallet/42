/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:30:20 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/27 13:03:26 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <typeinfo>
#include "../includes/Array.hpp"

int main( int ac, char** av )
{
	if (ac != 1)
		return (1);
	(void)av;

	Array<float>* arrf = NULL;
	try {
		Array<int>			arr(3);
		Array<std::string>	arrs(2);
		arrf = new Array<float>(2);

		// Test Array int
		arr[0] = 42;
		arr[1] = -33;
		arr[2] = 24;
		arr[2] = -24.1f;
		// arr[3] = 100;

		std::cout << std::endl;

		// Test Array String
		// arrs[-1] = "test";
		arrs[0] = "mama";
		arrs[1] = "momo";
		arrs[1] = 65;
		// arrs[2] = "test";

		std::cout << std::endl;

		(*arrf)[0] = 42.5f;
		(*arrf)[1] = -32.5f;
		// (*arrf)[0][2] = 55.5f;

		// arrf[1][0] = 4;
		// arrf[1][1] = 3.0;
		// arrf[1][2] = 'a';

		std::cout << std::endl;

		std::cout << "arr[0]: " << arr[0] << std::endl;
		std::cout << "arr[1]: " << arr[1] << std::endl;
		std::cout << "arr[2]: " << arr[2] << std::endl;
		// std::cout << "arr[3]: " << arr[3] << std::endl;

		std::cout << std::endl;

		std::cout << "arrs[0]: " << arrs[0] << std::endl;
		std::cout << "arrs[1]: " << arrs[1] << std::endl;
		// std::cout << "arrs[2]: " << arrs[2] << std::endl;

		std::cout << std::endl;

		std::cout << "arrf[0]: " << (*arrf)[0] << std::endl;
		std::cout << "arrf[1]: " << (*arrf)[1] << std::endl;
		// std::cout << "arrf[2]: " << (*arrf)[2] << std::endl;

		std::cout << std::endl;

		std::cout << "size i: " << arr.size() << std::endl;
		std::cout << "size s: " << arrs.size() << std::endl;
		std::cout << "size f: " << arrf->size() << std::endl;

		std::cout << std::endl;

		std::cout << typeid(arr).name() << std::endl;
		std::cout << typeid(arrs).name() << std::endl;
		std::cout << typeid(*arrf).name() << std::endl;
		std::cout << typeid((*arrf)[0]).name() << std::endl;
		std::cout << typeid((*arrf)[1]).name() << std::endl;

	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	if (arrf)
		delete arrf;

	return (0);
}