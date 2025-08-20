/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 09:57:20 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/20 09:38:08 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

/*
	public:
		parameterized constructor //canonical
		default constructor
		copy constructor //canonical
			do have an instance, create NEW object copy based on &src, Fixed b = a;
		destructor //canonical
			~ -> virtual keyword (see later)

		cp assignment operator overload //canonical(update of curr instance, call when Fixed b = a;)
			modif EXISTING object(instance, b = a, where b already exist due to refs)

	std::ostream &operator<<(std::ostream &o, Fixed const &i);
		!!! used to serialized the Class into a string to be able to output it !!!
		=> use for debugging
		ex: std::cout << instance1 << instance2 << std::endl;
		stream insertion operator(not member, but global function)
		1. allows chaining std::cout << f1 << f2...
		2. return std::ostream &: perf by returning ref to same output stream
*/
class Fixed {

	public:
		Fixed( void );
		Fixed( Fixed const &src);
		~Fixed();

		Fixed &operator=( Fixed const &rhs );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int 				_raw;
		static const int	_fracb;

};

#endif