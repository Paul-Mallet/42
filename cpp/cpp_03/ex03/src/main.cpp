/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:58:17 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/24 21:48:21 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/DiamondTrap.hpp"

int main( void ) {
	// ClapTrap clap2("Clapi");
	DiamondTrap diamond("Diamondi");

	// Diamond phase
	std::cout << diamond << std::endl;
	std::cout << "hp: " << diamond.getHitPoint() << std::endl;
	std::cout << "ep: " << diamond.getEnergyPoint() << std::endl;
	std::cout << "ad: " << diamond.getAttackDamage() << std::endl;
	diamond.attack("Scavi");
	diamond.guardGate();
	diamond.highFivesGuys();
	diamond.whoAmI();
	std::cout << std::endl;
	return 0;
}
