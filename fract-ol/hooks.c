/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:42:53 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/17 12:07:24 by paul_mall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_close(t_set *set)
{
	mlx_destroy_image(set->mlx.mlx_co, set->img.img_ptr);
	mlx_destroy_window(set->mlx.mlx_co, set->mlx.mlx_win);
	mlx_destroy_display(set->mlx.mlx_co);
	free(set->from_to);
	free(set->mlx.mlx_co);
	exit(0);
}

int	handle_keys(int key_sym, t_set *set)
{
	if (key_sym == XK_Escape)
		handle_close(set);
	else if (key_sym == XK_Left)
		set->shift_x -= 0.5 * set->zoom;
	else if (key_sym == XK_Right)
		set->shift_x += 0.5 * set->zoom;
	else if (key_sym == XK_Up)
		set->shift_y += 0.5 * set->zoom;
	else if (key_sym == XK_Down)
		set->shift_y -= 0.5 * set->zoom;
	render(set);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_set *set)
{
	(void)x;
	(void)y;
	if (button == Button4)
	{
		set->zoom *= 0.75;
		set->iterations += 1;
	}
	else if (button == Button5)
	{
		set->zoom *= 1.25;
		set->iterations -= 1;
	}
	render(set);
	return (0);
}
