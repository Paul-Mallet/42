/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 22:57:58 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/17 12:08:59 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <typeinfo>

class ScalarConverter {

	public:
		ScalarConverter( void );
		ScalarConverter( ScalarConverter const &src );
		~ScalarConverter();

		ScalarConverter &operator=( ScalarConverter const &rhs );

		void convert( std::string literal );

};

std::ostream &operator<<( std::ostream &o, ScalarConverter const &i );

#endif