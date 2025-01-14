/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:42:53 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/14 18:18:01 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int	close_esc_hook(int key_sym, t_mlx *mlx)
{
	if (key_sym == XK_Escape)
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	printf("Key pressed: %d\n", key_sym);
	return (0);
}

int	zoom_hook(int button, t_set set)
{
	if (button == Button4)
	{
		set.zoom *= 0.95;
		printf("Zoom in: %d(%f)\n", button, set.zoom);
	}
	else if (button == Button5)
	{
		set.zoom *= 1.05;
		printf("Zoom out: %d(%f)\n", button, set.zoom);
	}
	return (0);
}

int	close_cross_hook(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	printf("Cross clicked\n");
	return (0);
}
