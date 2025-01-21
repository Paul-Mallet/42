/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:55:20 by paul_mall         #+#    #+#             */
/*   Updated: 2025/01/21 17:23:35 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_overflow(char *s)
{
	long	res;
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
		res *= 10;
		if ((res * sign) < -2147483648 || (res * sign) > INT_MAX)
			handle_error(ERROR_MSG);
		res += (*s++ - 48);
		if ((res * sign) < -2147483648 || (res * sign) > INT_MAX)
			handle_error(ERROR_MSG);
	}
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
		res = (res * 10) + (*s++ - 48);
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
