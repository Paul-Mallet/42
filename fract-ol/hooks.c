/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:42:53 by pamallet          #+#    #+#             */
/*   Updated: 2025/01/04 16:54:18 by pamallet         ###   ########.fr       */
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

int	close_esc_hook(int key_sym, t_vars *vars)
{
	if (key_sym == XK_Escape)
		mlx_destroy_window(vars->mlx, vars->mlx_win);
	printf("ESC key pressed: %d\n", key_sym);
	return (0);
}

int	zoom_hook(int button)
{
	if (button == Button4)
		printf("Zoom in: %d\n", button);
	else if (button == Button5)
		printf("Zoom out: %d\n", button);
	return (0);
}

int	close_cross_hook(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	printf("Cross clicked\n");
	return (0);
}
