/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:23:07 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/26 16:03:20 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"
#include <typeinfo>

int main( int ac, char** av )
{
	if (ac != 1)
		return (1);
	(void)av;

	unsigned const int	len = 3;
	float			arrf[] = { 42.0f, 24.0f, -35.f };
	float const		arrfc[] = { 42.0f, 24.0f, -35.f };

	::iter(arrf, len, ::print<float>);
	// ::iter(arrfc, len, ::print<float>);
	::iter(arrfc, len, ::print<const float>);

	::iter(arrf, len, ::add_two<float>);

	::iter(arrf, len, ::print<float>);

	for (unsigned int i = 0; i < len; ++i)
		std::cout << typeid(arrf[i]).name() << std::endl;

	return (0);
}