/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:23:36 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/18 16:47:27 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl( void ) {}

Harl::~Harl() {}

/**
 * void (Harl::*func)() = NULL; -> ptr to func address init to null, waiting for an address
 * scope & accessibility of member functions addresses:
 * 		(RECOMMANDED) func = &Harl::debug; -> access to private mem_fun from "Harl::" class, accessible from everywhere (in/outside)
 * 		(AVOID) func = &debug; -> access only WITHIN a member func of class, here complain already a mem of Harl so it's good
 * (this->*func)() -> deref the ptr func by calling the mem_fun it is pointing to
 */
void Harl::complain( std::string level ) {
	std::string strings[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	void (Harl::*funcs[4])( void ) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	for (int i = 0; i < 3; ++i)
	{
		if (level == strings[i])
			return (this->*funcs[i])();
	}

	return ;
}

void Harl::debug( void ) {
	std::cout << "[ DEBUG ]\nI love having extra bacon for my"
		<< " 7XL-double-cheese-triple-pickle-specialketchup burger."
		<< "\nI really do!\n";
}

void Harl::info( void ) {
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money."
		<< "\nYou didn’t put enough bacon in my burger!\nIf you did,"
		<< " I wouldn’t be asking for more!\n";
}

void Harl::warning( void ) {
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free."
		<< "\nI’ve been coming for years, whereas you started working"
		<< " here just last month.\n";
}

void Harl::error( void ) {
	std::cout << "[ ERROR ]\nThis is unacceptable!\nI want to speak to the manager now.\n";
}
