/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:47:25 by bfiquet           #+#    #+#             */
/*   Updated: 2025/07/02 21:55:32 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
		"grid.wall.which_side: %d\n",
		data->mlx.name,
		data->player.pos_x, data->player.pos_y,
		data->player.dir_x, data->player.dir_y,
		data->cam.plane_x, data->cam.plane_y,
		data->grid.map_x, data->grid.map_y,
		data->grid.wall.is_hit, data->grid.wall.which_side);
}
