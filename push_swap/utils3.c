/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:56:18 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/29 15:56:36 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_ints(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (is_space(*s))
			s++;
		if (!*s)
			break ;
		if (*s == '-')
			s++;
		while (is_digit(*s))
			s++;
		count++;
	}
	return (count);
}
