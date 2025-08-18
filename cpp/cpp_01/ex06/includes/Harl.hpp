/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:39:56 by pamallet          #+#    #+#             */
/*   Updated: 2025/08/18 14:42:17 by pamallet         ###   ########.fr       */
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