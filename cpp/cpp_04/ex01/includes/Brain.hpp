/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 08:43:46 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/25 09:36:03 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {

	public:
		Brain( void );
		Brain( std::string ideas[100] );
		Brain( Brain const &src );
		virtual ~Brain();

		Brain &operator=( Brain const &rhs );

		std::string ideas[100];

};

#endif