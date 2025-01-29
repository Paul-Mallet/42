/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:28:37 by paul_mall         #+#    #+#             */
/*   Updated: 2025/01/29 17:30:21 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	bubble_sort(t_stack *stk)
{
	int	i;
	int	j;

	i = 0;
	while (i < stk->len)
	{
		j = 0;
		while (j < stk->len - 1)
		{
			if (stk->arr[j] > stk->arr[j + 1])
				ft_swap(&stk->arr[j], &stk->arr[j + 1]);
			j++;
		}
		i++;
	}
}

void	fill_stack(t_stack *stk, char **av)
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
			if (av[i + 1][j] && !is_overflow(&(av[i + 1])[j])
				&& !is_duplicate(stk, k, ft_atoi(&(av[i + 1])[j])))
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

void	refill_stack(t_stack *stk, t_stack *cpy)
{
	int	i;
	int	j;

	i = 0;
	while (i < stk->len)
	{
		j = 0;
		while (j < stk->len)
		{
			if (stk->arr[i] == cpy->arr[j])
			{
				stk->arr[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	init_stack(t_stack *stk, char **av, char name)
{
	int	i;

	i = 0;
	stk->name = name;
	stk->len = 0;
	stk->arr = NULL;
	stk->capacity = 0;
	while (av[++i])
		stk->capacity += count_ints(av[i]);
	if (stk->name == 'a' || stk->name == 'c')
		stk->len = stk->capacity;
	stk->arr = (int *)ft_calloc(stk->capacity, sizeof(int)); //free
	if (!stk->arr)
		handle_error(ERROR_MSG);
}
