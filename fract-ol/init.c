/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:36:24 by paul_mall         #+#    #+#             */
/*   Updated: 2025/01/17 12:23:27 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handle_err(char *str)
{
	perror(str);
	exit(1);
}

static void	init_set(t_set *set)
{
	if (!ft_strncmp(set->name, "mandelbrot", 10))
		set->iterations = 30;
	set->out_value = 4;
	set->from_to = NULL;
	if (!set->from_to)
	{
		set->from_to = (int *)ft_calloc(2, 2 * sizeof(int));
		if (!set->from_to)
		{
			perror("Calloc error.");
			exit (1);
		}
	}
	set->shift_x = 0.0;
	set->shift_y = 0.0;
	set->zoom = 1.0;
}

void	init(t_set *set)
{
	set->mlx.mlx_co = mlx_init();
	if (!set->mlx.mlx_co)
		handle_err("Malloc error.");
	set->mlx.mlx_win = mlx_new_window(set->mlx.mlx_co,
			WIDTH, HEIGHT, set->name);
	if (!set->mlx.mlx_win)
	{
		mlx_destroy_display(set->mlx.mlx_co);
		free(set->mlx.mlx_co);
		handle_err("Malloc error.");
	}
	set->img.img_ptr = mlx_new_image(set->mlx.mlx_co, WIDTH, HEIGHT);
	if (!set->img.img_ptr)
	{
		mlx_destroy_window(set->mlx.mlx_co, set->mlx.mlx_win);
		mlx_destroy_display(set->mlx.mlx_co);
		free(set->mlx.mlx_co);
		handle_err("Malloc error.");
	}
	set->img.addr = mlx_get_data_addr(set->img.img_ptr,
			&set->img.bpp, &set->img.line_len, &set->img.endian);
	init_set(set);
}
