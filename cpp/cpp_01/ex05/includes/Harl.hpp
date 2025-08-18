/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:24:01 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/18 11:08:58 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl {

	public:
		Harl( void );
		~Harl();

		void complain( std::string level );

	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

};

int stringHash( std::string level );

#endif