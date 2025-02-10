/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:46:52 by paul_mall         #+#    #+#             */
/*   Updated: 2025/02/10 18:17:47 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(const char *s)
{
	while (*s)
		write(2, &*s++, 1);
	exit(1);
}

int	is_only_spaces(const char *s)
{
	while (*s)
	{
		if (!ft_isspace(*s))
			return (0);
		s++;
	}
	return (1);
}

int	is_correct_digits(const char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (!ft_isdigit(s[i]) && !ft_isspace(s[i]) && !ft_issign(s[i]))
			return (0);
	}
	return (1);
}

int	is_correct_sign(const char *s)
{
	while (*s)
	{
		while (ft_isspace(*s) && *s)
			s++;
		if (!*s)
			return (1);
		if (ft_issign(*s))
			s++;
		if (!ft_isdigit(*s))
			return (0);
		while (ft_isdigit(*s))
			s++;
	}
	return (1);
}

int	is_valid_input(char *s)
{
	if (!ft_strlen(s))
		handle_error(ERROR_MSG);
	if (is_only_spaces(s))
		handle_error(ERROR_MSG);
	if (!is_correct_digits(s))
		handle_error(ERROR_MSG);
	if (!is_correct_sign(s))
		handle_error(ERROR_MSG);
	return (1);
}
