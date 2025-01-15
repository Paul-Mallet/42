/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:42:53 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/15 16:07:32 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	handle_close(t_mlx *mlx, t_img *img_ptr)
{
	mlx_destroy_image(mlx->mlx, img->img_ptr);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	printf("Successfully closed!\n");
	return (0);
}

static int	handle_keys(int key_sym, t_mlx *mlx, t_fractal *fractal)
{
	if (key_sym == XK_Escape)
		close_hook(mlx);
	else if (key_sym == XK_Up)
		//
	else if (key_sym == XK_Down)
		//
	else if (key_sym == XK_Left)
		//
	else if (key_sym == XK_Right)
		//
	else if (key_sym == XK_plus)
		//
	else if (key_sym == XK_minus)
		//
	printf("Key symbol: %d\n", key_sym);
	return (0);
}

static int	handle_mouse(int button, t_fractal *fractal)
{
	if (button == Button4)
		//
	else if (button == Button5)
		//
	printf("Mouse btn: %d\n", button);
	return (0);
}

void	handle_hooks(t_mlx *mlx, t_fractal *fractal)
{
	mlx_hook(mlx->mlx_win, DestroyNotify, StructureNotifyMask, handle_close, fractal);
	mlx_hook(mlx->mlx_win, KeyPress, KeyPressMask, handle_keys, fractal);
	mlx_hook(mlx->mlx_win, ButtonPress, ButtonPressMask, handle_mouse, fractal);
}
