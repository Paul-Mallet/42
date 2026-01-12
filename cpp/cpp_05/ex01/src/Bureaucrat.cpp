/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 22:49:57 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/12 15:25:13 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

Bureaucrat::Bureaucrat( void ) : _name("Stagiaire"), _grade(150) {
	std::cout << "Default Constructor - Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, unsigned int grade ) : _name(name) {
	std::cout << "Parameterized Constructor - Bureaucrat" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat( Bureaucrat const &src ) : _name(src._name), _grade(src._grade) {
	std::cout << "Copy Constructor - Bureaucrat" << std::endl;
}

Bureaucrat::~Bureaucrat( void ) {
	std::cout << "Destructor - Bureaucrat" << std::endl;
}

Bureaucrat &Bureaucrat::operator=( Bureaucrat const &rhs ) {
	std::cout << "Copy Assignment - Bureaucrat" << std::endl;
	if (this != &rhs)
		this->_grade = rhs._grade;
	return (*this);
}

std::string Bureaucrat::getName( void ) const {
	return (this->_name);
}

unsigned int Bureaucrat::getGrade( void ) const {
	return (this->_grade);
}

void Bureaucrat::incrementGrade( void ) {
	this->_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade( void ) {
	this->_grade++;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm( Form &f ) {
	try {
		f.beSigned(*this);
		std::cout << this->_name << " signed " << f.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << this->_name << " couldn’t sign " << f.getName()
			<< " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low.");
}

std::ostream &operator<<( std::ostream &o, Bureaucrat const &i ) {
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << "." << std::endl;
	return (o);
}