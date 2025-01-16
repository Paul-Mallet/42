/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:42:53 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/16 12:17:48 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	pointer_hook(int x, int y)
{
	printf("Pointer position: (%d,%d)\n", x, y);
	return (0);
}

int	close_esc_hook(int key_sym, t_set *set)
{
	if (key_sym == XK_Escape)
	{
		mlx_destroy_image(set->mlx.mlx_co, set->img.img_ptr);
		mlx_destroy_window(set->mlx.mlx_co, set->mlx.mlx_win);
		mlx_destroy_display(set->mlx.mlx_co);
		free(set->mlx.mlx_co);
	}
	printf("Key pressed: %d\n", key_sym);
	return (0);
}

int	zoom_hook(int button, t_set *set)
{
	if (button == Button4)
	{
		set->zoom *= 0.95;
		printf("Zoom in: %d(%f)\n", button, set->zoom);
	}
	else if (button == Button5)
	{
		set->zoom *= 1.05;
		printf("Zoom out: %d(%f)\n", button, set->zoom);
	}
	return (0);
}

int	close_cross_hook(t_set *set)
{
	mlx_destroy_window(set->mlx.mlx_co, set->mlx.mlx_win);
	/* mlx_destroy_display(mlx->mlx); */
	/* free(mlx->mlx); */
	printf("Cross clicked\n");
	return (0);
}
