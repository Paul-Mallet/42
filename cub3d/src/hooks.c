/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:20:42 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/24 17:21:08 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_close(t_data *data)
{
	mlx_destroy_image(data->mlx.mlx_co, data->img.img_ptr);
	mlx_destroy_window(data->mlx.mlx_co, data->mlx.mlx_win);
	mlx_destroy_display(data->mlx.mlx_co);
	free(data->mlx.mlx_co);
	exit(EXIT_SUCCESS);
}

int	handle_keys(int key_sym, t_data *data)
{
	t_player	*player;
	t_cam		*cam;
	t_speed		*speed;
	t_keys		*keys;

	player = &data->player;
	cam = &data->cam;
	speed = &data->speed;
	keys = &data->keys;
	// setup_next_moves();
	keys->curr_map_x = (int)(player->pos_x);
	keys->curr_map_y = (int)(player->pos_y);
	keys->next_map_x_up = (int)(player->pos_x + player->dir_x * speed->mov);
	keys->next_map_y_up = (int)(player->pos_y + player->dir_y * speed->mov);
	keys->next_map_x_down = (int)(player->pos_x - player->dir_x * speed->mov);
	keys->next_map_y_down = (int)(player->pos_y - player->dir_y * speed->mov);
	keys->next_map_x_right = (int)(player->pos_x + cam->plane_x * speed->mov);
	keys->next_map_y_right = (int)(player->pos_y + cam->plane_y * speed->mov);
	keys->next_map_x_left = (int)(player->pos_x - cam->plane_x * speed->mov);
	keys->next_map_y_left = (int)(player->pos_y - cam->plane_y * speed->mov);
	// printf("Trying to access world_map[%d][%d]\n", next_map_x, next_map_y);
	// printf("MAP bounds: width=%d, height=%d\n", MAP_WIDTH, MAP_HEIGHT);
	// printf("time_frame: %f\n", data->time.frame);
	// circle around player won't go inside walls(instead point)
	if (key_sym == XK_Escape)
		handle_close(data);
	//W, A, S, D to move(t_player + t_cam)...
	else if (key_sym == XK_w)
	{
		if (world_map[keys->next_map_x_up][keys->curr_map_y] == 0)
			player->pos_x += player->dir_x * speed->mov;
		if (world_map[keys->curr_map_x][keys->next_map_y_up] == 0)
			player->pos_y += player->dir_y * speed->mov;
		printf("XK_w\nplayer->pos_x: %f\nplayer->pos_y: %f\n", player->pos_x, player->pos_y);
	}
	else if (key_sym == XK_s)
	{
		if (world_map[keys->next_map_x_down][keys->curr_map_y] == 0)
			player->pos_x -= player->dir_x * speed->mov;
		if (world_map[keys->curr_map_x][keys->next_map_y_down] == 0)
			player->pos_y -= player->dir_y * speed->mov;
		printf("XK_s\nplayer->pos_x: %f\nplayer->pos_y: %f\n", player->pos_x, player->pos_y);
	}
	else if (key_sym == XK_d)
	{
		if (world_map[keys->next_map_x_right][keys->curr_map_y] == 0)
			player->pos_x += cam->plane_x * speed->mov;
		if (world_map[keys->curr_map_x][keys->next_map_y_right] == 0)
			player->pos_y += cam->plane_y * speed->mov; //cam->plane_y
	}
	else if (key_sym == XK_a)
	{
		if (world_map[keys->next_map_x_left][keys->curr_map_y] == 0)
			player->pos_x -= cam->plane_x * speed->mov;
		if (world_map[keys->curr_map_x][keys->next_map_y_left] == 0)
			player->pos_y -= cam->plane_y * speed->mov;
	}
	//Left Arrow / Right Arrow to rotate
	else if (key_sym == XK_Right)
	{
		// rotate both dirX & planeX
		player->old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(-speed->rot)
			- (player->dir_y * sin(-speed->rot));
		player->dir_y = player->old_dir_x * sin(-speed->rot)
			+ player->dir_y * cos(-speed->rot);
		
		cam->old_plane_x = cam->plane_x;
		cam->plane_x = cam->plane_x * cos(-speed->rot)
			- cam->plane_y * sin(-speed->rot);
		cam->plane_y = cam->old_plane_x * sin(-speed->rot)
			+ cam->plane_y * cos(-speed->rot);
		printf("XK_Right\nplayer->pos_x: %f\nplayer->pos_y: %f\n", player->pos_x, player->pos_y);
		printf("XK_Right\ncam->plane_x: %f\ncam->plane_y: %f\n", cam->plane_x, cam->plane_y);
	}
	else if (key_sym == XK_Left)
	{
		player->old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(speed->rot)
			- player->dir_y * sin(speed->rot);
		player->dir_y = player->old_dir_x * sin(speed->rot)
			+ player->dir_y * cos(speed->rot);
		cam->old_plane_x = cam->plane_x;
		cam->plane_x = cam->plane_x * cos(speed->rot)
			- cam->plane_y * sin(speed->rot);
		cam->plane_y = cam->old_plane_x * sin(speed->rot)
			+ cam->plane_y * cos(speed->rot);
		printf("XK_Left\nplayer->dir_x: %f\nplayer->dir_y: %f\n", player->dir_x, player->dir_y);
		printf("XK_Left\ncam->plane_x: %f\ncam->plane_y: %f\n", cam->plane_x, cam->plane_y);
	}
	render(data);
	return (0);
}
