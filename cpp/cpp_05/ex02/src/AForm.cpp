/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:56:00 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/10 23:11:45 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm( void ) : _name("Fundamentals"), _isSigned(false), _signedGrade(100), _executedGrade(120) {
	std::cout << "Default Constructor - Form" << std::endl;
}

AForm::AForm( std::string const name, unsigned int const signedGrade, unsigned int const executedGrade ) :
	_name(name),
	_isSigned(false),
	_signedGrade(signedGrade),
	_executedGrade(executedGrade) {
	std::cout << "Parameterized Constructor - Form" << std::endl;
	if (signedGrade < 1)
		throw AForm::GradeTooHighException();
	if (signedGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm( AForm const &src ) :
	_name(src._name),
	_isSigned(src._isSigned),
	_signedGrade(src._signedGrade),
	_executedGrade(src._executedGrade) {
	std::cout << "Copy Constructor - Form" << std::endl;
}

AForm::~AForm() {
	std::cout << "Destructor - Form" << std::endl;
}

AForm &AForm::operator=( AForm const &rhs ) {
	std::cout << "Copy Assignment - Form" << std::endl;
	if (this != &rhs)
		this->_isSigned = rhs._isSigned;
	return (*this);
}

void AForm::beSigned( Bureaucrat const &b ) {
	if (b.getGrade() > this->getSignedGrade())
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

std::string AForm::getName( void ) const {
	return (this->_name);
}

bool AForm::getIsSigned( void ) const {
	return (this->_isSigned);
}

unsigned int AForm::getSignedGrade( void ) const {
	return (this->_signedGrade);
}

unsigned int AForm::getExecutedGrade( void ) const {
	return (this->_executedGrade);
}

const char* AForm::GradeTooHighException::what( void ) const throw() {
	return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what( void ) const throw() {
	return ("Grade is too low");
}

std::ostream &operator<<( std::ostream &o, AForm const &i ) {
	o << i.getName() << ", form signed grade "
		<< i.getSignedGrade() << ", executed grade "
		<< i.getExecutedGrade() << "." << std::endl;
	return (o);
}