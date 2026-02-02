/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:30:20 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/02 18:28:27 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <typeinfo>
#include "Array.hpp"

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

		std::cout << "===== Arrays Type =====" << std::endl;
		std::cout << typeid(arr).name() << std::endl;
		std::cout << typeid(arr[0]).name() << std::endl;
		std::cout << typeid(arr[1]).name() << std::endl;
		std::cout << typeid(arrs).name() << std::endl;
		std::cout << typeid(arrs[0]).name() << std::endl;
		std::cout << typeid(arrs[1]).name() << std::endl;
		std::cout << typeid(*arrf).name() << std::endl;
		std::cout << typeid((*arrf)[0]).name() << std::endl;
		std::cout << typeid((*arrf)[1]).name() << std::endl;
		std::cout << std::endl;

		std::cout << "===== Int Array =====" << std::endl;
		arr[0] = 42;
		arr[1] = -33;
		arr[2] = 24;
		std::cout << "arr[0]: " << arr[0] << std::endl;
		std::cout << "arr[1]: " << arr[1] << std::endl;
		std::cout << "arr[2]: " << arr[2] << std::endl;
		std::cout << std::endl;

		std::cout << "===== String Array =====" << std::endl;
		arrs[0] = "mama";
		arrs[1] = "momo";
		std::cout << "arrs[0]: " << arrs[0] << std::endl;
		std::cout << "arrs[1]: " << arrs[1] << std::endl;
		std::cout << std::endl;

		std::cout << "===== Float Array =====" << std::endl;
		(*arrf)[0] = 42.5f;
		(*arrf)[1] = -32.5f;
		std::cout << "arrf[0]: " << (*arrf)[0] << std::endl;
		std::cout << "arrf[1]: " << (*arrf)[1] << std::endl;
		std::cout << std::endl;

		std::cout << "===== Arrays Size =====" << std::endl;
		std::cout << "size i: " << arr.size() << std::endl;
		std::cout << "size s: " << arrs.size() << std::endl;
		std::cout << "size f: " << arrf->size() << std::endl;
		std::cout << std::endl;

		std::cout << "===== Arrays Invalid Access =====" << std::endl;
		std::cout << "arr[3]: " << arr[3] << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	if (arrf)
		delete arrf;

	return (0);
}