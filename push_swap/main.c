/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:34:23 by paul_mall         #+#    #+#             */
/*   Updated: 2025/01/20 23:03:22 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_digits(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (is_space(*s))
			s++;
		if (*s == '-')
			s++;
		while (is_digit(*s))
			s++;
		count++;
	}
	return (count);
}

int	*ft_split(char **av)
{
	int	i;
	int	*arr;
	int	arr_len;

	i = 0;
	arr_len = 0;
	while (av[++i])
		arr_len += count_digits(av[i]);
	arr = (int *)malloc(arr_len * sizeof(int));
	if (!arr)
		return (NULL);
	//
	return (arr);
}

int	main(int ac, char **av)
{
	int	i;
	int	*arr;

	i = 0;
	arr = NULL;
	if (ac > 1)
	{
		/* init */
		while (av[++i]) //works on many str?(ask for)
			is_valid_input(av[i]);
		arr = ft_split(av); //start at 1 or 0?
		if (!arr)
			handle_error(ERROR_MSG);
	}
	return (0);
}
