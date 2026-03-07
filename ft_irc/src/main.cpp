/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:33:52 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/03/07 10:27:25 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Server.hpp>
#include <Client.hpp>

int main( int ac, char ** av ) {
	if (ac != 3) {
		std::cout << "Invalid amount of arguments\nex: ./ircserv [PORT] [PWD]" << std::endl;
		return (1);
	}

	try {
		long port = getPort(av);
		Server serv(static_cast<int>(port), av[2]);
		serv.init();
		serv.start();
	} catch (std::exception & e) {
		std::cerr << "Error: " << e.what() << std::endl;
        return 1;
	}
	return (0);
}