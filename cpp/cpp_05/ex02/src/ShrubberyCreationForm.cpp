/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 18:12:11 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/11 00:00:39 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) :
	AForm("Shrubbery", 145, 137),
	_target("home") {
	std::cout << "Default Constructor - ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) :
	AForm("Shrubbery", 145, 137),
	_target(target) {
	std::cout << "Parameterized Constructor - ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &src ) :
	AForm(src.getName(), src.getSignedGrade(), src.getExecutedGrade()),
	_target(src._target) {
	std::cout << "Copy Constructor - ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Destructor - ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( ShrubberyCreationForm const &rhs ) {
	std::cout << "Copy Assignment - ShrubberyCreationForm" << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

void ShrubberyCreationForm::createShrubbery( void ) {
	std::ofstream ofs;

	std::string filename = this->_target + "_shrubbery";
	ofs.open(filename.c_str(), std::ofstream::out | std::ofstream::trunc);
	ofs << "    ###" << std::endl;
    ofs	<< "   #o###" << std::endl;
    ofs	<< " #####o###" << std::endl;
   	ofs	<< "#o#\\#|#/###" << std::endl;
    ofs	<< " ###\\|/#o#" << std::endl;
    ofs	<< "  # }|{  #" << std::endl;
    ofs	<< "    }|{" << std::endl;
	ofs.close();
}