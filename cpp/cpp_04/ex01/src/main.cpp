/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:21:25 by pamallet          #+#    #+#             */
/*   Updated: 2026/01/07 11:08:00 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(int ac, char **av)
{
	if (!av || ac > 2)
	{
		std::cout << "Invalid input" << std::endl;
		std::cout << "ex: ./polymorphism \"Animal\"" << std::endl;
		return (1);
	}

	Animal* animals[6]; //not able to clone if const pointer !

	std::cout << std::endl;

	for (int i = 0; i < 3; i++)
		animals[i] = new Cat();
	for (int i = 3; i < 6; i++)
		animals[i] = new Dog();

	std::cout << std::endl;

	animals[2]->getType();
	animals[3]->getType();

	std::cout << std::endl;

	std::cout << animals[2]->getType() << std::endl;
	std::cout << animals[3]->getType() << std::endl;

	std::cout << std::endl;

	animals[2]->makeSound();
	animals[3]->makeSound();

	std::cout << std::endl;

	std::cout << animals[2]->getIdea(0) << std::endl;
	std::cout << animals[5]->getIdea(0) << std::endl;
	std::cout << animals[2]->getIdea(2) << std::endl;
	std::cout << animals[5]->getIdea(2) << std::endl;

	if (animals[2]->getIdea(2).empty())
		std::cout << std::endl << animals[2]->getType() << " has no idea..." << std::endl;

	std::cout << std::endl;

	animals[2]->setIdea("I want some kibbles !", 1);
	animals[5]->setIdea("I want some kibbles !", 1);
	animals[5]->setIdea("My gosh, I had poop on the floor !", 1);

	std::cout << std::endl;

	std::cout << animals[2]->getIdea(1) << std::endl;
	std::cout << animals[5]->getIdea(1) << std::endl;

	// delete (animals[0]);
	// animals[0] = animals[5];

	std::cout << std::endl;

	delete (animals[0]);
	animals[0] = animals[5]->clone();
	std::cout << animals[0]->getType() << std::endl;

	std::cout << std::endl;

	std::cout << animals[0]->getIdea(0);

	std::cout << std::endl;

	std::cout << animals[0]->getIdea(1);

	std::cout << std::endl;

	animals[0]->setIdea("Give me more biscuits !", 1);
	std::cout << animals[0]->getIdea(1);

	std::cout << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 6; i++)
		delete (animals[i]);
	return (0);
}