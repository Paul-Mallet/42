/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:21:25 by pamallet          #+#    #+#             */
/*   Updated: 2025/12/17 18:02:16 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Animal.hpp"

int	main(int ac, char **av)
{
	if (!av || ac > 2)
		return (1);
	Animal *animal = new Animal(av[1]);

	std::cout << "Hello world!" << std::endl;
	std::cout << ac << av[1] << std::endl;

	delete animal;
	return (0);
}