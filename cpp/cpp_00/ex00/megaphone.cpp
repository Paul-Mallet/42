/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:13:21 by pamallet          #+#    #+#             */
/*   Updated: 2025/07/30 18:03:05 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> //iostream
#include <cctype> //char approach with toupper
using namespace std; //namespace

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac > 1)
	{
		while (av[i])
			//string + transform, work seamlessly together(as standard)
		cout << "\n";
	}
	else
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
}