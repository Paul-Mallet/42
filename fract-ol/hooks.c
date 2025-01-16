/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:42:53 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/16 19:11:46 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_close(t_set *set)
{
	mlx_destroy_image(set->mlx.mlx_co, set->img.img_ptr);
	mlx_destroy_window(set->mlx.mlx_co, set->mlx.mlx_win);
	mlx_destroy_display(set->mlx.mlx_co);
	free(set->mlx.mlx_co);
	exit(0);
	return (0);
}

int	handle_keys(int key_sym, t_set *set)
{
	if (key_sym == XK_Escape)
	{
		printf("Key pressed: %d\n", key_sym);
		handle_close(set);
	}
	//key_sym -> XK_Left, XK_Right, XK_Up, XK_Down, XK_plus, XK_minus
	return (0);
}

int	handle_mouse(int button, t_set *set)
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
