/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 09:51:16 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/17 09:22:32 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"
#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"

/*
	can init list at NULL ptr to another OBJECT in constructor without its param
	always think as OBJECT logic if it has ptr to or not ! => mem leak / access to nothing
	can play with stack / heap alloc,
	but think as if the OBJECT should ALWAYS have some attributes or not(ref or ptr)
	3 ways to pass instances(Object) as a function's param
		instance as a param = copy of this instance
		instance ref as a param = this instance
		instance ptr as a param = the address of this instance
*/
int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}