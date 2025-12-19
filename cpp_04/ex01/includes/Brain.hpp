/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:19:25 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/12/19 18:29:05 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"

class Brain {

	private:
		std::string _ideas[100];

	public:
		Brain( void );
		Brain( std::string ideas[100] );
		Brain( Brain const &src );
		~Brain();

		Brain				&operator=( Brain const &rhs );

};

#endif