/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:58:12 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/13 18:29:00 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

// unit tests
int	main( int ac, char **av )
{
	if (ac < 1 || ac > 2)
		return (1);
	(void)av;

	char c = 'a';

	if (ft_isalpha(c))
		printf("%c is alpha, youhou !\n", c);
	printf("ft_atoi: %d\n", ft_atoi(av[1]));
	return (0);
}