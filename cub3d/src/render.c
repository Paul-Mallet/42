/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:44:43 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/19 18:02:35 by pamallet         ###   ########.fr       */
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

void	handle_vert_line(t_data *data)
{
	data->draw.line_height = (int)(S_HEIGHT / data->ray.perp_wall_dist);
	
	data->draw.draw_start = (-data->draw.line_height / 2) + (S_HEIGHT / 2);
	if (data->draw.draw_start < 0)
		data->draw.draw_start = 0;
	data->draw.draw_end = (data->draw.line_height / 2) + (S_HEIGHT / 2);
	if (data->draw.draw_end >= S_HEIGHT)
		data->draw.draw_end = S_HEIGHT - 1;

	// choose color based on x/y-side hit point
	// choose_color(data);

	// draw stripe pixels as a vertical line, see how_to_draw line of pixels?
	// draw_vert_line(x, data->draw.draw_start, data->draw.draw_end, color);
}

void	draw_my_pixel_line(t_data *data, int x, int y)
{
	(void)y;
	double	max_width;

	max_width = S_WIDTH - 1;
	// ray position & direction
	data->cam.camera_x = (2 * x) / max_width;
	data->ray.dir_x = (data->player.dir_x + data->cam.plane_x) * data->cam.camera_x;
	data->ray.dir_y = (data->player.dir_y + data->cam.plane_y) * data->cam.camera_x;

	// Ray len from 1 x/y-side to next side row/col
	get_next_side_dist(data);
	
	// Step & init ray side distances x/y
	get_init_side_dist(data);

	// DDA algorithm
	digit_diff_analyzer(data);
	
	// ray distance to wall, to determine wall height
	perp_wall_dist = (side_dist_y - delta_dist_y) / ft_abs(ray_dir_y) / ray_dir_y;

	// line height to draw on screen
	handle_vert_line(data);
	
	// ray tracing loop done
	// return ;
}

void	get_time_frames(data)
{
	data->time.old = data->time.curr;
	// data->time.curr = get_ticks();
	data->time.frame = (data->time.curr - data->time.old) / 1000.0; //in sec
}

void	speed_modifiers(t_data *data)
{
	data->speed.move = data->time.frame * 5.0;
	data->speed.rotate = data->time.frame * 3.0;
}

void	render(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	// ray-casting loop on width screen
	while (x < S_WIDTH)
	{
		draw_my_pixel_line(data, x, y); // not every pxl, every vertical stripe
		x++;
	}

	// get time between curr / prev frame & fps
	get_time_frames(data);

	// get fps
	printf("fps: %f\n", 1.0 / data->time.frame);
	// redraw();
	// clear_backbuff();

	// speed_modifiers(move & rotating hooks)
	speed_modifiers(data);

	// put fully drawn image to window
	mlx_put_image_to_window(data->mlx.mlx_co,
		data->mlx.mlx_win,
		data->img.img_ptr, 0, 0);
}
