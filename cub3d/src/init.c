/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:26:24 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/24 09:36:10 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_data(t_data *data)
{
	data->mlx.name = "cub3d_screen";
	// PARSING START
	// player position on 2d grid(22x12)
	data->player.pos_x = 22.0;
	data->player.pos_y = 12.0;
	// player direction(N, S, E, W)
	data->player.dir_x = -1.0; //West Side
	data->player.dir_y = 0.0;
	// vector camera plane
	data->cam.plane_x = 0.0;
	data->cam.plane_y = 0.66;
	// curr 2d grid cell where player is, RESET at each x++ !
	data->grid.map_x = (int)data->player.pos_x;
	data->grid.map_y = (int)data->player.pos_y;
	// PARSING END
	// 2d grid(32x32)
	data->grid.wall.is_hit = 0;
	// data->grid.wall.which_side = false;
	// time & fps
	data->time.curr = get_ticks();
	data->time.old = data->time.curr;
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
		free(data->mlx.mlx_win); //needed?
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
