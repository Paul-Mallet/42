/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:39:38 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/07 12:21:34 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void ) {
	Zombie *horde;

	horde = zombieHorde(ZOMBIE_NB, "Marley");

	for (int i = 0; i < ZOMBIE_NB; ++i)
		horde[i].announce();

	delete [] horde;
	return 0;
}
