/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 22:55:20 by paul_mall         #+#    #+#             */
/*   Updated: 2025/01/20 23:51:15 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *s)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	if (sign == '-')
	{
		sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		res = (res * 10) + (*s++ - 48);
	return (res * sign);
}

/* int	ft_quick_select(int *arr, int left, int right, int k) //median pivot */
/* { */
/* 	// */
/* } */

/* int	ft_hoare_partition(int *arr, int low, int high) //last index, smaller side */
/* { */
/* 	// */
/* } */
