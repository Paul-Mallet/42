/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:44:51 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/04 16:06:41 by pamallet         ###   ########.fr       */
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

int	pointer_hook(int x, int y)
{
	printf("Pointer position: (%d,%d)\n", x, y);
	return (0);
}

int	close_esc_hook(int key_sym, t_vars *vars)
{
	if (key_sym == XK_Escape)
		mlx_destroy_window(vars->mlx, vars->mlx_win);
	printf("ESC key pressed: %d\n", key_sym);
	return (0);
}

int	zoom_hook(int button)
{
	if (button == Button4)
		printf("Zoom in: %d\n", button);
	else if (button == Button5)
		printf("Zoom out: %d\n", button);
	return (0);
}

int	close_cross_hook(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	printf("Cross clicked\n");
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	t_data	img;
	/* void	*img_ld; */
	/* char	*img_ld_path; */
	/* int	img_ld_w; */
	/* int	img_ld_h; */
	/* img_ld_path = "./davidou.xpm"; */

	/* img_ld = mlx_xpm_file_to_image(vars.mlx, img_ld_path, &img_ld_w, &img_ld_h); */
	/* if (!img_ld) */
	/* { */
	/* 	printf("Image load error!"); */
	/* 	return (0); */
	/* } */

	/* mlx_put_image_to_window(vars.mlx, vars.mlx_win, img_ld, 0, 0); */
	if (ac > 1)
	{
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
		img.img = mlx_new_image(vars.mlx, W_WIDTH, W_HEIGHT);
		if (!img.img)
		{
			free(img.img);
			printf("Image error!");
			return (0);
		}
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pxl, &img.line_len, &img.endian);
		if (!img.addr)
		{
			printf("Image address error!");
			return (0);
		}
		//Sets
		(void)av;
		/* fractal_set(av[1], av[2], av[3]); //(set, C, i) */
		my_mlx_pixel_put(&img, 5, 50, 0x0000FF00);

		mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);

		mlx_loop_hook(vars.mlx, &handle_no_event, &vars);
		mlx_hook(vars.mlx_win, MotionNotify, PointerMotionMask, &pointer_hook, &vars);
		mlx_hook(vars.mlx_win, KeyPress, KeyPressMask, &close_esc_hook, &vars);
		mlx_hook(vars.mlx_win, DestroyNotify, 0, &close_cross_hook, &vars);
		mlx_mouse_hook(vars.mlx_win, &zoom_hook, &vars);

		mlx_loop(vars.mlx);

		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
	}
	else
		printf("Invalid params!\n\nExamples :\n$>./fractol \"mandelbrot\" \"2\" \"0.5\"\n$>./fractol \"julia\" \"1.95\" \"1\"\n");
	return (0);
}

/*
 * Implement Mandelbrot's Set*, Julia's Set**
 * Implement fractal_set(char *set, )Change Julia sets via params
 * Few colors, show fractal's depth(psychedelic effect)
 *
 *
 * KeySyms -> offer consistent key's action/symbol accross platforms
 * Mandelbrot's Set
 * pixel coord = complex nb(i)
 * color according to Mandelbrot or not
 * 2 approaches:
 * 	4 pxls des 4 coins de l'img, interpolate in-between pxls
 * But same problem for both!
 */
