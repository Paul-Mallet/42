/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:55:20 by paul_mall         #+#    #+#             */
/*   Updated: 2025/01/21 16:25:49 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_overflow(int a, int b, int c)
{
	if (a > 0 && ((a * b + c) < 0))
		return (1);
	return (0);
}

int	is_underflow(int a, int b, int c)
{
	printf("%d\n", a);
	if (a < 0 && ((a * b + c) > 0))
		return (1);
	return (0);
}

int	ft_atoi(char *s)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	if (*s == '-')
	{
		sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		if (is_overflow(res, 10, (*s - 48)))
			handle_error(ERROR_MSG);
		if (is_underflow((res * -1), 10, (*s - 48))) //not - yet
			handle_error(ERROR_MSG);
		res = (res * 10) + (*s++ - 48);
	}
	return (res * sign);
}

int	is_duplicate(t_stack *stk, int n)
{
	int	i;

	i = 0;
	while (stk->arr[i])
	{
		if (stk->arr[i] == n)
			handle_error(ERROR_MSG);
		i++;
	}
	return (0);
}
