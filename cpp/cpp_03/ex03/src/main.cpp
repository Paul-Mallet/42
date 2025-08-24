/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:58:17 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/24 11:30:08 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/DiamondTrap.hpp"

int main( void ) {
	// ClapTrap clap2("Clapi");
	DiamondTrap diamond("Diamondi");

	// std::cout << clap2 << std::endl;
	// std::cout << "hp: " << clap2.getHitPoint() << std::endl;
	// std::cout << "ep: " << clap2.getEnergyPoint() << std::endl;
	// std::cout << "ad: " << clap2.getAttackDamage() << std::endl << std::endl;

	// beRepaired 2nd phase
	// clap2.beRepaired(2);
	// clap2.beRepaired(2);
	// clap2.beRepaired(2);
	// clap2.beRepaired(2);
	// clap2.beRepaired(2);
	// clap2.beRepaired(2);
	// clap2.beRepaired(2);
	// clap2.beRepaired(2);

	// clap2.takeDamage(2);
	// clap2.beRepaired(2);

	// std::cout << clap2 << std::endl;
	// std::cout << "hp: " << clap2.getHitPoint() << std::endl;
	// std::cout << "ep: " << clap2.getEnergyPoint() << std::endl;
	// std::cout << "ad: " << clap2.getAttackDamage() << std::endl << std::endl;

	// // Diamond phase
	std::cout << diamond << std::endl;
	std::cout << "hp: " << diamond.getHitPoint() << std::endl;
	std::cout << "ep: " << diamond.getEnergyPoint() << std::endl;
	std::cout << "ad: " << diamond.getAttackDamage() << std::endl;
	diamond.attack("Scavi");
	diamond.guardGate();
	diamond.highFivesGuys();
	return 0;
}
