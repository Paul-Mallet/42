/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:55:20 by paul_mall         #+#    #+#             */
/*   Updated: 2025/01/21 14:15:06 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//malloc? -> https://www.geeksforgeeks.org/check-for-integer-overflow/
int	is_overflow(int a, int b)
{
	return (a > 0 && (a + b < 0));
}

int	is_underflow(int a, int b)
{
	return (a < 0 && (a + b > 0));
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
		if (is_overflow((res * 10) + (*s - 48), 1))
			handle_error(ERROR_MSG);
		if (is_underflow((res * 10) + (*s - 48), -1))
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

/* int	ft_quick_select(int *arr, int left, int right, int k) //median pivot */
/* { */
/* 	// */
/* } */

/* int	ft_hoare_partition(int *arr, int low, int high) //last index, smaller side */
/* { */
/* 	// */
/* } */
