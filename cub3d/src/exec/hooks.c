/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:47:19 by bfiquet           #+#    #+#             */
/*   Updated: 2025/07/02 21:56:22 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	handle_right_dir(t_data *data)
{
	t_player	*player;
	t_speed		*speed;
	t_cam		*cam;

	player = &data->player;
	speed = &data->speed;
	cam = &data->cam;
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
}

void	handle_left_dir(t_data *data)
{
	t_player	*player;
	t_speed		*speed;
	t_cam		*cam;

	player = &data->player;
	speed = &data->speed;
	cam = &data->cam;
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
}

int	handle_keys_press(int key_sym, t_data *data)
{
	if (key_sym == XK_Escape)
		data->keys.close = 1;
	if (key_sym == XK_w)
		data->keys.up = 1;
	else if (key_sym == XK_s)
		data->keys.down = 1;
	else if (key_sym == XK_d)
		data->keys.right = 1;
	else if (key_sym == XK_a)
		data->keys.left = 1;
	if (key_sym == XK_Right)
		data->keys.right_dir = 1;
	if (key_sym == XK_Left)
		data->keys.left_dir = 1;
	return (0);
}

int	handle_keys_release(int key_sym, t_data *data)
{
	if (key_sym == XK_Escape)
		data->keys.close = 0;
	if (key_sym == XK_w)
		data->keys.up = 0;
	else if (key_sym == XK_s)
		data->keys.down = 0;
	else if (key_sym == XK_d)
		data->keys.right = 0;
	else if (key_sym == XK_a)
		data->keys.left = 0;
	if (key_sym == XK_Right)
		data->keys.right_dir = 0;
	if (key_sym == XK_Left)
		data->keys.left_dir = 0;
	return (0);
}

int	handle_keys(t_data *data)
{
	setup_next_moves(data);
	if (data->keys.close)
		handle_close(data);
	if (data->keys.up)
		handle_up(data);
	else if (data->keys.down)
		handle_down(data);
	else if (data->keys.right)
		handle_right(data);
	else if (data->keys.left)
		handle_left(data);
	if (data->keys.right_dir)
		handle_right_dir(data);
	if (data->keys.left_dir)
		handle_left_dir(data);
	render(data);
	return (0);
}
