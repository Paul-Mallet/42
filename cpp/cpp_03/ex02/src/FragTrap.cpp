/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:52:40 by pamallet          #+#    #+#             */
/*   Updated: 2025/08/24 11:17:21 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap() {
	std::cout << "Default inherited FragTrap constructor called\n";
}

FragTrap::FragTrap( std::string const &name ) : ClapTrap(name) {
	std::cout << "Parameterized inherited FragTrap constructor called\n";
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
}

FragTrap::~FragTrap(){
	std::cout << "Default inherited FragTrap destructor called\n";
}

// Not ask for attack() msg modif
void FragTrap::highFivesGuys( void ) {
	std::cout << "FragTrap " << this->_name << " requests a positive high five!\n";
}
