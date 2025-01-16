/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:44:51 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/16 13:01:55 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handle_error(void)
{
	perror("Malloc error!");
	exit(1); //EXIT_FAILURE
}

static void	init_set(t_set *set)
{
	set->iterations = 30;
	set->shift_x = 0.0;
	set->shift_y = 0.0;
	set->zoom = 1.0;
}

void	init(t_set *set)
{
	set->mlx.mlx_co = mlx_init();
	if (!set->mlx.mlx_co)
		handle_error();
	set->mlx.mlx_win = mlx_new_window(set->mlx.mlx_co, WIDTH, HEIGHT, set->name);
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
									 &set->img.bpp,
									 &set->img.line_len,
									 &set->img.endian);
	init_set(set);
}

int	main(int ac, char **av)
{
	t_set	set; //.. or ->.

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	{	
		set.name = av[1];
		init(&set);
		render(&set);

		/* mlx_hook(mlx.mlx_win, MotionNotify, PointerMotionMask, &pointer_hook, &mlx); */
		/* mlx_hook(mlx.mlx_win, KeyPress, KeyPressMask, &close_esc_hook, &mlx); */
		/* mlx_hook(mlx.mlx_win, DestroyNotify, 0, &close_cross_hook, &mlx); */
		/* mlx_mouse_hook(mlx.mlx_win, &zoom_hook, &mlx); */

		mlx_loop(set.mlx.mlx_co);
	}
	else
		printf("Invalid params!\n\nExamples :\n$>./fractol \"mandelbrot\"\n$>./fractol \"julia\" <r> <i>\n");
	return (0);
}
