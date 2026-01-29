/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:05:01 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/29 09:58:36 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main( int ac, char **av )
{
	if (ac != 1) {
		std::cout << "Too many args\nex: ./serializer" << std::endl;
		return (1);
	}
	(void)av;

	Data*		ptr = new Data;
	uintptr_t	raw = 0;

	ptr->i = 42;
	ptr->f = 42.0f;
	ptr->str = "pamallet";

	std::cout << "ptr->i: " << ptr->i << std::endl;
	std::cout << "ptr->f: " << ptr->f << std::endl;
	std::cout << "ptr->str: " << ptr->str << std::endl;

	std::cout << std::endl;

	std::cout << "ptr: " << ptr << std::endl;
	raw = Serializer::serialize(ptr);

	std::cout << "raw: " << raw << std::endl;
	ptr = Serializer::deserialize(raw);

	std::cout << std::endl;

	std::cout << "ptr->i: " << ptr->i << std::endl;
	std::cout << "ptr->f: " << ptr->f << std::endl;
	std::cout << "ptr->str: " << ptr->str << std::endl;

	delete ptr;

	return (0);
}