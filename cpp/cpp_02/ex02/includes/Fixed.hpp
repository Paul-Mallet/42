/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:48:49 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/20 11:58:39 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	
	public:
		Fixed( void );
		Fixed( int const value );
		Fixed( float const value );
		Fixed( Fixed const &src );
		~Fixed();

		Fixed &operator=( Fixed const &rhs );
		Fixed operator+( Fixed const &rhs ) const;

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		int		toInt( void ) const;
		float	toFloat( void ) const;

	private:
		int					_raw;
		static const int	_fracb;
};

std::ostream &operator<<( std::ostream &o, Fixed const &i );

#endif