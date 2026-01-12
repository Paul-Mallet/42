/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 15:08:18 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/12 15:30:12 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <exception>
# include <cstring>

class AForm;

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