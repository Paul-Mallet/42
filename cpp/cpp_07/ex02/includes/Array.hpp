/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:17:46 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/02 18:17:20 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <exception>

template<typename T>
class Array {

	private:
		T*				_elements;
		unsigned int	_size;

	public:
		Array();
		Array( unsigned int n );
		Array( Array const & src );
		~Array();

		Array& operator=( Array const & rhs );
		T& operator[]( unsigned int i );
		const T& operator[]( unsigned int i ) const;

		unsigned int size( void ) const;

		class OutOfBoundsIndexException: public std::exception {
			public:
				virtual const char* what( void ) const throw();
		};

};

# include "Array.tpp"

#endif