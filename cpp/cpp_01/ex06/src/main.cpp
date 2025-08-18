/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:38:08 by pamallet          #+#    #+#             */
/*   Updated: 2025/08/18 16:23:22 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

// ./harlFilter "WARNING" || ./harlFilter "other than level" -> return same string
int main ( int ac, char **av )
{
	Harl harl2_0;

	if (ac != 2)
	{
		std::cout << "Valid format: ./harlFilter \"WARNING\"\n";
		return 0;
	}

	harl2_0.complain(av[1]);
	
	return 0;
}
