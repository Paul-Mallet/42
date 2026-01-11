/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 15:08:18 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/11 15:28:31 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <cstring>
# include "./AForm.hpp"
# include "./ShrubberyCreationForm.hpp"
# include "./RobotomyRequestForm.hpp"
# include "./PresidentialPardonForm.hpp"

class Intern {

	public:
		Intern( void );
		Intern( Intern const &src );
		~Intern();

		Intern &operator=( Intern const &rhs );

		AForm* makeForm( std::string formName, std::string formTarget );

		class FormNameDoesNotExistException: public std::exception {
			public:
				virtual const char* what( void ) const throw();
		};
};

#endif