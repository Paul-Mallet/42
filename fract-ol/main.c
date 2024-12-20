/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:44:51 by pamallet          #+#    #+#             */
/*   Updated: 2024/12/20 18:44:34 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bits_per_pxl / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	/* t_data	img; */
	void	*img_load;
	char	*img_load_path;
	int	img_load_width;
	int	img_load_height;

	img_load_path = "./davidou.xpm";
	mlx = mlx_init();
	if (!mlx)
	{
		printf("Mlx init error!");
		return (0);
	}
	mlx_win = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, "fract-ol");
	if (!mlx_win)
	{
		free(mlx_win);
		printf("Mlx window error!");
		return (0);
	}
	img_load = mlx_xpm_file_to_image(mlx, img_load_path, &img_load_width, &img_load_height);
	if (!img_load)
	{
		printf("Image load error!");
		return (0);
	}
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
	/* mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0); */
	mlx_put_image_to_window(mlx, mlx_win, img_load, 0, 0);
	mlx_loop(mlx);
	return (0);
}
