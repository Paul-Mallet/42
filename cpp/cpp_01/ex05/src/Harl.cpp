/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:23:36 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/18 11:58:03 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl( void ) {
	std::cout << "Harl created.\n";
}

Harl::~Harl() {
	std::cout << "Harl destroyed.\n";	
}

/**
 * void (Harl::*func)() = NULL; -> ptr to func address init to null, waiting for an address
 * scope & accessibility of member functions addresses:
 * 		(RECOMMANDED) func = &Harl::debug; -> access to private mem_fun from "Harl::" class, accessible from everywhere (in/outside)
 * 		(AVOID) func = &debug; -> access only WITHIN a member func of class, here complain already a mem of Harl so it's good
 * (this->*func)() -> deref the ptr func by calling the mem_fun it is pointing to
 */
void Harl::complain( std::string level ) {
	void (Harl::*func)() = NULL;

	switch (stringHash(level))
	{
	case 'D' + 'E' + 'B' + 'U' + 'G':
		func = &Harl::debug;
		break;
	case 'I' + 'N' + 'F' + 'O':
		func = &Harl::info;
		break;
	case 'W' + 'A' + 'R' + 'N' + 'I' + 'N' + 'G':
		func = &Harl::warning;
		break;
	case 'E' + 'R' + 'R' + 'O' + 'R':
		func = &Harl::error;
		break;
	default:
		break;
	}

	if (func)
		(this->*func)();
}

void Harl::debug( void ) {
	std::cout << "DEBUG: I love having extra bacon for my"
		<< " 7XL-double-cheese-triple-pickle-specialketchup burger."
		<< " I really do!\n";
}

void Harl::info( void ) {
	std::cout << "INFO: I cannot believe adding extra bacon costs more money."
		<< " You didn’t put enough bacon in my burger! If you did,"
		<< " I wouldn’t be asking for more!\n";
}

void Harl::warning( void ) {
	std::cout << "WARNING: I think I deserve to have some extra bacon for free."
		<< " I’ve been coming for years, whereas you started working"
		<< " here just last month.\n";
}

void Harl::error( void ) {
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now.\n";
}

int stringHash( std::string level ) {
	int hash;

	hash = 0;
	for (size_t i = 0; i < level.length(); ++i)
		hash += level[i];

	return hash;
}
