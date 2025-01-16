/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:44:51 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/17 00:10:05 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handle_error(void)
{
	perror("Malloc error!");
	exit(1);
}

static void	init_set(t_set *set)
{
	if (!ft_strncmp(set->name, "mandelbrot", 10))
		set->iterations = 30;
	set->out_value = 4;
	set->shift_x = 0.0;
	set->shift_y = 0.0;
	set->zoom = 1.0;
}

void	init(t_set *set)
{
	set->mlx.mlx_co = mlx_init();
	if (!set->mlx.mlx_co)
		handle_error();
	set->mlx.mlx_win = mlx_new_window(set->mlx.mlx_co,
			WIDTH, HEIGHT, set->name);
	if (!set->mlx.mlx_win)
	{
		mlx_destroy_display(set->mlx.mlx_co);
		free(set->mlx.mlx_co);
		handle_error();
	}
	set->img.img_ptr = mlx_new_image(set->mlx.mlx_co, WIDTH, HEIGHT);
	if (!set->img.img_ptr)
	{
		mlx_destroy_window(set->mlx.mlx_co, set->mlx.mlx_win);
		mlx_destroy_display(set->mlx.mlx_co);
		free(set->mlx.mlx_co);
		handle_error();
	}
	set->img.addr = mlx_get_data_addr(set->img.img_ptr,
			&set->img.bpp, &set->img.line_len, &set->img.endian);
	init_set(set);
}

int	main(int ac, char **av)
{
	t_set	set;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	{
		set.name = av[1];
		if (!ft_strncmp(set.name, "julia", 5))
		{
			set.iterations = 200;
			set.julia_x = ft_atodbl(av[2]);
			set.julia_y = ft_atodbl(av[3]);
		}
		init(&set);
		mlx_hook(set.mlx.mlx_win,
			DestroyNotify, StructureNotifyMask, &handle_close, &set);
		mlx_hook(set.mlx.mlx_win, KeyPress, KeyPressMask, &handle_keys,
			&set);
		mlx_hook(set.mlx.mlx_win, ButtonPress, ButtonPressMask, &handle_mouse,
			&set);
		render(&set);
		mlx_loop(set.mlx.mlx_co);
	}
	else
		printf("Ex:\n$>./fractol mandelbrot\n$>./fractol julia <r> <i>\n"); //!
	return (0);
}
