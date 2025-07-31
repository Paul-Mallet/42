/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:13:21 by pamallet          #+#    #+#             */
/*   Updated: 2025/07/31 16:01:10 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

using std::cout;
namespace MyNamespace {
	int value = 42;
	namespace MyInnerNamespace {
		void function() { cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n"; }
	}
}

// using: like import in other languages
// namespace: like struct in C, interfaces in TS
// iostream: standard input/output stream objects
// cctype: to classify / transform individual char
int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac > 1)
	{
		while (av[++i])
		{
			j = -1;
			while (av[i][++j])
				av[i][j] = toupper(av[i][j]);
			cout << av[i];
		}
		cout << "\n";
	}
	else
		MyNamespace::MyInnerNamespace::function();
	return (0);
}
