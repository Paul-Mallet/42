/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:38:25 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/09 11:10:25 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class Form {

	private:
		std::string const	_name;
		bool				_isSigned;
		unsigned int const	_signedGrade;
		unsigned int const	_executedGrade;

	public:
		Form( void );
		Form( std::string const name, unsigned int const signedGrade, unsigned int const executedGrade );
		Form( Form const &src );
		~Form();

		Form &operator=( Form const &rhs );

		std::string			getName( void ) const;
		bool				getIsSigned( void ) const;
		unsigned int		getSignedGrade( void ) const;
		unsigned int		getExecutedGrade( void ) const;

		void				beSigned( Bureaucrat const &b );

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what( void ) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what( void ) const throw();
		};

	};

std::ostream &operator<<( std::ostream &o, Form const &i );

#endif