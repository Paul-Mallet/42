/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:28:37 by paul_mall         #+#    #+#             */
/*   Updated: 2025/01/21 19:12:14 by pamallet         ###   ########.fr       */
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

void	init_stack(t_stack *stk, char **av)
{
	int	i;
	int	j;

	i = 0;
	stk->arr = NULL;
	stk->len = 0;
	while (av[++i])
		stk->len += count_ints(av[i]);
	stk->arr = (int *)malloc(stk->len * sizeof(int)); //free
	if (!stk->arr)
		handle_error(ERROR_MSG);
	i = 0;
	while (i < stk->len)
	{
		j = 0;
		while (av[i + 1][j])
		{
			while (is_space(av[i + 1][j]))
				j++;
			if (!is_overflow(&(av[i + 1])[j]) 
			&& !is_duplicate(stk, ft_atoi(&(av[i + 1])[j])))
				stk->arr[i] = ft_atoi(&(av[i + 1])[j]);
			while (is_digit(av[i + 1][j]))
				j++;
		}
		i++;
	}
}
