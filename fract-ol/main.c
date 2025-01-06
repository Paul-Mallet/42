/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:44:51 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/06 19:03:38 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bits_per_pxl / 8));
	*(unsigned int *)dst = color;
}

void	fractol_sets(char *set, void *img, unsigned int w, unsigned int h)
{
	unsigned int	x;
	unsigned int	y;
	double		re_min; 
	double		re_max;
	double		im_min;
	double		im_max;
	double		c_re;
	double		c_im;
	double		z_re;
	double		z_im;
	double		z_re2;
	double		z_im2;
	unsigned int	is_in;
	int	max_i;

	if (is_valid_set(set))
	{
		printf("Invalid params!\n\nExamples :\n$>./fractol \"mandelbrot\" \"2\" \"0.5\"\n$>./fractol \"julia\" \"1.95\" \"1\"\n");
		return ;
	}
	re_min = -2.0;
	re_max = 1.0;
	im_min = -1.2;
	im_max = im_min + (re_max - re_min) * h/w;
	y = 0;
	while (y < h)
	{
		x = 0;
		c_im = im_max - (y * ((im_max - im_min) / (h - 1)));
		while (x < w)
		{
			c_re = re_min + (x * ((re_max - re_min) / (w - 1)));
			z_re = c_re;
			z_im = c_im;
			is_in = 1;
			while (0 < max_i) //?
			{
				z_re2 = z_re * z_re;
				z_im2 = z_im * z_im;
				if (z_re2 + z_im2 > 4)
				{
					is_in = 0;
					break ;
				}
				z_re = (z_re2 - z_im2) + c_re;
				z_im = (2 * z_re * z_im) + c_im;
				max_i--;
			}
			if (is_in)
				my_mlx_pixel_put(img, x, y, 0x0000FF00);
			x++;
		}
		y++;
	}
}

int	main(int ac, char **av)
{
	t_vars	vars;
	t_data	img; //t_img

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

		fractol_sets(av[1], img.img, W_WIDTH, W_HEIGHT);

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
 *
 *
 * void	*img_ld;
 * char	*img_ld_path;
 * int	img_ld_w;
 * int	img_ld_h;
 * img_ld_path = "./davidou.xpm";
 * img_ld = mlx_xpm_file_to_image(vars.mlx, img_ld_path, &img_ld_w, &img_ld_h);
 * if (!img_ld)
 * {
 * 	printf("Image load error!");
 * 	return (0);
 * }
 * mlx_put_image_to_window(vars.mlx, vars.mlx_win, img_ld, 0, 0);
 */
