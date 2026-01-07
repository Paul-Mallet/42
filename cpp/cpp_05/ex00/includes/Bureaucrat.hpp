/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:05:28 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/07 19:20:14 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <exception>

/**
 * @brief Représente un bureaucrate avec un nom immuable et un grade évolutif.
 * * Le grade est compris strictement entre 1 (plus haut) et 150 (plus bas).
 * @warning Toute tentative de créer ou modifier un grade hors de ces limites lève une exception.
 */
class Bureaucrat {

	private:
		std::string	const	_name;
		unsigned int		_grade;

	public:
		Bureaucrat();
		/**
		 * @brief Construit un nouveau Bureaucrat.
		 * @param name Nom unique du bureaucrate.
		 * @param grade Niveau hiérarchique initial (1 à 150).
		 * @throw Bureaucrat::GradeTooHighException Si le grade est < 1.
		 * @throw Bureaucrat::GradeTooLowException Si le grade est > 150.
		 */
		Bureaucrat( std::string const name, unsigned int grade );
		Bureaucrat( Bureaucrat const &src );
		~Bureaucrat();

		Bureaucrat &operator=( Bureaucrat const &rhs );

		std::string		const getName( void ) const;
		unsigned int	getGrade( void ) const;

		/**
		 * @brief Augmente le grade (diminue la valeur numérique).
		 * @throw GradeTooHighException Si le grade dépasse 1.
		 */
		void			incrementGrade( void );
		/**
		 * @brief Diminue le grade (augmente la valeur numérique).
		 * @throw GradeTooLowException Si le grade dépasse 150.
		 */
		void			decrementGrade( void );

		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what( void ) const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what( void ) const throw();
		};

};

// friend within Class, i._name and i._grade directly !
std::ostream &operator<<( std::ostream &o, Bureaucrat const &i );