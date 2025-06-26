/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 17:20:42 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/26 12:42:52 by paul_mallet      ###   ########.fr       */
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

void	setup_next_moves(t_data *data)
{
	t_player	*player;
	t_cam		*cam;
	t_speed		*speed;
	t_keys		*keys;

	player = &data->player;
	cam = &data->cam;
	speed = &data->speed;
	keys = &data->keys;
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
}

void	handle_up(t_data *data)
{
	t_player	*player;
	t_speed		*speed;
	t_keys		*keys;

	player = &data->player;
	speed = &data->speed;
	keys = &data->keys;
	if (world_map[keys->next_map_x_up][keys->curr_map_y] == 0)
		player->pos_x += player->dir_x * speed->mov;
	if (world_map[keys->curr_map_x][keys->next_map_y_up] == 0)
		player->pos_y += player->dir_y * speed->mov;
}

void	handle_down(t_data *data)
{
	t_player	*player;
	t_speed		*speed;
	t_keys		*keys;

	player = &data->player;
	speed = &data->speed;
	keys = &data->keys;
	if (world_map[keys->next_map_x_down][keys->curr_map_y] == 0)
		player->pos_x -= player->dir_x * speed->mov;
	if (world_map[keys->curr_map_x][keys->next_map_y_down] == 0)
		player->pos_y -= player->dir_y * speed->mov;
}

void	handle_right(t_data *data)
{
	t_player	*player;
	t_speed		*speed;
	t_keys		*keys;
	t_cam		*cam;

	player = &data->player;
	speed = &data->speed;
	keys = &data->keys;
	cam = &data->cam;
	if (world_map[keys->next_map_x_right][keys->curr_map_y] == 0)
		player->pos_x += cam->plane_x * speed->mov;
	if (world_map[keys->curr_map_x][keys->next_map_y_right] == 0)
		player->pos_y += cam->plane_y * speed->mov;
}

void	handle_left(t_data *data)
{
	t_player	*player;
	t_speed		*speed;
	t_keys		*keys;
	t_cam		*cam;

	player = &data->player;
	speed = &data->speed;
	keys = &data->keys;
	cam = &data->cam;
	if (world_map[keys->next_map_x_left][keys->curr_map_y] == 0)
		player->pos_x -= cam->plane_x * speed->mov;
	if (world_map[keys->curr_map_x][keys->next_map_y_left] == 0)
		player->pos_y -= cam->plane_y * speed->mov;
}

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

int	handle_keys(int key_sym, t_data *data)
{
	setup_next_moves(data);
	if (key_sym == XK_Escape)
		handle_close(data);
	else if (key_sym == XK_w)
		handle_up(data);
	else if (key_sym == XK_s)
		handle_down(data);
	else if (key_sym == XK_d)
		handle_right(data);
	else if (key_sym == XK_a)
		handle_left(data);
	else if (key_sym == XK_Right)
		handle_right_dir(data);
	else if (key_sym == XK_Left)
		handle_left_dir(data);
	render(data);
	return (0);
}
