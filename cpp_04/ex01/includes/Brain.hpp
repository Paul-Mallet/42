/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:19:25 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/19 19:32:47 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"

class Brain {

	private:
		std::string		_ideas[100];
		unsigned int	_inc = 0;

	public:
		Brain( void );
		Brain( std::string idea );
		Brain( Brain const &src );
		~Brain();

		Brain				&operator=( Brain const &rhs );

		std::string	const	getIdea( unsigned int i );
		void const			setIdea( std::string idea );

};

#endif