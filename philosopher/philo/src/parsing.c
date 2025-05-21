/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:26:41 by pamallet          #+#    #+#             */
/*   Updated: 2025/05/21 11:24:48 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	handle_error(int status)
{
	if (status == EMPTY_ERR)
		printf("Invalid empty input.\n");
	else if (status == SPACES_ERR)
		printf("Invalid only spaces input.\n");
	else if (status == DIGITS_ERR)
		printf("Invalid digits format.\n");
	else if (status == SIGN_ERR)
		printf("Invalid sign, not handle.\n");
	else if (status == OVERFLOW_ERR)
		printf("Invalid type, only handle int.\n");
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
			return (0);
		if (!ft_isdigit(*s))
			return (0);
		while (ft_isdigit(*s))
			s++;
	}
	return (1);
}

void	parsing(char **av)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (!ft_strlen(av[i]))
			handle_input_error(EMPTY_ERR);
		else if (is_only_spaces(av[i]))
			handle_input_error(SPACES_ERR);
		else if (!is_correct_digits(av[i]))
			handle_input_error(DIGITS_ERR);
		else if (!is_correct_sign(av[i]))
			handle_input_error(SIGN_ERR);
		else if (is_overflow(av[i]))
			handle_input_error(OVERFLOW_ERR);
	}
}
