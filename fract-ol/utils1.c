/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 00:17:03 by paul_mall         #+#    #+#             */
/*   Updated: 2025/01/17 12:26:48 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*arr;
	size_t			i;

	arr = (unsigned char *)malloc(nmemb * size);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		arr[i++] = '\0';
	return (arr);
}

void	my_mlx_pixel_put(t_set *set, int x, int y, int color)
{
	char	*dst;

	dst = set->img.addr + (y * set->img.line_len + x * (set->img.bpp / 8));
	*(unsigned int *)dst = color;
}

double	resize(double unsc_n, double n_min, double n_max, double prv_max)
{
	double	prv_min;

	prv_min = 0;
	return ((n_max - n_min) * (unsc_n - prv_min) / (prv_max - prv_min) + n_min);
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
