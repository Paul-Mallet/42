/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:21:25 by pamallet          #+#    #+#             */
/*   Updated: 2025/12/19 12:39:59 by paul_mallet      ###   ########.fr       */
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

	const Animal* animal = new Animal();
	const Animal* animalv2 = new Animal(av[1]);
	const Animal* animalv3 = animal;
	const Animal* cat = new Cat();
	const Animal* catv2 = new Cat(av[1]);
	const Animal* catv3 = cat;
	const Animal* dog = new Dog();
	const Animal* dogv2 = new Dog(av[1]);
	const Animal* dogv3 = dog;
	const WrongAnimal* wrong_animal = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();

	std::cout << std::endl;

	animal->getType();
	animalv2->getType();
	animalv3->getType();

	std::cout << std::endl;

	std::cout << animal->getType() << std::endl;
	std::cout << animalv2->getType() << std::endl;
	std::cout << animalv3->getType() << std::endl;

	std::cout << std::endl;

	animal->makeSound();
	animalv2->makeSound();
	animalv3->makeSound();

	std::cout << std::endl;

	dog->getType();
	dogv2->getType();
	dogv3->getType();

	std::cout << std::endl;

	dog->makeSound();
	dogv2->makeSound();
	dogv3->makeSound();

	std::cout << std::endl;

	cat->getType();
	catv2->getType();
	catv3->getType();

	std::cout << std::endl;

	cat->makeSound();
	catv2->makeSound();
	catv3->makeSound();

	std::cout << std::endl;

	wrong_cat->getType();
	wrong_cat->getType();
	wrong_cat->getType();

	std::cout << std::endl;

	wrong_cat->makeSound();
	wrong_cat->makeSound();
	wrong_cat->makeSound();

	std::cout << std::endl;

	delete animal;
	delete animalv2;
	delete dog;
	delete dogv2;
	delete cat;
	delete catv2;
	delete wrong_animal;
	delete wrong_cat;
	return (0);
}