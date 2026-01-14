/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:35:20 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/14 11:41:31 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <exception>

/**
 * @brief 
 * Must not be instanciable by user !
 */
class ScalarConverter {

	public:
		ScalarConverter( void );
		ScalarConverter( ScalarConverter const &src );
		virtual ~ScalarConverter();

		ScalarConverter &operator=( ScalarConverter const &rhs );

		/**
		 * @brief 
		 * non displayable chars < 32 (ascii) -> info message
		 * 
		 */
		static void convert( std::string literal );

		class NonDisplayableCharException : public std::exception {
			public:
				virtual const char* what( void ) const throw();
		};
};

class ScalarConverterDerived : public ScalarConverter {
	public:
		~ScalarConverterDerived();
};

#endif