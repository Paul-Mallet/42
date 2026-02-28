/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:33:52 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/28 13:08:20 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Server.hpp>
#include <Client.hpp>

static long getPort( char ** av ) {
	long port = std::strtol(av[1], NULL, 10);
	if (port < 1024 || port > 65535)
		return (-1);
	return (port);
}

int main( int ac, char ** av ) {
	if (ac != 3) {
		std::cout << "Invalid amount of arguments\nex: ./ircserv [PORT] [PWD]" << std::endl;
		return (1);
	}

	try {
		// 0. Parsing (PORT & Pwd server)
		long port = getPort(av);
		if (port == -1) {
			std::cerr << "Error: Port must be between 1024 and 65535" << std::endl;
			return (1);
		}
		Server serv(static_cast<int>(port), av[2]);
		serv.init();
		serv.start();
	} catch (std::exception & e) {
		std::cerr << "Error: " << e.what() << std::endl;
        return 1;
	}

	return (0);
}