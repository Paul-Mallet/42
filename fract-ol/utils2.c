/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:03:50 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/17 19:04:07 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_hextoi(char c, char *hex)
{
	int	i;

	i = -1;
	while (hex[++i])
	{
		if (hex[i] == c)
			return (i);
	}
	return (0);
}

int	ft_power(int nb, int power)
{
	int	i;
	int	res;

	if (power < 0)
		return (0);
	i = 0;
	res = 1;
	while (i < power)
	{
		res *= nb;
		i++;
	}
	return (res);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

double	ft_atodbl(char *s)
{
	double	bef;
	double	aft;
	double	pow;
	int		sign;

	bef = 0.0;
	aft = 0.0;
	pow = 1;
	sign = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	while (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		bef = (bef * 10) + (*s++ - 48);
	if (*s == '.')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		pow /= 10;
		aft = aft + (*s++ - 48) * pow;
	}
	return ((bef + aft) * sign);
}
