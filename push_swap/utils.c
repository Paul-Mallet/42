/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:46:52 by paul_mall         #+#    #+#             */
/*   Updated: 2025/01/20 14:12:00 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	write(1, "\n", 1);
}

/* int	ft_quick_select(int *arr, int left, int right, int k) //median pivot */
/* { */
/* 	// */
/* } */

/* int	ft_partition(int *arr, int low, int high) //last index, smaller side */
/* { */
/* 	// */
/* } */
