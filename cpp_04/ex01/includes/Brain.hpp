/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:19:25 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/21 10:20:21 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"

# define MAX_IDEAS 100

class Brain {

	public:
		std::string		ideas[MAX_IDEAS];

	public:
		Brain( void );
		Brain( std::string idea );
		Brain( Brain const &src );
		~Brain();

		Brain	&operator=( Brain const &rhs );

};

#endif