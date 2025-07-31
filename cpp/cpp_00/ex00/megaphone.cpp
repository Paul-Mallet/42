/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:13:21 by pamallet          #+#    #+#             */
/*   Updated: 2025/07/31 15:32:36 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> //iostream
#include <cctype> //char approach with toupper
using std::cout;

//namespace not good, don't know if my cout or the std::cout
//string + transform, work seamlessly together(as standard)

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
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
}