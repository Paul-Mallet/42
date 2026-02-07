/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:37:16 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/07 14:42:19 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main( int ac, char** av ) {
	if (ac != 2) {
		std::cout << "Invalid arguments\nex1: ./btc input.txt\nex2: ./btc txt/input.txt" << std::endl;
		return (1);
	}

	BitcoinExchange btc;
	btc.loadDatabase("data/data.csv");
	if (btc.getDatabase().size() > 0)
		btc.processInput(av[1]);

	return (0);
}