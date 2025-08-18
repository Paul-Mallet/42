/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:24:01 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/18 16:03:41 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

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

#endif