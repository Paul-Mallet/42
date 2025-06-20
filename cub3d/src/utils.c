/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:38:43 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/20 17:34:25 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_ticks(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (EXIT_FAILURE);
	return (tv.tv_sec + tv.tv_usec / 1e6);
}

double	ft_abs(double dir)
{
	if (dir < 0)
		return (dir * -1);
	return (dir);
}

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(unsigned int *)dst = color;
}

double	my_clamped_formula(double (*formula)(double), double input)
{
	double	res;

	if (input > 1)
		input = 1.0;
	if (input < 1)
		input = -1.0;
	res = formula(input);
	return (res);
}
