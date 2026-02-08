/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:39:37 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/08 07:44:03 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN( void ) {
	std::cout << "RPN - Default Constructor" << std::endl;
}

RPN::RPN( RPN const & src ): _operands(src._operands) {
	std::cout << "RPN - Copy Constructor" << std::endl;
}

RPN::~RPN() {
	std::cout << "RPN - Destructor" << std::endl;
}

RPN & RPN::operator=( RPN const & rhs ) {
	if (this != &rhs)
		this->_operands = rhs._operands;
	return (*this);
}

std::stack<int> RPN::getOperands( void ) {
	return (this->_operands);
}

bool RPN::isoperator( char c ) const {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::calculate( char op ) {
	int a = 0;
	int b = 0;

	if (this->_operands.size() < 2)
		throw (NotEnoughNumbersToCalculateException());

	b = this->_operands.top();
	if (op == '/' && b == 0)
		throw (DivisionByZeroException());

	this->_operands.pop();
	a = this->_operands.top();
	this->_operands.pop();
	if (op == '+')
		a += b;
	else if (op == '-')
		a -= b;
	else if (op == '*')
		a *= b;
	else
		a /= b;
	this->_operands.push(a);
}

void RPN::evaluate( std::string & expression ) {
	size_t pos = 0;

	pos = expression.find_first_not_of("0123456789+-*/ ");
	if (pos != std::string::npos)
		throw (InvalidCharacterFoundException());

	for(std::string::iterator it = expression.begin(); it != expression.end(); ++it) {
		if (isspace(*it))
			continue ;
		if (isdigit(*it)) {
			if (isdigit(*(it + 1)))
				throw (DigitNotLessThanTenException());
			this->_operands.push(*it - '0');
		}
		else if (this->isoperator(*it)) {
			if ( ( !isspace(*(it + 1)) && (it + 1) != expression.end() )
				|| (!isspace(*(it - 1)) && (it - 1) != expression.begin() ))
				throw (OperatorNotIsolatedException());
			this->calculate(*it);
		}
		else
			throw (InvalidCharacterFoundException());
	}
	if (this->_operands.size() != 1)
		throw(TooManyOperandsInResultException());
	this->display();
}

void RPN::display( void ) const {
	std::stack<int> tmp(this->_operands);

	for (size_t i = 0; i < this->_operands.size(); ++i) {
		std::cout << tmp.top() << std::endl;
		tmp.pop();
	}
}

const char * RPN::InvalidCharacterFoundException::what( void ) const throw() {
	return ("Invalid character found");
}

const char * RPN::DigitNotLessThanTenException::what( void ) const throw() {
	return ("Digit not less than 10");
}

const char * RPN::OperatorNotIsolatedException::what( void ) const throw() {
	return ("Operator not isolated");
}

const char * RPN::NotEnoughNumbersToCalculateException::what( void ) const throw() {
	return ("Not enough numbers to calculate");
}

const char * RPN::DivisionByZeroException::what( void ) const throw() {
	return ("Division by zero");
}

const char * RPN::TooManyOperandsInResultException::what( void ) const throw() {
	return ("Too many operands in result");
}