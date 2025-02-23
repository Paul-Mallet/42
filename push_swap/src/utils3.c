/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:56:18 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/23 11:52:42 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_poten_error(char *str, t_data *data, t_stack *stk, int k)
{
	if (is_overflow(str) || is_duplicate(stk, k, ft_atoi(str)))
	{
		free_stacks(data);
		handle_error(ERROR_MSG);
		return (1);
	}
	return (0);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int	count_ints(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (ft_isspace(*s))
			s++;
		if (!*s)
			break ;
		if (ft_issign(*s))
			s++;
		while (ft_isdigit(*s))
			s++;
		count++;
	}
	return (count);
}

int	optimal_count(int count, int count2)
{
	if (count2 < count)
		return (count + 0);
	else
		return (0 + count2);
}

int	above_bigger(t_stack *b)
{
	int	i;
	int	big_i;
	int	bigger;

	i = 0;
	big_i = 0;
	bigger = 0;
	while (i < b->len)
	{
		if (b->arr[i] > bigger)
		{
			bigger = b->arr[i];
			big_i = i;
		}
		i++;
	}
	return (big_i);
}
