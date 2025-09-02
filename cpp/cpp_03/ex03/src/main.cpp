/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:58:17 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/09/02 16:21:43 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/DiamondTrap.hpp"

int main( void ) {
	DiamondTrap diamond("Diamondi");

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
