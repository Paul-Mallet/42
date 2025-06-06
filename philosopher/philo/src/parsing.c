/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:26:41 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/06 17:51:59 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

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
			return (0);
		if (!ft_isdigit(*s))
			return (0);
		while (ft_isdigit(*s))
			s++;
	}
	return (1);
}

int	parsing(char **av)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (!ft_strlen(av[i]))
			return (handle_input_error(EMPTY_ERR));
		else if (is_only_spaces(av[i]))
			return (handle_input_error(SPACES_ERR));
		else if (!is_correct_digits(av[i]))
			return (handle_input_error(DIGITS_ERR));
		else if (!is_correct_sign(av[i]))
			return (handle_input_error(SIGN_ERR));
		else if (is_overflow(av[i]))
			return (handle_input_error(OVERFLOW_ERR));
	}
	return (SUCCESS);
}
