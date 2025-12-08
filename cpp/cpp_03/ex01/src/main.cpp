/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:58:17 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/08 23:02:51 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int main( void ) {
	ClapTrap clap;
	ClapTrap clap2("Clapi");
	ClapTrap clapCopy( clap );
	ScavTrap scav("Scavi");
	ClapTrap *ptr = new ScavTrap("Scavo");

	delete(ptr);
	clapCopy = clap2;

	std::cout << clap << std::endl;
	std::cout << "hp: " << clap.getHitPoint() << std::endl;
	std::cout << "ep: " << clap.getEnergyPoint() << std::endl;
	std::cout << "ad: " << clap.getAttackDamage() << std::endl << std::endl;

	std::cout << clap2 << std::endl;
	std::cout << "hp: " << clap2.getHitPoint() << std::endl;
	std::cout << "ep: " << clap2.getEnergyPoint() << std::endl;
	std::cout << "ad: " << clap2.getAttackDamage() << std::endl << std::endl;

	std::cout << clapCopy << "(copy)" << std::endl;
	std::cout << "hp: " << clapCopy.getHitPoint() << std::endl;
	std::cout << "ep: " << clapCopy.getEnergyPoint() << std::endl;
	std::cout << "ad: " << clapCopy.getAttackDamage() << std::endl << std::endl;

	// ScavTrap
	std::cout << scav << std::endl;
	std::cout << "hp: " << scav.getHitPoint() << std::endl;
	std::cout << "ep: " << scav.getEnergyPoint() << std::endl;
	std::cout << "ad: " << scav.getAttackDamage() << std::endl << std::endl;
	scav.attack("Clapi");
	scav.guardGate();
	return 0;
}
