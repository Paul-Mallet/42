/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:46:52 by paul_mall         #+#    #+#             */
/*   Updated: 2025/01/23 13:05:08 by paul_mall        ###   ########.fr       */
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

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	is_valid_input(char *s)
{
	if (!ft_strlen(s))
		handle_error(ERROR_MSG);
	while (*s)
	{
		while (is_space(*s))
			s++;
		if (*s == '-')
			s++;
		if (!is_digit(*s) || (*s == '0' && is_digit(*(s + 1))))
			handle_error(ERROR_MSG);
		while (is_digit(*s))
			s++;
	}
	return (1);
}
