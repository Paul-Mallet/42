/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:47:21 by bfiquet           #+#    #+#             */
/*   Updated: 2025/07/02 21:55:59 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	set_latitude_dirs(t_data *data)
{
	if (ft_strcmp(data->parsing.orientation, "North") == 0)
	{
		data->player.dir_x = -1.0;
		data->player.dir_y = 0.0;
		data->cam.plane_x = 0.0;
		data->cam.plane_y = 0.66;
	}
	else if (ft_strcmp(data->parsing.orientation, "South") == 0)
	{
		data->player.dir_x = 1.0;
		data->player.dir_y = 0.0;
		data->cam.plane_x = 0.0;
		data->cam.plane_y = -0.66;
	}
}

static void	set_longitude_dirs(t_data *data)
{
	if (ft_strcmp(data->parsing.orientation, "East") == 0)
	{
		data->player.dir_x = 0.0;
		data->player.dir_y = 1.0;
		data->cam.plane_x = 0.66;
		data->cam.plane_y = 0.0;
	}
	else if (ft_strcmp(data->parsing.orientation, "West") == 0)
	{
		data->player.dir_x = 0.0;
		data->player.dir_y = -1.0;
		data->cam.plane_x = -0.66;
		data->cam.plane_y = 0.0;
	}
}

static void	which_player_dir(t_data *data)
{
	set_latitude_dirs(data);
	set_longitude_dirs(data);
}

static void	setup_keys_bool(t_data *data)
{
	data->keys.close = 0;
	data->keys.up = 0;
	data->keys.down = 0;
	data->keys.right = 0;
	data->keys.left = 0;
	data->keys.right_dir = 0;
	data->keys.left_dir = 0;
}

void	init(t_data *data)
{
	convert_map_to_int(data);
	data->player.pos_x = (double)data->parsing.player_x;
	data->player.pos_y = (double)data->parsing.player_y;
	which_player_dir(data);
	data->grid.map_x = (int)data->player.pos_x;
	data->grid.map_y = (int)data->player.pos_y;
	data->grid.wall.is_hit = 0;
	setup_keys_bool(data);
}
