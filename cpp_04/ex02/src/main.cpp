/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:00:01 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/22 10:51:03 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

int	main(int ac, char **av)
{
	if (!av || ac > 2)
	{
		std::cout << "Invalid input" << std::endl;
		std::cout << "ex: ./abstract \"aanimals\"" << std::endl;
		return (1);
	}

	// AAnimals* aanimals = new AAnimals();
	AAnimal* aanimals[6];

	std::cout << std::endl;

	for (int i = 0; i < 3; i++)
		aanimals[i] = new Cat();
	for (int i = 3; i < 6; i++)
		aanimals[i] = new Dog();

	std::cout << std::endl;

	aanimals[2]->getType();
	aanimals[3]->getType();

	std::cout << std::endl;

	std::cout << aanimals[2]->getType() << std::endl;
	std::cout << aanimals[3]->getType() << std::endl;

	std::cout << std::endl;

	aanimals[2]->makeSound();
	aanimals[3]->makeSound();

	std::cout << std::endl;

	std::cout << aanimals[2]->getIdea(0) << std::endl;
	std::cout << aanimals[5]->getIdea(0) << std::endl;
	std::cout << aanimals[2]->getIdea(2) << std::endl;
	std::cout << aanimals[5]->getIdea(2) << std::endl;

	if (aanimals[2]->getIdea(2).empty())
		std::cout << std::endl << aanimals[2]->getType() << " has no idea..." << std::endl;

	std::cout << std::endl;

	aanimals[2]->setIdea("I want some kibbles !", 1);
	aanimals[5]->setIdea("I want some kibbles !", 1);
	aanimals[5]->setIdea("My gosh, I had poop on the floor !", 1);

	std::cout << std::endl;

	std::cout << aanimals[2]->getIdea(1) << std::endl;
	std::cout << aanimals[5]->getIdea(1) << std::endl;

	std::cout << std::endl;

	delete (aanimals[0]);
	aanimals[0] = aanimals[5]->clone();
	std::cout << aanimals[0]->getType() << std::endl;

	std::cout << std::endl;

	std::cout << aanimals[0]->getIdea(0);

	std::cout << std::endl;

	std::cout << aanimals[0]->getIdea(1);

	std::cout << std::endl;

	aanimals[0]->setIdea("Give me more biscuits !", 1);
	std::cout << aanimals[0]->getIdea(1);

	std::cout << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 6; i++)
		delete (aanimals[i]);
	return (0);
}