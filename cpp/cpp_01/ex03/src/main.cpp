/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 09:51:16 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/08 15:01:07 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/*
	can init list at NULL ptr to another OBJECT in constructor without its param
	always think as OBJECT logic if it has ptr to or not ! => mem leak / access to nothing
	can play with stack / heap alloc,
	but think as if the OBJECT should ALWAYS have some attributes or not(ref or ptr)
*/

// not std::endl; each time, << "\n" better for ressources

// int	main( void ) {
// 	Weapon weapon1("axe");
// 	Weapon *weapon2 = new Weapon("bow");

// 	weapon1.setType("sword");
// 	HumanA human1("Georges", weapon1);
// 	HumanB human2("Sabrina");

// 	human1.attack();
// 	human2.attack();

// 	human2.setWeapon(weapon2);
// 	human2.attack();

// 	human2.setWeapon(NULL);
// 	delete weapon2;
// 	return 0;
// }

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