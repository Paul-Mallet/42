/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 00:07:49 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/03 13:50:13 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>

class IntNotFoundException: public std::exception {
	public:
		virtual const char* what( void ) const throw() {
			return ("Int not found");
		};
};

# include "easyfind.tpp"

#endif