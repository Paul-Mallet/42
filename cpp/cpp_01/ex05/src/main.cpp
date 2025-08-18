/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:14:16 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/18 11:50:22 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int main( void )
{
	Harl *harl2_0 = new Harl();
	Harl harl2_00;

	harl2_0->complain("DEBUG");
	harl2_0->complain("INFO");
	harl2_0->complain("WARNING");
	harl2_0->complain("ERROR");

	harl2_00.complain("DEBUG");
	harl2_00.complain("INFO");
	harl2_00.complain("WARNING");
	harl2_00.complain("ERROR");

	delete harl2_0;
	return 0;
}