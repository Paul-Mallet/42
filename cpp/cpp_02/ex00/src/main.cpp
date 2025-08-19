/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 09:31:17 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/19 18:31:24 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

/*
	[ad-hoc] [polymorphism] = function/operator overloading = many diff function with same name(from same class), but diff params
	[1] -> for this purpose(in latin), created for a specific case, not following a general rule
	[2] -> polymorphism, transform in diff form
	ad-hoc = diff implemetations for each type combination
	diff polymorphism, parametric(templates), subtype(inheritances)
		ex:
			void Class::fun1( int n ) {...}
			void Class::fun1( char a ) {...}
			void Class::fun1( bool t ) {...}

	operator overload lead to prev one, define new operator
		infix operation: 1 + 1, cause of + operator between 2 operands(Math)
		+(1, 1) prefix notation, also functional notation
			ex:
				Integer &operator=( Integer const & rhs ) {...};
					also = to assignment operator
					(a = (b = (c = d...))) from right to left assignment, reason why ref &
				Integer operator+( Integer const & rhs ) const {...};
					1 + 2 + 3 + 4, no need to check the order, so return a copy
					overwrite + operator for this class only !!!
				overload ref to = bin ope with curr instance (this) as 1rst param, and ref to  as 2nd param
		rhs: right-hand side, the object being copied FROM(cause of this(1rst param) left hand side)
			 think as (left, right) chaining sides
			 (a = (b = (c = d...))) a left = b right(&rhs)
			 return Class( this->_attr + rhs.getAttr() ); not opti(because copy) but can't do it an other way
		[TODO...]
			ex:
				1.+( 1 ) = instance.func( param ) call
		1 + 1 infix =
		1 1 + postfix = stack calculation
		within Class -> operator keyword to declare operator mem_fun
		unary, binary(like: +, -, = etc. | ope on left, on right ex: ), ternary opes can be used

	canonical class form = coplain form in C
		see Fixed.hpp
*/
int main ( void )
{
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}