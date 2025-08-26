/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 09:04:26 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/26 09:09:29 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int main( void )
{
	const int size = 10;
	Animal *animals[size];

	for (int i = 0; i < (size / 2); ++i)
		animals[i] = new Dog();
	for (int i = (size / 2); i < size; ++i)
		animals[i] = new Cat();

	std::cout << std::endl;
	Dog dog1;
	Dog dog2( dog1 );
	std::cout << std::endl;

	for (int i = 0; i < size; ++i)
		delete animals[i];

	return 0;
}
