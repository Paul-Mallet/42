/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:45:16 by pamallet          #+#    #+#             */
/*   Updated: 2025/04/01 11:57:18 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_isspace(const char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_issign(const char c)
{
	return (c == '+' || c == '-');
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
