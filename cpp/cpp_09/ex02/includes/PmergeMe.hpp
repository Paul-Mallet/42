/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:13:17 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/02/14 11:39:01 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <vector>
# include <deque>
# include <algorithm>
# include <exception>
# include <cstdlib>
# include <limits>
# include <utility>
# include <cctype>
# include <typeinfo>
# include <sys/time.h>

class PmergeMe {

	private:
		std::vector<int>	_vectorNumbers;
		std::deque<int>		_dequeNumbers;
		double				_vectorChrono;
		double				_dequeChrono;
		bool				_isSorted;

	public:
		PmergeMe( void );
		PmergeMe( PmergeMe const & src );
		~PmergeMe();

		PmergeMe & operator=( PmergeMe const & rhs );

		std::vector<int>	getVectorNumbers( void ) const;
		std::deque<int>		getDequeNumbers( void ) const;
		double				getVectorChrono( void ) const;
		double				getDequeChrono( void ) const;
		bool				getSorted( void ) const;

		void				evaluate( int ac, char ** av );
		double				processTimeVector( void );
		double				processTimeDeque( void );
		void				fordJohnsonVector( std::vector<int> & numbers );
		void				fordJohnsonDeque( std::deque<int> & numbers );

		std::vector<int>	generateInsertionOrder( int n );

		void				display( std::vector<int> ctnr );
		void				displayVectorProcessTime( void );
		void				displayDequeProcessTime( void );

		class NotPositiveIntegerFoundException: public std::exception {
			public:
				virtual const char * what( void ) const throw();
		};
		class OverflowIntegerException: public std::exception {
			public:
				virtual const char * what( void ) const throw();
		};

};

std::ostream & operator<<( std::ostream & o, PmergeMe const & p );

#endif