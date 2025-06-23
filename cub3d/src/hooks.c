/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:20:42 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/23 17:32:04 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_close(t_data *data)
{
	if (data->screen.fps_str)
		free(data->screen.fps_str);
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

	player = &data->player;
	cam = &data->cam;
	speed = &data->speed;

	int new_x = (int)(player->pos_x + player->dir_x * speed->move);
	int new_y = (int)(player->pos_y);
	printf("Trying to access world_map[%d][%d]\n", new_x, new_y);
	printf("MAP bounds: width=%d, height=%d\n", MAP_WIDTH, MAP_HEIGHT);
	printf("time_frame: %f\n", data->time.frame);
	// circle around player won't go inside walls(instead point)
	if (key_sym == XK_Escape)
		handle_close(data);
	//W, A, S, D to move(t_player + t_cam)...
	else if (key_sym == XK_w)
	{
		if (world_map[(int)(player->pos_x + player->dir_x * speed->move)][(int)(player->pos_y)] == 0)
			player->pos_x += player->dir_x * speed->move;
		if (world_map[(int)(player->pos_x)][(int)(player->pos_y + player->dir_y * speed->move)] == 0)
			player->pos_y += player->dir_y * speed->move;
		printf("XK_w\nplayer->pos_x: %f\nplayer->pos_y: %f\n", player->pos_x, player->pos_y);
	}
	else if (key_sym == XK_s)
	{
		if (world_map[(int)(player->pos_x - player->dir_x * speed->move)][(int)(player->pos_y)] == 0)
			player->pos_x -= player->dir_x * speed->move;
		if (world_map[(int)(player->pos_x)][(int)(player->pos_y - player->dir_y * speed->move)] == 0)
			player->pos_y -= player->dir_y * speed->move;
		printf("XK_s\nplayer->pos_x: %f\nplayer->pos_y: %f\n", player->pos_x, player->pos_y);
	}
	// else if (key_sym == XK_a)
	// {
	// 	if (world_map[(int)(player->pos_x + player->dir_x * speed->move)][(int)(player->pos_y)] == 0)
	// 		player->pos_x += player->dir_x * speed->move;
	// 	if (world_map[(int)(player->pos_x)][(int)(player->pos_y - player->dir_y * speed->move)] == 0)
	// 		player->pos_y -= player->dir_y * speed->move;
	// }
	// else if (key_sym == XK_d)
	// {
	// 	if (world_map[(int)(player->pos_x - player->dir_x * speed->move)][(int)(player->pos_y)] == 0)
	// 		player->pos_x -= player->dir_x * speed->move;
	// 	if (world_map[(int)(player->pos_x)][(int)(player->pos_y + player->dir_y * speed->move)] == 0)
	// 		player->pos_y += player->dir_y * speed->move;
	// }
	//Left Arrow / Right Arrow to rotate
	else if (key_sym == XK_Right)
	{
		// rotate both dirX & planeX
		player->old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(-speed->rot) - player->dir_y * sin(-speed->rot);
		player->dir_y = player->old_dir_x * sin(-speed->rot) + player->dir_y * cos(-speed->rot);
		cam->old_plane_x = cam->plane_x;
		cam->plane_x = cam->plane_x * cos(-speed->rot) - cam->plane_y * sin(-speed->rot);
		cam->plane_y = cam->old_plane_x * sin(-speed->rot) + cam->plane_y * cos(-speed->rot);
		printf("XK_Right\nplayer->pos_x: %f\nplayer->pos_y: %f\n", player->pos_x, player->pos_y);
		printf("XK_Right\ncam->plane_x: %f\ncam->plane_y: %f\n", cam->plane_x, cam->plane_y);
	}
	else if (key_sym == XK_Left)
	{
		player->old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(speed->rot) - player->dir_y * sin(speed->rot);
		player->dir_y = player->old_dir_x * sin(speed->rot) + player->dir_y * cos(speed->rot);
		cam->old_plane_x = cam->plane_x;
		cam->plane_x = cam->plane_x * cos(speed->rot) - cam->plane_y * sin(speed->rot);
		cam->plane_y = cam->old_plane_x * sin(speed->rot) + cam->plane_y * cos(speed->rot);
		printf("XK_Left\nplayer->dir_x: %f\nplayer->dir_y: %f\n", player->dir_x, player->dir_y);
		printf("XK_Left\ncam->plane_x: %f\ncam->plane_y: %f\n", cam->plane_x, cam->plane_y);
	}
	render(data);
	return (0);
}
