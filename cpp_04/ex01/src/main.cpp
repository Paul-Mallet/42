/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:21:25 by pamallet          #+#    #+#             */
/*   Updated: 2025/12/19 18:30:00 by pamallet         ###   ########.fr       */
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

	const Animal* animals[6];

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

	animals[2]->getBrain();
	animals[5]->getBrain();

	animals[0] = animals[5];

	std::cout << std::endl;

	for (int i = 0; i < 6; i++)
		delete animals[i];
	return (0);
}