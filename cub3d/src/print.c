/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 18:00:27 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/17 18:13:00 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_data(t_data *data)
{
	printf("mlx.name: %s\n"
		"vect.player.pos_x: %f\n"
		"vect.player.pos_y: %f\n"
		"vect.player.dir_x: %f\n"
		"vect.player.dir_y: %f\n"
		"vect.cam.plane_x: %f\n"
		"vect.cam.plane_y: %f\n"
		"grid.map_x: %d\n"
		"grid.map_y: %d\n"
		"grid.wall.is_hit: %d\n"
		"grid.wall.which_side: %d\n"
		"frame.time: %f\n"
		"frame.old_time: %f\n",
		data->mlx.name,
		data->vect.player.pos_x,
		data->vect.player.pos_y,
		data->vect.player.dir_x,
		data->vect.player.dir_y,
		data->vect.cam.plane_x,
		data->vect.cam.plane_y,
		data->grid.map_x,
		data->grid.map_y,
		data->grid.wall.is_hit,
		data->grid.wall.which_side,
		data->frame.time,
		data->frame.old_time);
}