/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:56:00 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/12 15:25:09 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

Form::Form( void ) : _name("Fundamentals"), _isSigned(false), _signedGrade(100), _executedGrade(120) {
	std::cout << "Default Constructor - Form" << std::endl;
}

Form::Form( std::string const name, unsigned int const signedGrade, unsigned int const executedGrade ) :
	_name(name),
	_isSigned(false),
	_signedGrade(signedGrade),
	_executedGrade(executedGrade) {
	std::cout << "Parameterized Constructor - Form" << std::endl;
	if (signedGrade < 1)
		throw Form::GradeTooHighException();
	if (signedGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form( Form const &src ) :
	_name(src._name),
	_isSigned(src._isSigned),
	_signedGrade(src._signedGrade),
	_executedGrade(src._executedGrade) {
	std::cout << "Copy Constructor - Form" << std::endl;
}

Form::~Form() {
	std::cout << "Destructor - Form" << std::endl;
}

Form &Form::operator=( Form const &rhs ) {
	std::cout << "Copy Assignment - Form" << std::endl;
	if (this != &rhs)
		this->_isSigned = rhs._isSigned;
	return (*this);
}

void Form::beSigned( Bureaucrat const &b ) {
	if (b.getGrade() > this->getSignedGrade())
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

std::string Form::getName( void ) const {
	return (this->_name);
}

bool Form::getIsSigned( void ) const {
	return (this->_isSigned);
}

unsigned int Form::getSignedGrade( void ) const {
	return (this->_signedGrade);
}

unsigned int Form::getExecutedGrade( void ) const {
	return (this->_executedGrade);
}

const char* Form::GradeTooHighException::what( void ) const throw() {
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what( void ) const throw() {
	return ("Grade is too low");
}

std::ostream &operator<<( std::ostream &o, Form const &i ) {
	o << i.getName() << ", form signed grade "
		<< i.getSignedGrade() << ", executed grade "
		<< i.getExecutedGrade() << "." << std::endl;
	return (o);
}