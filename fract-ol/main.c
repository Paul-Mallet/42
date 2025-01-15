/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:07:41 by paul_mall         #+#    #+#             */
/*   Updated: 2025/01/15 16:48:14 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handle_error(void)
{
	ft_printf("Invalid params!\n\nExamples :\n$>./fractol \"mandelbrot\"\n$>./fractol \"julia\" <r> <i>\n");
}

static void	init(t_mlx *mlx, t_img *img)
{
	//init, new_window, new_img, events, fractal_init(data)(see 1rst part video)
	//implement fractal_render() at home
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_img	img;

	if ((ac == 2 && !strncmp(av[1], "mandelbrot", 10))
		|| ac == 4 && !strncmp(av[1], "julia", 5))
	{
		init(&mlx, &img);
		//fractal_render(); //frct.name
		mlx_loop(mlx.mlx_ptr);
	}
	else
		handle_error();
	return (0);
}
