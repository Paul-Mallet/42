/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:44:51 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/17 19:05:19 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handle_err(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_set	set;

	if ((ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
		|| (ac == 4 && !ft_strcmp(av[1], "julia")))
	{
		set.name = av[1];
		if (!ft_strcmp(set.name, "julia"))
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
