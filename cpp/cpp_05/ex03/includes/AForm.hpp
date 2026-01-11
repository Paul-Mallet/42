/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:38:25 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/11 12:40:18 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "./Bureaucrat.hpp"

class Bureaucrat;

/**
 * @class Form
 * @brief Classe représentant un formulaire administratif.
 * * Un formulaire possède un nom, un statut (signé ou non) et des grades requis
 * pour la signature et l'exécution. Les grades sont immuables et doivent être
 * compris entre 1 et 150.
 */
class AForm {

	private:
		std::string const	_name;
		bool				_isSigned;
		unsigned int const	_signedGrade;
		unsigned int const	_executedGrade;

	public:
		AForm( void );
		/**
         * @brief Constructeur paramétré.
         * @param name Nom du formulaire.
         * @param signedGrade Grade requis pour signer (1-150).
         * @param executedGrade Grade requis pour exécuter (1-150).
         * @throw Form::GradeTooHighException Si un grade est < 1.
         * @throw Form::GradeTooLowException Si un grade est > 150.
         */
		AForm( std::string const name, unsigned int const signedGrade, unsigned int const executedGrade );
		AForm( AForm const &src );
		virtual ~AForm();

		AForm &operator=( AForm const &rhs );

		/** @name Getters */
        /** @{ */
		std::string			getName( void ) const;
		bool				getIsSigned( void ) const;
		unsigned int		getSignedGrade( void ) const;
		unsigned int		getExecutedGrade( void ) const;
        /** @} */

		/**
         * @brief Tente de faire signer le formulaire par un bureaucrate.
         * @param b Le Bureaucrat tentant de signer.
         * @throw Form::GradeTooLowException Si le grade du bureaucrate est trop faible.
         */
		void				beSigned( Bureaucrat const &b );

		/**
		 * @brief ...
		 */
		virtual void		executeAction( void ) const = 0;
		/**

		 * @brief ...
		 */
		void 				execute(Bureaucrat const &executor) const;

		/**
         * @exception GradeTooHighException
         * @brief Lancée quand un grade est supérieur à 1.
         */
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what( void ) const throw();
		};

		/**
         * @exception GradeTooLowException
         * @brief Lancée quand un grade est inférieur à 150 ou insuffisant.
         */
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what( void ) const throw();
		};

		/**
         * @exception FormNotSignedException
         * @brief Lancée quand un form n'est pas signed.
         */
		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what( void ) const throw();
		};

	};

std::ostream &operator<<( std::ostream &o, AForm const &i );

#endif