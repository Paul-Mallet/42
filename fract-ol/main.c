/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:44:51 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/08 19:24:44 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *img, unsigned int x, unsigned int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bits_per_pxl / 8));
	*(unsigned int *)dst = color;
}

int	ft_hextoi(char c, char *hex)
{
	int	i;

	i = -1;
	while (hex[++i])
	{
		if (hex[i] == c)
			return (i);
	}
	return (0);
}

int	ft_power(int nb, int power)
{
	int	i;
	int	res;

	if (power < 0)
		return (0);
	i = 0;
	res = 1;
	while (i < power)
	{
		res *= nb;
		i++;
	}
	return (res);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	pixel_put_gradient(t_img img, unsigned int it, unsigned int x, unsigned int y)
{
	int	i;
	int	j;
	int	clr1_i;
	int	clr2_i;

	i = ft_strlen(COLOR1) + 1;
	j = 0;
	clr1_i = 0;
	clr2_i = 0;
	if (it < (MAX_IT / 2)) //COLOR3(black) to COLOR1(red)
	{
		while (--i > 0)
		{
			clr1_i += ft_hextoi(COLOR1[i], "0123456789ABCDEF") * ft_power(16, j);
			clr2_i += ft_hextoi(COLOR3[i], "0123456789ABCDEF") * ft_power(16, j);
			j++;
		}
		//clr1_i = 16 711 680 = FF0000;
		//clr2_i = 0 = 000000;
		clr1_i = (((clr1_i + clr2_i) / 2) / (MAX_IT / 2)) * it;
	}
	else if ((it >= MAX_IT / 2) && (it <= MAX_IT - 1)) //COLOR1(red) to COLOR2(white)
	{
		while (--i > 0)
		{
			clr1_i += ft_hextoi(COLOR1[i], "0123456789ABCDEF") * ft_power(16, j);
			clr2_i += ft_hextoi(COLOR2[i], "0123456789ABCDEF") * ft_power(16, j);
			j++;
		}
		clr1_i = (((clr1_i + clr2_i) / 2) / (MAX_IT / 2)) * it; //it++ or it--(order)
	}
	else //COLOR3(black dft)
	{
		while (--i > 0)
		{
			clr1_i += ft_hextoi(COLOR3[i], "0123456789ABCDEF") * ft_power(16, j);
			j++;
		}
	}
	//printf("%d\n", clr1_i);
	my_mlx_pixel_put(&img, x, y, clr1_i);
}

void	fractol_sets(t_img img)
{
	t_set		s;
	unsigned int	is_in;
	unsigned int	i;

	s.re_min = -3.2;
	s.re_max = 1.0;
	s.im_min = -1.2;
	s.im_max = s.im_min + (s.re_max - s.re_min) * W_H/W_W;
	s.y = 0;
	while (s.y < W_H)
	{
		s.x = 0;
		s.c_im = s.im_max - (s.y * ((s.im_max - s.im_min) / (W_H - 1)));
		while (s.x < W_W)
		{
			s.c_re = s.re_min + (s.x * ((s.re_max - s.re_min) / (W_W - 1)));
			s.z_re = s.c_re;
			s.z_im = s.c_im;
			is_in = 1;
			i = 0;
			while (i < MAX_IT)
			{
				s.z_re2 = s.z_re * s.z_re;
				s.z_im2 = s.z_im * s.z_im;
				if (s.z_re2 + s.z_im2 > 4)
				{
					is_in = 0;
					break ;
				}
				s.z_im = (2*s.z_re*s.z_im) + s.c_im;
				s.z_re = (s.z_re2 - s.z_im2) + s.c_re;
				pixel_put_gradient(img, i, s.x, s.y);
				i++;
			}
			if (is_in)
				pixel_put_gradient(img, i, s.x, s.y); //black by dft
				//my_mlx_pixel_put(&img, s.x, s.y, 16777215);//white
			s.x++;
		}
		s.y++;
	}
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_img	img;

	if (ac == 2 && !is_valid_set(av[1])) //is_valid_color()?
	{
		mlx.mlx = mlx_init();
		if (!mlx.mlx)
		{
			printf("Mlx init error!");
			return (1);
		}
		mlx.mlx_win = mlx_new_window(mlx.mlx, W_W, W_H, "fract-ol");
		if (!mlx.mlx_win)
		{
			free(mlx.mlx_win);
			printf("Mlx window error!");
			return (1);
		}
		img.img = mlx_new_image(mlx.mlx, W_W, W_H);
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
		fractol_sets(img);
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
		printf("Invalid params!\n\nExamples :\n$>./fractol \"mandelbrot\" \"COLOR1=#FF0000\" \"COLOR2=#FFFFFF\"\n$>./fractol \"julia\" \"COLOR1=#00FFFF\" \"COLOR2=#FFFFFF\"\n");
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
