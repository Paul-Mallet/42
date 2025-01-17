/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:44:51 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/17 11:47:36 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handle_err(char *str)
{
	perror(str);
	exit(1);
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
		mlx_hook(set.mlx.mlx_win,
			KeyPress, KeyPressMask, &handle_keys, &set);
		mlx_hook(set.mlx.mlx_win,
			ButtonPress, ButtonPressMask, &handle_mouse, &set);
		render(&set);
		mlx_loop(set.mlx.mlx_co);
	}
	else
		handle_err("Ex:\n$>./fractol mandelbrot\n$>./fractol julia <r> <i>\n");
	return (0);
}
