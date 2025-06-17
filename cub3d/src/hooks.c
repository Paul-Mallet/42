/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:20:42 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/17 17:21:53 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_close(t_data *data)
{
	mlx_destroy_image(data->mlx.mlx_co, data->img.img_ptr);
	mlx_destroy_window(data->mlx.mlx_co, data->mlx.mlx_win);
	mlx_destroy_display(data->mlx.mlx_co);
	free(data->mlx.mlx_co);
	exit(EXIT_SUCCESS);
}

int	handle_keys(int key_sym, t_data *data)
{
	if (key_sym == XK_Escape)
		handle_close(data);
	//W, A, S, D to move(t_player + t_cam)...
	return (0);
}