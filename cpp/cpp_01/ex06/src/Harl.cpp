/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:23:36 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/18 16:32:18 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl( void ) {}

Harl::~Harl() {}

/**
 * switch keyword:
 * 		ONLY take integral(int, char, bool) as param for perf opti(not like JS which can take whole string)
 * 		break ; in case = stop exec rest of switch
 * 		default: if none of cases validated do something else
 */
void Harl::complain( std::string level ) {
	std::string strings[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int i = 0;

	while (i < 4)
	{
		if (level == strings[i])
			break ;
		i++;
	}

	switch(i) {
		case 0:
			(this->Harl::debug)();
			std::cout << std::endl;
		case 1:
			(this->Harl::info)();
			std::cout << std::endl;
		case 2:
			(this->Harl::warning)();
			std::cout << std::endl;
		case 3:
			(this->Harl::error)();
			std::cout << std::endl;
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}

void Harl::debug( void ) {
	std::cout << "[ DEBUG ]\nI love having extra bacon for my"
		<< " 7XL-double-cheese-triple-pickle-specialketchup burger."
		<< "\nI really do!\n";
}

void Harl::info( void ) {
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money."
		<< "\nYou didn’t put enough bacon in my burger! If you did,"
		<< " I wouldn’t be asking for more!\n";
}

void Harl::warning( void ) {
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free."
		<< "\nI’ve been coming for years, whereas you started working"
		<< " here just last month.\n";
}

void Harl::error( void ) {
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n";
}
