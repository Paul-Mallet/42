/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render_side_dist.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:12:13 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/28 10:07:07 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_side_dist_x(t_ray *ray, t_player *player, t_grid *grid)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - grid->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (grid->map_x + 1.0 - player->pos_x)
			* ray->delta_dist_x;
	}
}

static void	init_side_dist_y(t_ray *ray, t_player *player, t_grid *grid)
{
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - grid->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (grid->map_y + 1.0 - player->pos_y)
			* ray->delta_dist_y;
	}
}

void	get_init_side_dist(t_data *data)
{
	t_ray		*ray;
	t_player	*player;
	t_grid		*grid;

	ray = &data->ray;
	player = &data->player;
	grid = &data->grid;
	grid->map_x = (int)data->player.pos_x;
	grid->map_y = (int)data->player.pos_y;
	init_side_dist_x(ray, player, grid);
	init_side_dist_y(ray, player, grid);
}

void	get_next_side_dist(t_data *data)
{
	t_ray	*ray;

	ray = &data->ray;
	if (ray->dir_x == 0)
		ray->delta_dist_x = INFINITY;
	else
		ray->delta_dist_x = ft_abs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->delta_dist_y = INFINITY;
	else
		ray->delta_dist_y = ft_abs(1 / ray->dir_y);
}
