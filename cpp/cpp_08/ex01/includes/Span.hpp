/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 19:40:55 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/05 11:08:07 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <iterator>
# include <sstream>
# include <algorithm>
# include <exception>

class Span {

	private:
		unsigned int		_n;
		std::vector<int>	_storage;

	public:
		Span( void );
		Span( unsigned int N );
		Span( Span const & src );
		~Span();

		Span & operator=( Span const & rhs );

		std::vector<int> getStorage( void ) const;
		unsigned int getCapacity( void ) const;

		void			addNumber( int number );
		unsigned int	shortestSpan( void ) const;
		unsigned int	longestSpan( void ) const;

		template<typename InputIterator>
		void insertNumbers(InputIterator begin, InputIterator end) {
			typename std::iterator_traits<InputIterator>::difference_type dist = std::distance(begin, end);

			if ((static_cast<unsigned int>(this->_storage.size()) + static_cast<unsigned int>(dist)) > this->_n)
				throw (SpanStorageIsFullException());
			this->_storage.insert(this->_storage.end(), begin, end);
		};

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