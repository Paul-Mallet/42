/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 10:27:43 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/25 15:10:40 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template< typename T >
void swap( T& a, T& b )
{
	T swap;
	swap = a;
	a = b;
	b = swap;
}

template< class C >
C& min( C& a, C& b )
{
	if (a < b)
		return (a);
	return (b);
}

template<class T>
T& max( T& a, T& b )
{
	if (a > b)
		return (a);
	return (b);
}

#endif