/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:13:56 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/26 15:43:34 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

/**
 * Code bloat: gonflement inutile binaire du code
 * ex: <typename T, unsigned int, typename C> WRONG !!!
 * 
 * type deduction: explicit <type> -> || implicit
 * * if <typename T> -> must be same type everywhere
 * * 
 */
template<typename T, typename F>
void iter( T* array, unsigned int const len, F f ) {
	for(unsigned int i = 0; i < len; ++i)
		(f)(array[i]);
}

template<typename T>
void add_two( T& value ) {
	value += 2;
}

template<typename T>
void print( T& value ) {
	std::cout << value << std::endl;
}

#endif