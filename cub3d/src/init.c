/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:26:24 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/17 18:07:23 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_data(t_data *data)
{
	data->mlx.name = "cub3d_screen";
	// PARSING CHANGES
	data->vect.player.pos_x = 22.0;
	data->vect.player.pos_y = 12.0;
	data->vect.player.dir_x = -1.0;
	data->vect.player.dir_y = 0;
	data->vect.cam.plane_x = 0.0;
	data->vect.cam.plane_y = 0.66;
	data->grid.map_x = (int)data->vect.player.pos_x;
	data->grid.map_y = (int)data->vect.player.pos_y;
	// ---
	data->grid.wall.is_hit = false;
	data->grid.wall.which_side = false;
	data->frame.time = 0;
	data->frame.old_time = 0;
}

static void	init_mlx(t_data *data)
{
	data->mlx.mlx_co = mlx_init();
	if (!data->mlx.mlx_co)
		handle_err("Malloc error.", INIT);
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx_co,
		S_WIDTH, S_HEIGHT, data->mlx.name);
	if (!data->mlx.mlx_win)
	{
		mlx_destroy_display(data->mlx.mlx_co);
		free(data->mlx.mlx_co);
		handle_err("Malloc error.", WINDOW);
	}
	data->img.img_ptr = mlx_new_image(data->mlx.mlx_co, S_WIDTH, S_HEIGHT);
	if (!data->img.img_ptr)
	{
		mlx_destroy_window(data->mlx.mlx_co, data->mlx.mlx_win);
		mlx_destroy_display(data->mlx.mlx_co);
		free(data->mlx.mlx_co);
		free(data->mlx.mlx_win); //?
		handle_err("Malloc error.", IMAGE);
	}
	data->img.addr = mlx_get_data_addr(data->img.img_ptr,
		&data->img.bpp, &data->img.line_len, &data->img.endian);
}

void	init(t_data *data)
{
	init_data(data);
	init_mlx(data);
}
