/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:07:41 by paul_mall         #+#    #+#             */
/*   Updated: 2025/01/15 19:07:12 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	error_msg(void)
{
	printf("$>./fractol \"mandelbrot\"\n$>./fractol \"julia\" <r> <i>\n");
}

static void	init(t_mlx *mlx, t_img *img, t_fractal *set)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (error_msg());
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, set->name);
	if (!mlx->mlx_win)
		return (mlx_destroy_display(mlx->mlx_ptr),
			free(mlx->mlx_ptr),
			error_msg());
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	if (!img->img_ptr)
		return (mlx_destroy_display(mlx->mlx_ptr),
			mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win),
			free(mlx->mlx_ptr),
			error_msg());
	handle_events(mlx, set);
	//init_fractal();
}

int	main(int ac, char **av)
{
	t_mlx		mlx;
	t_img		img;
	t_fractal	set;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	{
		set.name = av[1];
		init(&mlx, &img, &set);
		//render(); //frct.name
		mlx_loop(mlx.mlx_ptr);
	}
	else
		error_msg();
	return (0);
}
