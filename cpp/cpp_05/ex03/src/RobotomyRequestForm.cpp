/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 10:19:34 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/11 12:05:11 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) :
	AForm("Robotomy form", 72, 45),
	_target("home") {
	std::cout << "Default Constructor - RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) :
	AForm("Robotomy form", 72, 45),
	_target(target) {
	std::cout << "Parameterized Constructor - RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &src ) :
	AForm(src.getName(), src.getSignedGrade(), src.getExecutedGrade()),
	_target(src._target) {
	std::cout << "Copy Constructor - RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Destructor - RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( RobotomyRequestForm const &rhs ) {
	std::cout << "Copy Assignment - RobotomyRequestForm" << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

void RobotomyRequestForm::executeAction( void ) const {
	int randomRobotomy = rand() % 2;

	if (randomRobotomy == 0)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->_target << " robotomy failed" << std::endl;
}