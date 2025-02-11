/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:03:50 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/18 12:21:03 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	parse_sign(char *s, int i)
{
	int	sign;

	sign = 1;
	while (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	return (sign);
}

static int	skip_signs(char *s, int i)
{
	while (s[i] == '+' || s[i] == '-')
		i++;
	return (i);
}

double	ft_atodbl(char *s)
{
	t_double	dbl;
	int			i;

	dbl.bef = 0.0;
	dbl.aft = 0.0;
	dbl.pow = 1;
	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	dbl.sign = parse_sign(s, i);
	i = skip_signs(s, i);
	while (s[i] >= '0' && s[i] <= '9')
	{
		dbl.bef = (dbl.bef * 10) + (s[i] - 48);
		i++;
	}
	if (s[i] == '.')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		dbl.pow /= 10;
		dbl.aft = dbl.aft + (s[i] - 48) * dbl.pow;
		i++;
	}
	return ((dbl.bef + dbl.aft) * dbl.sign);
}

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
