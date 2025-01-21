/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:28:37 by paul_mall         #+#    #+#             */
/*   Updated: 2025/01/21 12:24:30 by paul_mall        ###   ########.fr       */
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

void	init_stack(t_stack *stk, char **av)
{
	int	i;

	i = 0;
	stk->arr = NULL;
	stk->len = 0;
	while (av[++i])
		stk->len += count_digits(av[i]);
	stk->arr = (int *)malloc(stk->len * sizeof(int)); //free
	if (!stk->arr)
		handle_error(ERROR_MSG);
	i = -1;
	while (++i < stk->len)
	{
		if (!is_duplicate(stk, ft_atoi(av[i + 1])))
			stk->arr[i] = ft_atoi(av[i + 1]); //not working on "42 ...", TODO
	}
}
