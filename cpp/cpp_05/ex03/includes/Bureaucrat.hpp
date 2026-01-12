/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 22:36:00 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/12 15:28:30 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class AForm;

/**
 * @brief Représente un bureaucrate avec un nom immuable et un grade évolutif.
 * * Le grade est compris strictement entre 1 (plus haut) et 150 (plus bas).
 * @warning Toute tentative de créer ou modifier un grade hors de ces limites lève une exception.
 */
class Bureaucrat {

	private:
		std::string const	_name;
		unsigned int		_grade;

	public:
		Bureaucrat( void );
		/**
		 * @brief Construit un nouveau Bureaucrat.
		 * @param name Nom unique du bureaucrate.
		 * @param grade Niveau hiérarchique initial (1 à 150).
		 * @throw Bureaucrat::GradeTooHighException Si le grade est < 1.
		 * @throw Bureaucrat::GradeTooLowException Si le grade est > 150.
		 */
		Bureaucrat( std::string name, unsigned int grade );
		Bureaucrat( Bureaucrat const &src );
		~Bureaucrat();

		Bureaucrat &operator=( Bureaucrat const &rhs );

		std::string			getName( void ) const;
		unsigned int		getGrade( void ) const;

		void				incrementGrade( void );
		void				decrementGrade( void );
		void				signForm( AForm &form );
		void				executeForm( AForm const &form ) const;

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