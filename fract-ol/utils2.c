/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 00:17:03 by paul_mall         #+#    #+#             */
/*   Updated: 2025/01/17 00:25:05 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double uns_num,
		double n_min, double n_max, double o_min, double o_max)
{
	return ((n_max - n_min) * (uns_num - o_min) / (o_max - o_min) + n_min);
}

t_complex	sum_complex(t_complex c1, t_complex c2)
{
	t_complex	res;

	res.x = c1.x + c2.x;
	res.y = c1.y + c2.y;
	return (res);
}

t_complex	square_complex(t_complex c)
{
	t_complex	res;

	res.x = (c.x * c.x) - (c.y * c.y);
	res.y = 2 * c.x * c.y;
	return (res);
}
