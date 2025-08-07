/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:12:51 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/07 11:15:44 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
	new(): combine void *mem = operator new(size_t) + new(mem) ClassName();
		 dynamically alloc mem for an Object, still need to be deleted(free mem)
	delete '[]': free Object's mem,
		   think of destructor scope
		   	- if instanciated in function, auto destructor called at end of it
		   		= local used/short-lived/small or fixed size/no sharing criterias
	ex:
		Zombie zombie("Bob"); //no dft constructor
		Zombie *zombie2 = new Zombie("Dylan");
		void *rawZombieMem = operator new(sizeof(Zombie));
		Zombie *zombie3 = new(rawZombieMem) Zombie("Marcel");

		zombie.announce();
		zombie2->announce();
		zombie3->announce();

		delete zombie2;
		delete zombie3;
*/
int	main( void ) {
	Zombie *bob = newZombie("Bob");

	randomChump("Dylan");

	delete bob;
	return 0;
};
