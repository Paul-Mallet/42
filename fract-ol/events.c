/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:42:53 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/15 19:18:37 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	handle_close(t_mlx *mlx, t_img *img)
{
	(void)img;
	/* mlx_destroy_image(mlx->mlx_ptr, img->img_ptr); */
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win); //only this on seg fault?
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	printf("Successfully closed!\n");
	return (0);
}

static int	handle_keys(int key_sym, t_mlx *mlx, t_img *img, t_fractal *fractal)
{
	(void)fractal;
	if (key_sym == XK_Escape)
		handle_close(mlx, img);
/* 	else if (key_sym == XK_Up) */
/* 		// */
/* 	else if (key_sym == XK_Down) */
/* 		// */
/* 	else if (key_sym == XK_Left) */
/* 		// */
/* 	else if (key_sym == XK_Right) */
/* 		// */
/* 	else if (key_sym == XK_plus) */
/* 		// */
/* 	else if (key_sym == XK_minus) */
/* 		// */
	printf("Key symbol: %d\n", key_sym);
	return (0);
}

/* static int	handle_mouse(int button, int x, int y, t_fractal *fractal) */
/* { */
/* 	if (button == Button4) */
/* 		// */
/* 	else if (button == Button5) */
/* 		// */
/* 	printf("Mouse btn: %d\n", button); */
/* 	return (0); */
/* } */

void	handle_events(t_mlx *mlx, t_fractal *set)
{
	mlx_hook(mlx->mlx_win, DestroyNotify, StructureNotifyMask, handle_close, set);
	mlx_hook(mlx->mlx_win, KeyPress, KeyPressMask, handle_keys, set);
	/* mlx_hook(mlx->mlx_win, ButtonPress, ButtonPressMask, handle_mouse, fractal); */
}
