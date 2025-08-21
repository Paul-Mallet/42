/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:48:49 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/21 17:04:05 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Point;

class Fixed {

	public:
		Fixed( void );
		Fixed( int const value );
		Fixed( float const value );
		Fixed( Fixed const &src );
		~Fixed();

		Fixed	&operator=( Fixed const &rhs );
		bool	operator>( Fixed const &rhs ) const;
		bool	operator<( Fixed const &rhs ) const;
		bool	operator>=( Fixed const &rhs ) const;
		bool	operator<=( Fixed const &rhs ) const;
		bool	operator==( Fixed const &rhs ) const;
		bool	operator!=( Fixed const &rhs ) const;

		Fixed	operator+( Fixed const &rhs ) const;
		Fixed 	operator-( Fixed const &rhs ) const;
		Fixed	operator*( Fixed const &rhs ) const;
		Fixed	operator/( Fixed const &rhs ) const;

		Fixed	&operator++( void );
		Fixed	operator++( int );
		Fixed	&operator--( void );
		Fixed	operator--( int );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		int		toInt( void ) const;
		float	toFloat( void ) const;
		
		static	Fixed &min( Fixed &raw1, Fixed &raw2 );
		static	Fixed const &min( Fixed const &raw1, Fixed const &raw2 );
		static	Fixed &max( Fixed &raw1, Fixed &raw2 );
		static	Fixed const &max( Fixed const &raw1, Fixed const &raw2 );
		
	private:
		int					_raw;
		static const int	_fracb;

};
	
std::ostream	&operator<<( std::ostream &o, Fixed const &i );
bool			bsp( Point const a, Point const b, Point const c, Point const point);

#endif