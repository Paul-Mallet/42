/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:44:43 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/20 12:19:14 by paul_mallet      ###   ########.fr       */
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

int		choose_color(t_data *data)
{
	t_grid	grid;
	t_draw	draw;

	grid = data->grid;
	draw = data->draw;

	//wall hit or empty space, change with texture after
	if (worldMap[grid.map_x][grid.map_y] == 1) //wall
		draw.color = GREEN;
	if (worldMap[grid.map_x][grid.map_y] == 0) //empty
		draw.color = BLACK;

	//darker if y-side hit too(diff x/y-sides visible on screen)
	if (data->grid.wall.which_side == 1)
		draw.color = draw.color / 2;
}

void	draw_vert_line(t_data *data, int y_start, int y_end, int color)
{
	int	y;
	
	y = y_start;
	// top to bottom pixel put
    while (y <= y_end)
    {
        my_mlx_pixel_put(data, data->screen.x, y, color);
     	y++;
    }
}

void	handle_vert_line(t_data *data)
{
	t_draw	draw;

	draw = data->draw;
	draw.line_height = (int)(S_HEIGHT / data->ray.perp_wall_dist);
	
	draw.draw_start = (-draw.line_height / 2) + (S_HEIGHT / 2);
	if (draw.draw_start < 0)
		draw.draw_start = 0;
	draw.draw_end = (draw.line_height / 2) + (S_HEIGHT / 2);
	if (draw.draw_end >= S_HEIGHT)
		draw.draw_end = S_HEIGHT - 1;

	// choose color based on x/y-side hit point
	draw.color = choose_color(data);

	// draw stripe pixels as a vertical line, see how_to_draw line of pixels?
	draw_vert_line(data, draw.draw_start, draw.draw_end, draw.color);
}

void	draw_my_pixel_line(t_data *data)
{
	t_player	player;
	t_cam		cam;
	t_ray		ray;
	double		max_width;

	player = data->player;
	cam = data->cam;
	ray = data->ray;
	max_width = S_WIDTH - 1;

	// ray position & direction
	cam.camera_x = (2 * data->screen.x) / max_width;
	ray.dir_x = (player.dir_x + cam.plane_x) * cam.camera_x;
	ray.dir_y = (player.dir_y + cam.plane_y) * cam.camera_x;

	// Ray len from 1 x/y-side to next side row/col
	get_next_side_dist(data);
	
	// Step & init ray side distances x/y
	get_init_side_dist(data);

	// DDA algorithm
	digit_diff_analyzer(data);
	
	// ray distance to wall, to determine wall height
	ray.perp_wall_dist = (ray.side_dist_y - ray.delta_dist_y) / ft_abs(ray.dir_y) / ray.dir_y;

	// line height to draw on screen
	handle_vert_line(data);
	
	// ray tracing loop done
	return ;
}

void	get_time_frames(data)
{
	data->time.old = data->time.curr;
	// data->time.curr = get_ticks(); // #TODO
	data->time.frame = (data->time.curr - data->time.old) / 1000.0; //in sec
}

void	speed_modifiers(t_data *data)
{
	data->speed.move = data->time.frame * 5.0;
	data->speed.rot = data->time.frame * 3.0;
}

void	render(t_data *data)
{
	t_screen	screen;

	screen = data->screen;
	screen.x = 0;
	screen.y = 0;
	// ray-casting loop on width screen
	while (screen.x < S_WIDTH)
	{
		draw_my_pixel_line(data); // not every pxl, every vertical stripe
		screen.x++;
	}

	// get time between curr / prev frame & fps
	get_time_frames(data);

	// get fps
	// print_on_screen(1.0 / data->time.frame);
	// redraw();
	// clear_backbuff();

	// speed_modifiers(move & rotating hooks)
	speed_modifiers(data);

	// put fully drawn image to window
	mlx_put_image_to_window(data->mlx.mlx_co,
		data->mlx.mlx_win,
		data->img.img_ptr, 0, 0);
}
