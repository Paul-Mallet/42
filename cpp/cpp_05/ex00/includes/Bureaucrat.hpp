/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:05:28 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/07 18:53:16 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat {

	private:
		std::string	const	_name;
		unsigned int		_grade;

	public:
		Bureaucrat();
		Bureaucrat( std::string const name, unsigned int grade );
		Bureaucrat( Bureaucrat const &src );
		~Bureaucrat();

		Bureaucrat &operator=( Bureaucrat const &rhs );

		std::string		const getName( void ) const;
		unsigned int	getGrade( void ) const;

		void			incrementGrade( void );
		void			decrementGrade( void );

		class GradeTooHighException: public std::exception {

			public:
				virtual const char* what( void ) const throw();

		} tooHigh;
		class GradeTooLowException: public std::exception {

			public:
				virtual const char* what( void ) const throw();

		} tooLow;

};

std::ostream &operator<<( std::ostream &o, Bureaucrat const &i );