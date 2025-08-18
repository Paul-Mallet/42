/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:38:08 by pamallet          #+#    #+#             */
/*   Updated: 2025/08/18 14:48:41 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

// ./harlFilter "WARNING" || ./harlFilter "other than level" -> return same string
int main ( int ac, char **av )
{
	if (ac != 2)
	{
		std::cout << "Valid format: ./harlFilter \"WARNING\"\n";
		return 0;
	}

	Harl harl2_0;
	Harl *harl2_00 = new Harl();

	harl2_0.complain(av[1]);
	harl2_00->complain(av[1]);

	delete harl2_00;
	return 0;
}
