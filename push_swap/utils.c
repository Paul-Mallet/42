/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:46:52 by paul_mall         #+#    #+#             */
/*   Updated: 2025/01/20 19:19:04 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(const char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	is_digit(const char c)
{
	return (c >= '0' && c <= '9');
}

int	is_valid_input(char *s)
{
	while (*s)
	{
		while (is_space(*s))
			s++;
		if (*s == '-')
			s++;
		if (!is_digit(*s))// || *s != '-')
			handle_error(ERROR_MSG);
		while (is_digit(*s))
			s++;
	}
	return (1);
}

void	handle_error(const char *s)
{
	while (*s)
		write(2, &*s++, 1);
	exit(1);
}

/* int	ft_quick_select(int *arr, int left, int right, int k) //median pivot */
/* { */
/* 	// */
/* } */

/* int	ft_hoare_partition(int *arr, int low, int high) //last index, smaller side */
/* { */
/* 	// */
/* } */
