/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:44:43 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/24 10:44:26 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_init_side_dist(t_data *data)
{
	t_ray		*ray;
	t_player	*player;

	ray = &data->ray;
	player = &data->player;
	data->grid.map_x = (int)data->player.pos_x;
	data->grid.map_y = (int)data->player.pos_y;
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - data->grid.map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (data->grid.map_x + 1.0 - player->pos_x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - data->grid.map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (data->grid.map_y + 1.0 - player->pos_y) * ray->delta_dist_y;
	}
	// #TODO : understand map_x : 5.000000, step_x = 1..., all before OK
	printf("data->grid.map_x: %d\ndata->grid.map_y: %d\n", data->grid.map_x, data->grid.map_y);
	printf("ray->side_dist_x: %f\nray->side_dist_y: %f\n", ray->side_dist_x, ray->side_dist_y);
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
	printf("ray->delta_dist_x: %f\n", ray->delta_dist_x);
	printf("ray->delta_dist_y: %f\n", ray->delta_dist_y);
}

void	digit_diff_analyzer(t_data *data)
{
	t_ray	*ray;
	t_grid	*grid;

	ray = &data->ray;
	grid = &data->grid;
	data->grid.wall.is_hit = 0;
	// start DDA
	while (!grid->wall.is_hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			grid->map_x += ray->step_x;
			grid->wall.which_side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			grid->map_y += ray->step_y;
			grid->wall.which_side = 1;
		}
		// worldMap = 2d grid from PARSING
		if (world_map[grid->map_x][grid->map_y] > 0)
			grid->wall.is_hit = true;
	}
	printf("data->ray.step_x: %d (after dda)\ndata->ray.step_y: %d (after dda)\n", data->ray.step_x, data->ray.step_y);
	printf("data->grid.map_x: %d (after dda)\ndata->grid.map_y: %d (after dda)\n", data->grid.map_x, data->grid.map_y);
}

void	choose_color(t_data *data)
{
	t_grid	*grid;
	t_draw	*draw;

	grid = &data->grid;
	draw = &data->draw;

	//wall hit or empty space, change with texture after
	if (world_map[grid->map_x][grid->map_y] == 1) //wall
		draw->color = GREEN;
	if (world_map[grid->map_x][grid->map_y] == 0) //empty
		draw->color = BLACK;

	//darker if y-side hit too(diff x/y-sides visible on screen)
	if (grid->wall.which_side == 1)
		draw->color = draw->color / 2;
}

void	draw_vert_line(t_data *data, int y_start, int y_end, int color)
{
	int			y;
	t_screen	*screen;
	
	y = y_start;
	screen = &data->screen;
	// top to bottom pixel put
    while (y <= y_end)
    {
        my_mlx_pixel_put(data, screen->x, y, color);
     	y++;
    }
}

void	handle_vert_line(t_data *data)
{
	t_ray	*ray;
	t_draw	*draw;

	ray = &data->ray;
	draw = &data->draw;
	draw->line_height = (int)(S_HEIGHT / ray->perp_wall_dist);

	draw->draw_start = (-draw->line_height / 2) + (S_HEIGHT / 2);
	if (draw->draw_start < 0)
		draw->draw_start = 0;
	draw->draw_end = (draw->line_height / 2) + (S_HEIGHT / 2);
	if (draw->draw_end >= S_HEIGHT)
		draw->draw_end = S_HEIGHT - 1;

	// choose color based on x/y-side hit point
	choose_color(data);

	// draw stripe pixels as a vertical line, see how_to_draw line of pixels?
	draw_vert_line(data, draw->draw_start, draw->draw_end, draw->color);
}

void	draw_my_pixel_line(t_data *data)
{
	t_cam		*cam;
	t_ray		*ray;
	t_player	*player;

	cam = &data->cam;
	ray = &data->ray;
	player = &data->player;

	// ray position & direction
	printf("screen.x: %d\n", data->screen.x);
	cam->camera_x = ((2 * data->screen.x) / (double)S_WIDTH) - 1; //[0 - 1]
	ray->dir_x = player->dir_x + (cam->plane_x * cam->camera_x);
	ray->dir_y = player->dir_y + (cam->plane_y * cam->camera_x);
	printf("ray->dir_x: %f\nray->dir_y: %f\n", ray->dir_x, ray->dir_y);

	// Ray len from 1 x/y-side to next side row/col
	get_next_side_dist(data);
	
	// Step & init ray side distances x/y
	get_init_side_dist(data);

	// DDA algorithm
	digit_diff_analyzer(data);
	
	// ray distance to wall, to determine wall height
	if (data->grid.wall.which_side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);

	// line height to draw on screen
	handle_vert_line(data);
	
	// ray tracing loop done
	return ;
}

void	get_time_frames(t_data *data)
{
	t_time	*time;

	time = &data->time;
	time->old = time->curr;
	time->curr = get_ticks();
	printf("get_time_frame() time->old: %f\n", time->old);
	printf("get_time_frame() time->curr: %f\n", time->curr);
	time->frame = (time->curr - time->old) / 1000.0; //in sec.usec
	printf("get_time_frame() time_frame: %f\n", time->frame);
}

//1.0 / 0.02 -> 50 fps
void	get_fps_string(t_data *data, int fps)
{
	t_screen	*screen;
	int			fps_len;
	int			i;

	screen = &data->screen;
	fps_len = ft_intlen(fps);
	screen->fps_str = (char *)malloc((fps_len + 1) * sizeof(char));
	if (!screen->fps_str)
		return ;
	i = fps_len - 1;
	while (fps > 9)
	{
		screen->fps_str[i] = (fps % 10) + '0';
		fps /= 10;
		i--;
	}
	screen->fps_str[i] = (fps % 10) + '0';
	screen->fps_str[fps_len] = '\0';
	printf("fps: %d\nscreen->fps_str: %s\n", fps, screen->fps_str);
}

void	speed_modifiers(t_data *data)
{
	t_time	*time;
	t_speed	*speed;

	time = &data->time;
	speed = &data->speed;
	speed->move = time->frame * 5.0;
	speed->rot = time->frame * 3.0;
	printf("speed->move: %f\nspeed->rot: %f\n", speed->move, speed->rot);
}

void	clear_image(t_data *data)
{
	ft_memset(data->img.addr, 0, S_HEIGHT * data->img.line_len);
}

void	render(t_data *data)
{
	t_mlx		*mlx;
	t_screen	*screen;

	mlx = &data->mlx;
	screen = &data->screen;
	screen->x = 0;
	screen->y = 0;
	// fully draw with black pixels img.addr better than mlx functions
	clear_image(data);

	// ray-casting loop on width screen
	while (screen->x < S_WIDTH)
	{
		draw_my_pixel_line(data); // not every pxl, every vertical stripe
		screen->x++;
	}

	// get time between curr / prev frame & fps
	get_time_frames(data);

	// get fps
	get_fps_string(data, (int)(1.0 / data->time.frame));
	// print on screen coord & color
	// mlx_string_put(mlx->mlx_co, mlx->mlx_win,
	// 	X_STR, Y_STR, WHITE, screen->fps_str);

	// redraw_frame();
	// ... not needed

	// // fully draw with black pixels > mlx_destroy_window()
	// clear_image(data); before instead of after

	// speed_modifiers(move & rotating hooks)
	speed_modifiers(data);

	// put fully drawn image to window
	mlx_put_image_to_window(mlx->mlx_co, mlx->mlx_win,
		data->img.img_ptr, 0, 0);
}
