/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render_floor_casting.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:19:54 by pamallet          #+#    #+#             */
/*   Updated: 2025/07/02 21:55:00 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	texturing_horiz_line(t_data *data,
	int textures[TEX_NUM][TEX_WIDTH *TEX_HEIGHT],
	u_int32_t tex_buff[S_HEIGHT][S_WIDTH],
	int y)
{
	int		x;
	t_floor	*floor;
	t_tex	*tex;

	floor = &data->floor;
	tex = &data->tex;
	x = -1;
	while (++x < S_WIDTH)
	{
		floor->cell_x = (int)floor->x;
		floor->cell_y = (int)floor->y;
		tex->floor_x = (int)
			(TEX_WIDTH * (floor->x - floor->cell_x)) & (TEX_WIDTH - 1);
		tex->floor_y = (int)
			(TEX_HEIGHT * (floor->y - floor->cell_y)) & (TEX_HEIGHT - 1);
		floor->x += floor->step_x;
		floor->y += floor->step_y;
		tex->color = textures[1][TEX_WIDTH * tex->floor_y + tex->floor_x];
		tex->color = (tex->color >> 1) & 8355711;
		tex_buff[y][x] = tex->color;
		tex->color = textures[2][TEX_WIDTH * tex->floor_y + tex->floor_x];
		tex->color = (tex->color >> 1) & 8355711;
		tex_buff[S_HEIGHT - y - 1][x] = tex->color;
	}
}

void	drawing_horiz_line(t_data *data, int y)
{
	int	x;
	int	color_floor;
	int	color_ceil;

	x = -1;
	color_floor = data->parsing.color_f;
	color_ceil = data->parsing.color_c;
	while (++x < S_WIDTH)
	{
		my_mlx_pixel_put(data, x, y, color_floor);
		my_mlx_pixel_put(data, x, S_HEIGHT - y - 1, color_ceil);
	}
}

void	floor_casting(t_data *data)
{
	int			y;
	t_ray		*ray;
	t_floor		*floor;

	ray = &data->ray;
	floor = &data->floor;
	y = S_HEIGHT / 2 - 1;
	while (++y < S_HEIGHT)
	{
		ray->dir_x_left = data->player.dir_x - data->cam.plane_x;
		ray->dir_y_left = data->player.dir_y - data->cam.plane_y;
		ray->dir_x_right = data->player.dir_x + data->cam.plane_x;
		ray->dir_y_right = data->player.dir_y + data->cam.plane_y;
		floor->pos_y = y - S_HEIGHT / 2;
		floor->pos_z = 0.5 * S_HEIGHT;
		floor->row_dist = floor->pos_z / (double)floor->pos_y;
		floor->step_x = floor->row_dist
			* (ray->dir_x_right - ray->dir_x_left) / S_WIDTH;
		floor->step_y = floor->row_dist
			* (ray->dir_y_right - ray->dir_y_left) / S_WIDTH;
		floor->x = data->player.pos_x + floor->row_dist * ray->dir_x_left;
		floor->y = data->player.pos_y + floor->row_dist * ray->dir_y_left;
		drawing_horiz_line(data, y);
	}
}
