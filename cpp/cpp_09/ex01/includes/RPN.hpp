/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:37:32 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/08 07:20:35 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <iomanip>
# include <stack>
# include <string>
# include <exception>

class RPN {

	private:
		std::stack<int> _operands;

	public:
		RPN( void );
		RPN( RPN const & src );
		~RPN();

		RPN & operator=( RPN const & rhs );

		std::stack<int> getOperands( void );

		bool isoperator( char c ) const;
        void calculate( char op );
		void evaluate( std::string & expression );
		void display( void ) const;

		class InvalidCharacterFoundException: public std::exception {
			public:
				virtual const char * what( void ) const throw();
		};
		class DigitNotLessThanTenException: public std::exception {
			public:
				virtual const char * what( void ) const throw();
		};
		class OperatorNotIsolatedException: public std::exception {
			public:
				virtual const char * what( void ) const throw();
		};
		class NotEnoughNumbersToCalculateException: public std::exception {
			public:
				virtual const char * what( void ) const throw();
		};
		class DivisionByZeroException: public std::exception {
			public:
				virtual const char * what( void ) const throw();
		};
		class TooManyOperandsInResultException: public std::exception {
			public:
				virtual const char * what( void ) const throw();
		};
};

#endif