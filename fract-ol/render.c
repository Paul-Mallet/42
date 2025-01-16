/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:23:32 by paul_mall         #+#    #+#             */
/*   Updated: 2025/01/16 17:26:25 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_mlx_pixel_put(t_set *set, unsigned int x, unsigned int y, int color)
{
	char	*dst;

	dst = set->img.addr + (y * set->img.line_len + x * (set->img.bpp / 8));
	*(unsigned int *)dst = color;
}

static void	gradient(t_set *set, unsigned int it, unsigned int x, unsigned int y)
{
	int	i;
	int	j;
	int	clr_from;
	int	clr_to;

	i = ft_strlen(COLOR1);
	j = 0;
	clr_from = 0;
	clr_to = 0;
	if (it < (set->iterations / 2))
	{
		while (--i >= 0)
		{
			clr_from += ft_hextoi(COLOR3[i], "0123456789ABCDEF") * ft_power(16, j);
			clr_to += ft_hextoi(COLOR1[i], "0123456789ABCDEF") * ft_power(16, j);
			j++;
		}
		clr_from = clr_from + ((((clr_from - clr_to)) / (set->iterations / 2)) * it);
		if (clr_from < 0)
			clr_from *= -1;
	}
	else if ((it >= set->iterations / 2) && (it <= set->iterations - 1))
	{
		while (--i >= 0)
		{
			clr_from += ft_hextoi(COLOR1[i], "0123456789ABCDEF") * ft_power(16, j);
			clr_to += ft_hextoi(COLOR2[i], "0123456789ABCDEF") * ft_power(16, j);
			j++;
		}
		clr_from = clr_from + ((((clr_from - clr_to)) / (set->iterations / 2)) * it);
		if (clr_from < 0)
			clr_from *= -1;
	}
	/* else */
	/* { */
	/* 	while (--i > 0) */
	/* 	{ */
	/* 		clr_from += ft_hextoi(COLOR3[i], "0123456789ABCDEF") * ft_power(16, j); */
	/* 		j++; */
	/* 	} */
	/* } */
	my_mlx_pixel_put(set, x, y, clr_from);
}

void	draw_pixel(t_set *set, int x, int y)
{
	int	i;
	int	color;
	t_complex	z;
	t_complex	c;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = map(x, -2, 2, 0, WIDTH);
	c.y = map(y, 2, -2, 0, HEIGHT);
	/* printf("z.x: %f\nz.y: %f\n", set->z.x, set->z.y); */
	while (i < set->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > set->out_value)
		{
			/* gradient(set, i, x, y); */
			color = map(i, 0x000000, 0xFF0000, 0, set->iterations);
			my_mlx_pixel_put(set, x, y, 0x00FF00);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(set, x, y, 0x000000);
}

void	render(t_set *set)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			draw_pixel(set, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(set->mlx.mlx_co,
				set->mlx.mlx_win,
				set->img.img_ptr, 0, 0);
}
