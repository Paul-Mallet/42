/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:58:17 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/22 16:41:31 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int main( void ) {
	ClapTrap clap;
	ClapTrap clap2("Clapi");
	ClapTrap clapCopy( clap );
	ScavTrap scav("Scavi");

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

	// attack & beRepaired phase
	clap.attack("Clapi");
	clap2.beRepaired(2);
	std::cout << clap << std::endl;
	std::cout << "hp: " << clap.getHitPoint() << std::endl;
	std::cout << "ep: " << clap.getEnergyPoint() << std::endl;
	std::cout << "ad: " << clap.getAttackDamage() << std::endl << std::endl;

	std::cout << clap2 << std::endl;
	std::cout << "hp: " << clap2.getHitPoint() << std::endl;
	std::cout << "ep: " << clap2.getEnergyPoint() << std::endl;
	std::cout << "ad: " << clap2.getAttackDamage() << std::endl << std::endl;

	// attack 2nd phase
	clap.attack("Clapi");
	clap.attack("Clapi");
	clap.attack("Clapi");
	clap.attack("Clapi");
	clap.attack("Clapi");
	clap.attack("Clapi");
	clap.attack("Clapi");
	clap.attack("Clapi");
	clap.attack("Clapi");
	clap.attack("Clapi");
	std::cout << clap << std::endl;
	std::cout << "hp: " << clap.getHitPoint() << std::endl;
	std::cout << "ep: " << clap.getEnergyPoint() << std::endl;
	std::cout << "ad: " << clap.getAttackDamage() << std::endl << std::endl;

	std::cout << clap2 << std::endl;
	std::cout << "hp: " << clap2.getHitPoint() << std::endl;
	std::cout << "ep: " << clap2.getEnergyPoint() << std::endl;
	std::cout << "ad: " << clap2.getAttackDamage() << std::endl << std::endl;

	// beRepaired 2nd phase
	clap2.beRepaired(2);
	clap2.beRepaired(2);
	clap2.beRepaired(2);
	clap2.beRepaired(2);
	clap2.beRepaired(2);
	clap2.beRepaired(2);
	clap2.beRepaired(2);
	clap2.beRepaired(2);

	clap2.takeDamage(2);
	clap2.beRepaired(2);

	clap2.takeDamage(1);
	clap2.beRepaired(1);
	// clap2.takeDamage(100);
	std::cout << clap << std::endl;
	std::cout << "hp: " << clap.getHitPoint() << std::endl;
	std::cout << "ep: " << clap.getEnergyPoint() << std::endl;
	std::cout << "ad: " << clap.getAttackDamage() << std::endl << std::endl;

	std::cout << clap2 << std::endl;
	std::cout << "hp: " << clap2.getHitPoint() << std::endl;
	std::cout << "ep: " << clap2.getEnergyPoint() << std::endl;
	std::cout << "ad: " << clap2.getAttackDamage() << std::endl << std::endl;
	
	// ScavTrap phase
	std::cout << scav << std::endl;
	std::cout << "hp: " << scav.getHitPoint() << std::endl;
	std::cout << "ep: " << scav.getEnergyPoint() << std::endl;
	std::cout << "ad: " << scav.getAttackDamage() << std::endl << std::endl;
	return 0;
}
