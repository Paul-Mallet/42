/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:52:34 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/21 20:51:32 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {

	public:
		Point( void );
		Point( float const x, float const y );
		Point( Point const &src );
		~Point();

		Point &operator=( Point const &rhs );

		Fixed getX( void ) const;
		Fixed getY( void ) const;

	private:
		Fixed const _x;
		Fixed const _y;

};

#endif