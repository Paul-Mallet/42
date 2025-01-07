/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:44:51 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/07 17:59:44 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *img, unsigned int x, unsigned int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bits_per_pxl / 8));
	*(unsigned int *)dst = color;
}

/*
 * Color gradients
 *
 * Black -> red: [0, 30/2 - 1] -> [0x00000000, 0x00FF0000]; +(12 * 15) * 2
 * Red -> white: [30/2, 30 - 1] -> [0x00FF0000, 0x00FFFFFF]; +(12 * 15) * 4
 * 
 * "FFFFFF" -> "000000" (hex conv int) 16777215 -> 0
 * "0123456789ABCDEF"
 * 16*16 = 256 = FF
 * 0x00 + FF + 0000
 */

void	fractol_sets(t_img img, unsigned int w, unsigned int h)
{
	t_set		set;
	unsigned int	x;
	unsigned int	y;
	unsigned int	is_in;
	unsigned int	i;

	y = 0;
	set.re_min = -3.2;
	set.re_max = 1.0;
	set.im_min = -1.2;
	set.im_max = set.im_min + (set.re_max - set.re_min) * h/w;
	while (y < h)
	{
		x = 0;
		set.c_im = set.im_max - (y * ((set.im_max - set.im_min) / (h - 1)));
		while (x < w)
		{
			set.c_re = set.re_min + (x * ((set.re_max - set.re_min) / (w - 1)));
			set.z_re = set.c_re;
			set.z_im = set.c_im;
			is_in = 1;
			i = 0;
			while (i < 30)
			{
				set.z_re2 = set.z_re * set.z_re;
				set.z_im2 = set.z_im * set.z_im;
				if (set.z_re2 + set.z_im2 > 4)
				{
					is_in = 0;
					break ;
				}
				set.z_im = (2*set.z_re*set.z_im) + set.c_im;
				set.z_re = (set.z_re2 - set.z_im2) + set.c_re;
				//...
				i++;
			}
			if (is_in)
				my_mlx_pixel_put(&img, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_img	img;

	if (ac == 2 && !is_valid_set(av[1]))
	{
		mlx.mlx = mlx_init();
		if (!mlx.mlx)
		{
			printf("Mlx init error!");
			return (1);
		}
		mlx.mlx_win = mlx_new_window(mlx.mlx, W_WIDTH, W_HEIGHT, "fract-ol");
		if (!mlx.mlx_win)
		{
			free(mlx.mlx_win);
			printf("Mlx window error!");
			return (1);
		}
		img.img = mlx_new_image(mlx.mlx, W_WIDTH, W_HEIGHT);
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
		fractol_sets(img, W_WIDTH, W_HEIGHT);
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, img.img, 0, 0);
		mlx_loop_hook(mlx.mlx, &handle_no_event, &mlx);
		mlx_hook(mlx.mlx_win, MotionNotify, PointerMotionMask, &pointer_hook, &mlx);
		mlx_hook(mlx.mlx_win, KeyPress, KeyPressMask, &close_esc_hook, &mlx);
		mlx_hook(mlx.mlx_win, DestroyNotify, 0, &close_cross_hook, &mlx);
		mlx_mouse_hook(mlx.mlx_win, &zoom_hook, &mlx);
		mlx_loop(mlx.mlx);
		mlx_destroy_display(mlx.mlx);
		free(mlx.mlx);
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
