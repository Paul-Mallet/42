/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 11:49:13 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/12 15:33:47 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) :
	AForm("President form", 25, 5),
	_target("home") {
	std::cout << "Default Constructor - PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) :
	AForm("President form", 25, 5),
	_target(target) {
	std::cout << "Parameterized Constructor - PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &src ) :
	AForm(src.getName(), src.getSignedGrade(), src.getExecutedGrade()),
	_target(src._target) {
	std::cout << "Copy Constructor - PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Destructor - PresidentialPardonForm" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( PresidentialPardonForm const &rhs ) {
	std::cout << "Copy Assignment - PresidentialPardonForm" << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

void PresidentialPardonForm::executeAction( void ) const {
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}