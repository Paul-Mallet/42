/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 22:36:00 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/09 11:13:54 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "./Form.hpp"

class Bureaucrat {

	private:
		std::string const	_name;
		unsigned int		_grade;

	public:
		Bureaucrat( void );
		Bureaucrat( std::string name, unsigned int grade );
		Bureaucrat( Bureaucrat const &src );
		~Bureaucrat();

		Bureaucrat &operator=( Bureaucrat const &rhs );

		std::string			getName( void ) const;
		unsigned int		getGrade( void ) const;

		void				incrementGrade( void );
		void				decrementGrade( void );
		void				signForm( Form &f );

		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

};

std::ostream &operator<<( std::ostream &o, Bureaucrat const &i );

#endif