/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:48:35 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/11 16:08:20 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int	main( int ac, char **av )
{
	if (ac != 1)
		return (1);
	(void)av;

	// AForm* form = NULL;
	Bureaucrat* random = NULL;
	Bureaucrat* jenna = NULL;
	Bureaucrat* fujiro = NULL;

	ShrubberyCreationForm*	shrub_form = NULL;
	ShrubberyCreationForm*	jenna_shrub_form = NULL;
	ShrubberyCreationForm*	fujiro_shrub_form = NULL;
	RobotomyRequestForm*	robot_form = NULL;
	PresidentialPardonForm*	presi_form = NULL;
	try {
		// form = new AForm();
		random = new Bureaucrat();
		jenna = new Bureaucrat("Jenna", 45);
		fujiro = new Bureaucrat("Fujiro", 4);

		shrub_form = new ShrubberyCreationForm();
		jenna_shrub_form = new ShrubberyCreationForm("room");
		fujiro_shrub_form = new ShrubberyCreationForm("office");
		robot_form = new RobotomyRequestForm();
		presi_form = new PresidentialPardonForm();

		std::cout << std::endl;
		random->signForm(*shrub_form);
		random->executeForm(*shrub_form);
		random->signForm(*robot_form);
		random->executeForm(*robot_form);
		random->signForm(*presi_form);
		random->executeForm(*presi_form);
		std::cout << std::endl;
		jenna->signForm(*jenna_shrub_form);
		jenna->executeForm(*jenna_shrub_form);
		jenna->signForm(*robot_form);
		jenna->executeForm(*robot_form);
		jenna->signForm(*presi_form);
		jenna->executeForm(*presi_form);
		std::cout << std::endl;
		fujiro->signForm(*fujiro_shrub_form);
		fujiro->executeForm(*fujiro_shrub_form);
		fujiro->signForm(*robot_form);
		fujiro->executeForm(*robot_form);
		fujiro->signForm(*presi_form);
		fujiro->executeForm(*presi_form);
		std::cout << std::endl;

		delete random;
		delete jenna;
		delete fujiro;
		delete shrub_form;
		delete jenna_shrub_form;
		delete fujiro_shrub_form;
		delete robot_form;
		delete presi_form;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		delete random;
		delete jenna;
		delete fujiro;
		delete shrub_form;
		delete jenna_shrub_form;
		delete fujiro_shrub_form;
		delete robot_form;
		delete presi_form;
	}
	return (0);
}