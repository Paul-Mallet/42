/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:05:28 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/06 12:28:32 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>

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

		Bureaucrat const getName() const;
		Bureaucrat const getGrade() const;

		Bureaucrat incrementGrade();
		Bureaucrat decrementGrade();

};

std::ostream &operator<<( std::ostream const &o, Bureaucrat const &i );