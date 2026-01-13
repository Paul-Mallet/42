/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:35:20 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/13 13:59:35 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

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

};

#endif