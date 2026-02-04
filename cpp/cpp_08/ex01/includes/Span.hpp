/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:40:55 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/04 11:30:38 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>

class Span {

	private:
		unsigned int				_n;
		std::vector<unsigned int>	_storage;

	public:
		Span( void );
		Span( unsigned int N );
		Span( Span const & src );
		~Span();

		Span & operator=( Span const & rhs );

		std::vector<unsigned int> getStorage( void ) const;
		unsigned int getCapacity( void ) const;

		void			addNumber( unsigned int number );
		unsigned int	shortestSpan( void ) const;
		unsigned int	longestSpan( void ) const;
		// x10k member function

		class SpanStorageIsFullException: public std::exception {
			public:
				virtual const char * what( void ) const throw() {
					return ("Span storage is full");
				};
		};
		class NotEnoughNumbersStoredException: public std::exception {
			public:
				virtual const char * what( void ) const throw() {
					return ("Not enough numbers stored");
				};
		};

};

#endif