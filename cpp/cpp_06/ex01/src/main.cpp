/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:05:01 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/19 10:12:32 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"

int	main( int ac, char **av )
{
	if (ac != 1)
		return (1);
	(void)av;

	Data*		ptr = new Data;
	uintptr_t	raw = 0;

	ptr->i = 42;
	ptr->f = 42.0f;
	ptr->str = "pamallet";

	std::cout << "ptr->i: " << ptr->i << std::endl;
	std::cout << "ptr->f: " << ptr->f << std::endl;
	std::cout << "ptr->str: " << ptr->str << std::endl;
	std::cout << "raw: " << raw << std::endl;

	std::cout << "ptr: " << ptr << std::endl;
	raw = Serializer::serialize(ptr);

	std::cout << "raw: " << raw << std::endl;
	ptr = Serializer::deserialize(raw);

	std::cout << "ptr: " << ptr << std::endl;
	std::cout << "raw: " << raw << std::endl;
	std::cout << "ptr->i: " << ptr->i << std::endl;
	std::cout << "ptr->f: " << ptr->f << std::endl;
	std::cout << "ptr->str: " << ptr->str << std::endl;

	delete ptr;

	return (0);
}