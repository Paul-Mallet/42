/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:23:32 by paul_mall         #+#    #+#             */
/*   Updated: 2025/01/17 19:07:28 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	*from_to_values(t_set *set, char *clr_1, char *clr_2)
{
	int	i;
	int	j;

	i = ft_strlen(CLR_1);
	j = 0;
	set->from_to[0] = 0;
	set->from_to[1] = 0;
	while (--i >= 0)
	{
		set->from_to[0] += ft_hextoi(clr_1[i], HEXA_STR) * ft_power(16, j);
		set->from_to[1] += ft_hextoi(clr_2[i], HEXA_STR) * ft_power(16, j++);
	}
	return (set->from_to);
}

static void	gradient(t_set *set, int it, int x, int y)
{
	int	color;

	if (it < (set->iterations / 2))
		set->from_to = from_to_values(set, CLR_3, CLR_1);
	else
		set->from_to = from_to_values(set, CLR_1, CLR_2);
	color = set->from_to[0] + (((set->from_to[0] - set->from_to[1]) / 15) * it);
	if (color < 0)
		color *= -1;
	my_mlx_pixel_put(set, x, y, color);
}

static void	choose_set(t_set *set)
{
	if (!ft_strcmp(set->name, "julia"))
	{
		set->c.x = set->julia_x;
		set->c.y = set->julia_y;
	}
	else
	{
		set->c.x = set->z.x;
		set->c.y = set->z.y;
	}
}

static void	draw_pixel(t_set *set, int x, int y)
{
	int	i;

	i = 0;
	set->z.x = (resize(x, -2, 2, WIDTH) * set->zoom) + set->shift_x;
	set->z.y = (resize(y, 2, -2, HEIGHT) * set->zoom) + set->shift_y;
	choose_set(set);
	while (i < set->iterations)
	{
		set->z = sum_complex(square_complex(set->z), set->c);
		if ((set->z.x * set->z.x) + (set->z.y * set->z.y) > set->out_value)
		{
			gradient(set, i, x, y);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(set, x, y, CLR_NOT_IN_SET);
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
