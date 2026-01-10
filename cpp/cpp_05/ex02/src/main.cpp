/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:48:35 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/10 23:24:19 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int	main( int ac, char **av )
{
	if (ac != 1)
		return (1);

	(void)av;

	Bureaucrat* random = NULL;
	AForm* form = NULL;
	ShrubberyCreationForm* shrub_form = NULL;
	// RobotomyRequestForm* robot_form = NULL;
	// PresidentialPardonForm* presi_form = NULL;
	try {
		random = new Bureaucrat();
		form = new AForm();
		shrub_form = new ShrubberyCreationForm();

		shrub_form->createShrubbery();

		delete random;
		delete form;
		delete shrub_form;
	} catch (std::exception &e) {
		delete random;
		delete form;
		delete shrub_form;
		std::cout << e.what() << std::endl;
	}
	return (0);
}