/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:28:37 by paul_mall         #+#    #+#             */
/*   Updated: 2025/01/21 22:26:10 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_ints(char *s)
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

static void	fill_stack(t_stack *stk, char **av)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (k < stk->len)
	{
		j = 0;
		while (av[i + 1][j])
		{
			while (is_space(av[i + 1][j]))
				j++;
			if (!is_overflow(&(av[i + 1])[j]) 
			&& !is_duplicate(stk, ft_atoi(&(av[i + 1])[j])))
				stk->arr[k] = ft_atoi(&(av[i + 1])[j]);
			if (av[i + 1][j] == '-')
				j++;
			while (is_digit(av[i + 1][j]))
				j++;
			k++;
		}
		i++;
	}
}

void	init_stack(t_stack *stk, char **av)
{
	int	i;

	i = 0;
	stk->len = 0;
	stk->arr = NULL;
	while (av[++i])
		stk->len += count_ints(av[i]);
	stk->arr = (int *)ft_calloc(stk->len, sizeof(int)); //calloc, free
	if (!stk->arr)
		handle_error(ERROR_MSG);
	fill_stack(stk, av);
}
