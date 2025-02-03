/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:46:52 by paul_mall         #+#    #+#             */
/*   Updated: 2025/02/03 17:36:47 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(const char *s)
{
	while (*s)
		write(2, &*s++, 1);
	exit(1);
}

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
	int	count;
	int	nb_ints;

	count = 0;
	nb_ints = count_ints(s);
	if (!ft_strlen(s))
		handle_error(ERROR_MSG);
	while (*s)
	{
		while (is_space(*s))
			s++;
		if (count == nb_ints)
			return (1);
		if (*s == '-')
			s++;
		if (!is_digit(*s))
			handle_error(ERROR_MSG);
		while (is_digit(*s))
			s++;
		count++;
	}
	return (1);
}
