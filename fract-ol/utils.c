/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:03:50 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/15 15:46:36 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

double	ft_atodbl(char *s)
{
	int		intg;
	double	fraction;
	double	pow;
	int		sign;

	intg = 0;
	fraction = 0;
	pow = 1;
	sign = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	while (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while ((*s >= '0' && *s <= '9') && *s != '.')
		intg = intg * 10 + (*s++ - 48);
	while (*++s >= '0' && *s <= '9')
	{
		pow /= 10;
		fraction += (*s - 48) * pow;
	}
	return ((intg + fraction) * sign);
}
