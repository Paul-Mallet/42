/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:44:51 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/02 17:56:41 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bits_per_pxl / 8));
	*(unsigned int *)dst = color;
}

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}

int	close_press(int keysym, t_vars *vars)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(vars->mlx, vars->mlx_win);
	printf("Keypress: %d\n", keysym);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	/* t_data	img; */
	/* void	*img_load; */
	/* char	*img_load_path; */
	/* int	img_load_width; */
	/* int	img_load_height; */

	/* img_load_path = "./davidou.xpm"; */
	vars.mlx = mlx_init();
	if (!vars.mlx)
	{
		printf("Mlx init error!");
		return (1);
	}
	vars.mlx_win = mlx_new_window(vars.mlx, W_WIDTH, W_HEIGHT, "fract-ol");
	if (!vars.mlx_win)
	{
		free(vars.mlx_win);
		printf("Mlx window error!");
		return (1);
	}
	/* img_load = mlx_xpm_file_to_image(vars.mlx, img_load_path, &img_load_width, &img_load_height); */
	/* if (!img_load) */
	/* { */
	/* 	printf("Image load error!"); */
	/* 	return (0); */
	/* } */
	/* img.img = mlx_new_image(mlx, W_WIDTH, W_HEIGHT); */
	/* if (!img.img) */
	/* { */
	/* 	free(img.img); */
	/* 	printf("Image error!"); */
	/* 	return (0); */
	/* } */
	/* img.addr = mlx_get_data_addr(img.img, &img.bits_per_pxl, &img.line_len, &img.endian); */
	/* if (!img.addr) */
	/* { */
	/* 	printf("Image address error!"); */
	/* 	return (0); */
	/* } */
	/* my_mlx_pixel_put(&img, 5, 50, 0x00FF0000); */
	/* mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0); */
	/* mlx_put_image_to_window(vars.mlx, vars.mlx_win, img_load, 0, 0); */
	/* mlx_hook(vars.mlx_win, KeyRelease, KeyReleaseMask, &close_release, &vars); */

	mlx_loop_hook(vars.mlx, &handle_no_event, &vars);
	mlx_hook(vars.mlx_win, KeyPress, KeyPressMask, &close_press, &vars);

	mlx_loop(vars.mlx);

	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	return (0);
}
/*
 * Mouse wheel zooms in/out
 * Mouse position on screen
 * Change Julia sets via params
 * Few colors, show fractal's depth
 * ESC close window + quit prog in clean way
 * Click on cross on inside window close window + quit prog
 */
