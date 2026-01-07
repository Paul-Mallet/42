/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:29:18 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/07 18:59:05 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(150) {
	std::cout << "Default constructor" << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, unsigned int grade ) : _name(name) {
	std::cout << "Parameterized constructor" << std::endl;
	if (grade < 1)
		throw tooHigh;
	if (grade > 150)
		throw tooLow;
	this->_grade = grade;
}

Bureaucrat::Bureaucrat( Bureaucrat const &src ) : _name(src._name), _grade(src._grade) {
	std::cout << "Copy constructor" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor" << std::endl;
}

Bureaucrat &Bureaucrat::operator=( Bureaucrat const &rhs ) {
	std::cout << "Assignment operator" << std::endl;
	if (this != &rhs)
	{
		if (rhs._grade < 1)
			throw tooHigh;
		if (rhs._grade > 150)
			throw tooLow;
		this->_grade = rhs._grade;
	}
	return (*this);
}

std::string const Bureaucrat::getName( void ) const {
	return (this->_name);
}

unsigned int Bureaucrat::getGrade( void ) const {
	return (this->_grade);
}

void Bureaucrat::incrementGrade( void ) {
	this->_grade--;
	if (this->_grade < 1)
		throw tooHigh;
}

void Bureaucrat::decrementGrade( void ) {
	this->_grade++;
	if (this->_grade > 150)
		throw tooLow;
}

// without &, slicing trap !
// exception& e 
const char* Bureaucrat::GradeTooHighException::what( void ) const throw() {
	return ("Grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what( void ) const throw() {
	return ("Grade is too low.");
}

std::ostream &operator<<( std::ostream &o, Bureaucrat const &i ) {
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << "." << std::endl;
	return (o);
}