/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:13:21 by pamallet          #+#    #+#             */
/*   Updated: 2025/08/05 11:12:13 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*
	using namespace: (not allowed !) using = like import struct in C, 
	ex:
		namespace MyNamespace {
			int value = 42;
			void myFunction( void ) {
				std::cout << "My Function !" << std::endl;
			}
		}
		namespace MyNamespace2 {
			namespace MyInnerNamespace {
				int valueInner = 24;
				void myInnerFunction( void ) {
					std::cout << "My Inner Function !" << std::endl;
				}
			}
		}
		MyNamespace3 = Mynamespace2::MyInnerNamespace;
		MyNamespace3::myInnerFunction(); " output: "My Function !\n" "
	'::': scope resolution operator, access global / member attributes(states) & functions(behaviors)
	<iostream>: standard input/output stream objects
	stream: is an abstraction that represents a device on which input/ouput operations are performed,
		stream can basically be represented as a src/dest of chars of indefinite length
		ex: disk file, the keyboard, or the console where are physically input/output
	narrow-oriented objects: cin, cout, cerr, clog
	wide-oriented objects: wcin, wcout, wcerr, wclog
	'>>': (extraction operator) redirect to, to a buffer with enough capacity
	'<<': (insertion operator) redirect in
	std::endl: allow to write '\n' in any OS(cause Linux way differs from Windows etc.)
	<locale>: local zone based, 6 facets for 6 diff purposes(ctype -> chars manip)
	<string>: object of char[N] with methods to manip it
*/
int	main(int ac, char **av)
{
	int i = 0;
	std::locale loc;
	std::string str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	if (ac < 2)
		std::cout << str << std::endl;
	else
	{
		while (av[++i])
		{
			str = av[i];
			for (std::string::iterator it = str.begin(); it != str.end(); ++it)
				*it = std::toupper(*it, loc);
			std::cout << str;
		}
		std::cout << std::endl;
	}
	return (0);
}
