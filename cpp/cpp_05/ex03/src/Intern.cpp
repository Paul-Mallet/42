/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 15:14:24 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/12 15:35:48 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

Intern::Intern( void ) {
	std::cout << "Default Constructor - Intern" << std::endl;
}

Intern::Intern( Intern const &src ) {
	std::cout << "Copy Constructor - Intern" << std::endl;
	*this = src;
}

Intern::~Intern() {
	std::cout << "Destructor - Intern" << std::endl;
}

Intern &Intern::operator=( Intern const &rhs ) {
	std::cout << "Copy Assignment - Intern" << std::endl;
	(void)rhs;
	return (*this);
}

AForm* Intern::makeForm( std::string formName, std::string formTarget ) {
	AForm*			form = NULL;
	std::string		validNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon",
	};
	int				validIndex = -1;

	for (int i = 0; i < 3; i++) {
		if (validNames[i] == formName ) {
			validIndex = i;
			break ;
		}
	}

	switch (validIndex) {
		case 0:
			form = new ShrubberyCreationForm(formTarget);
			break ;
		case 1:
			form = new RobotomyRequestForm(formTarget);
			break ;
		case 2:
			form = new PresidentialPardonForm(formTarget);
			break ;
		default :
			throw Intern::FormNameDoesNotExistException();
	}

	std::cout << "Intern created " << formName << std::endl;
	return (form);
}

const char* Intern::FormNameDoesNotExistException::what( void ) const throw() {
	return ("Form name does not exist");
}