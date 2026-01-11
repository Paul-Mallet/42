/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 17:48:35 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/11 16:19:00 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

int	main( int ac, char **av )
{
	if (ac != 1)
		return (1);
	(void)av;

	Bureaucrat* fujiro = NULL;
	Intern*		intern = NULL;
	AForm* 		scf = NULL;
	AForm* 		rrf = NULL;
	AForm* 		ppf = NULL;
	AForm* 		unknown = NULL;

	ShrubberyCreationForm*	fujiro_shrub_form = NULL;
	RobotomyRequestForm*	robot_form = NULL;
	PresidentialPardonForm*	presi_form = NULL;
	try {
		fujiro = new Bureaucrat("Fujiro", 4);
		intern = new Intern();

		fujiro_shrub_form = new ShrubberyCreationForm("office");
		robot_form = new RobotomyRequestForm();
		presi_form = new PresidentialPardonForm();

		std::cout << std::endl;
		fujiro->signForm(*fujiro_shrub_form);
		fujiro->executeForm(*fujiro_shrub_form);
		fujiro->signForm(*robot_form);
		fujiro->executeForm(*robot_form);
		fujiro->signForm(*presi_form);
		fujiro->executeForm(*presi_form);
		std::cout << std::endl;
		scf = intern->makeForm("shrubbery creation", "toilet");
		rrf = intern->makeForm("robotomy request", "toilet");
		ppf = intern->makeForm("presidential pardon", "toilet");
		unknown = intern->makeForm("not existing form", "toilet");
		std::cout << std::endl;
		fujiro->signForm(*scf);
		fujiro->executeForm(*scf);
		fujiro->signForm(*rrf);
		fujiro->executeForm(*rrf);
		fujiro->signForm(*ppf);
		fujiro->executeForm(*ppf);
		std::cout << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		std::cout << std::endl;
	}
	delete fujiro;
	delete intern;
	delete fujiro_shrub_form;
	delete robot_form;
	delete presi_form;
	delete scf;
	delete rrf;
	delete ppf;
	delete unknown;
	return (0);
}