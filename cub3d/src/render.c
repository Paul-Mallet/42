/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:44:43 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/18 17:09:37 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_init_side_dist(t_data *data)
{
	if (data->ray.dir_x < 0)
	{
		data->ray.step_x = -1;
		data->ray.side_dist_x = (data->player.pos_x - data->grid.map_x) * data->ray.delta_dist_x;
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.side_dist_x = (data->grid.map_x + 1.0 - data->player.pos_x) * data->ray.delta_dist_x;
	}
	if (data->ray.dir_y < 0)
	{
		data->ray.step_y = -1;
		data->ray.side_dist_y = (data->player.pos_y - data->grid.map_y) * data->ray.delta_dist_y;
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.side_dist_y = (data->grid.map_y + 1.0 - data->player.pos_y) * data->ray.delta_dist_y;
	}
}

void	get_next_side_dist(t_data *data)
{
	if (data->ray.dir_x == 0)
		data->ray.delta_dist_x = INFINITY;
	else
		data->ray.delta_dist_x = ft_abs(1 / data->ray.dir_x);
	if (data->ray.dir_y == 0)
		data->ray.delta_dist_y = INFINITY;
	else
		data->ray.delta_dist_y = ft_abs(1 / data->ray.dir_y);
}

void	digit_diff_analyzer(t_data *data)
{
	// start DDA
	while (!data->grid.wall.is_hit)
	{
		if (data->ray.side_dist_x < data->ray.side_dist_y)
		{
			data->ray.side_dist_x += data->ray.delta_dist_x;
			data->grid.map_x += data->ray.step_x;
			data->grid.wall.which_side = 0;
		}
		else
		{
			data->ray.side_dist_y += data->ray.delta_dist_y;
			data->grid.map_y += data->ray.step_y;
			data->grid.wall.which_side = 1;
		}
		// worldMap = 2d grid from PARSING
		// if (worldMap[data->grid.map_x][data->grid.map_y] > 0) #TODO
		// 	data->grid.wall.is_hit = true;
	}
}

void	draw_my_pixel(t_data *data, int x, int y)
{
	(void)y;
	double	max_width;

	max_width = S_WIDTH - 1;
	// ray position & direction
	data->cam.camera_x = 2 * x / max_width;
	data->ray.dir_x = (data->player.dir_x + data->cam.plane_x) * data->cam.camera_x;
	data->ray.dir_y = (data->player.dir_y + data->cam.plane_y) * data->cam.camera_x;

	// Ray len from 1 x/y-side to next side row/col
	get_next_side_dist(data);
	
	// Step & init ray side distances x/y
	get_init_side_dist(data);

	// DDA algorithm
	digit_diff_analyzer(data);
	
	// ray distance to wall, to determine wall height
	// after DDA
}

void	render(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < S_HEIGHT)
	{
		x = 0;
		while (x < S_WIDTH)
		{
			draw_my_pixel(data, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx.mlx_co,
		data->mlx.mlx_win,
		data->img.img_ptr, 0, 0);
}
