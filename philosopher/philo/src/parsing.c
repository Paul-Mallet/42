/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:26:41 by pamallet          #+#    #+#             */
/*   Updated: 2025/04/02 15:33:31 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	handle_error(int status)
{
	if (status == EMPTY_INPUT_ERR)
		printf("Invalid empty input.\n");
	else if (status == ONLY_SPACES_ERR)
		printf("Invalid only spaces input.\n");
	else if (status == INVALID_DIGITS_ERR)
		printf("Invalid digits format.\n");
	else if (status == INVALID_SIGN_ERR)
		printf("Invalid sign, not handle.\n");
	else if (status == INVALID_OVERF_ERR)
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

int	parsing(char **av)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (!ft_strlen(av[i]))
			handle_error(EMPTY_INPUT_ERR);
		else if (is_only_spaces(av[i]))
			handle_error(ONLY_SPACES_ERR);
		else if (!is_correct_digits(av[i]))
			handle_error(INVALID_DIGITS_ERR);
		else if (!is_correct_sign(av[i]))
			handle_error(INVALID_SIGN_ERR);
		else if (is_overflow(av[i]))
			handle_error(INVALID_OVERF_ERR);
		if (!ft_strlen(av[i]) || is_only_spaces(av[i])
			|| !is_correct_digits(av[i]) || !is_correct_sign(av[i]))
			return (0);
	}
	return (1);
}
