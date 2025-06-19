/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:20:42 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/19 19:04:32 by pamallet         ###   ########.fr       */
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
	t_player	player;
	t_cam		cam;
	t_speed		speed;

	player = data->player;
	cam = data->cam;
	speed = data->speed;
	// circle around player won't go inside walls(instead point)
	if (key_sym == XK_Escape)
		handle_close(data);
	//W, A, S, D to move(t_player + t_cam)...
	else if (key_sym == XK_w)
	{
		if (worldMap[(int)(player.pos_x + player.dir_x * speed.move)][(int)(player.pos_y)] == 0)
			player.pos_x += player.dir_x * speed.move;
		if (worldMap[(int)(player.pos_x)][(int)(player.pos_y + player.dir_y * speed.move)] == 0)
			player.pos_y += player.dir_y * speed.move;
	}
	else if (key_sym == XK_s)
	{
		if (worldMap[(int)(player.pos_x - player.dir_x * speed.move)][(int)(player.pos_y)] == 0)
			player.pos_x -= player.dir_x * speed.move;
		if (worldMap[(int)(player.pos_x)][(int)(player.pos_y - player.dir_y * speed.move)] == 0)
			player.pos_y -= player.dir_y * speed.move;
	}
	// else if (key_sym == XK_a) 1 left step
	// else if (key_sym == XK_d) 1 right step

	//Left Arrow / Right Arrow to rotate
	else if (key_sym == XK_Right)
	{
		// rotate both dirX & planeX
		player.old_dir_x = player.dir_x;
		player.dir_x = player.dir_x * cos(-speed.rot) - player.dir_y * sin(-speed.rot);
		player.dir_y = player.old_dir_x * sin(-speed.rot) + player.dir_y * cos(-speed.rot);
		cam.old_plane_x = cam.plane_x;
		cam.plane_x = cam.plane_x * cos(-speed.rot) - cam.plane_y * sin(-speed.rot);
		cam.plane_y = cam.old_plane_x * sin(-speed.rot) + cam.plane_y * cos(-speed.rot);
	}
	else if (key_sym == XK_Left)
	{
		player.old_dir_x = player.dir_x;
		player.dir_x = player.dir_x * cos(speed.rot) - player.dir_y * sin(speed.rot);
		player.dir_y = player.old_dir_x * sin(speed.rot) + player.dir_y * cos(speed.rot);
		cam.old_plane_x = cam.plane_x;
		cam.plane_x = cam.plane_x * cos(speed.rot) - cam.plane_y * sin(speed.rot);
		cam.plane_y = cam.old_plane_x * sin(speed.rot) + cam.plane_y * cos(speed.rot);
	}
	return (0);
}