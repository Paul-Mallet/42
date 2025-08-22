/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:52:40 by pamallet          #+#    #+#             */
/*   Updated: 2025/08/22 17:22:40 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap( std::string const &name ) : ClapTrap(name) {
	std::cout << "Parameterized inherited FragTrap constructor called\n";
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
}

FragTrap::~FragTrap(){
	std::cout << "Default inherited FragTrap destructor called\n";
}

void FragTrap::highFivesGuys( void ) {
	std::cout << "FragTrap " << this->_name << " requests a positive high five!\n";
}
