/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:19:25 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/22 10:26:15 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "AAnimal.hpp"

# define MAX_IDEAS 100

/**
 * @class Brain
 * @brief A brain which can have 100 ideas maximum
 * * in a way it could burnout.
 * 
 * @date 12/22/2025
 * @author Paul Mallet
 * 
 * @param string idea - AAnimal brain's best idea.
 * @see AAnimal, Cat, Dog
 * @warning Must be dynamically allocate within Cat and Dog using new and delete.
 */
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