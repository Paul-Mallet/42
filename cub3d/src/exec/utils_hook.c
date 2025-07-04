/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:09:50 by pamallet          #+#    #+#             */
/*   Updated: 2025/07/02 09:33:37 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// where I call it, depends on seg fault?
int	handle_close(t_data *data)
{
	free(data->parsing.orientation);
	free_textures_and_images(data);
	if (data->parsing.file)
		free_tab(data->parsing.file);
	if (data->parsing.map)
		free_tab(data->parsing.map);
	if (data->parsing.map_int)
		free_map_int(data);
	mlx_destroy_image(data->mlx.mlx_co, data->img.img_ptr);
	mlx_destroy_window(data->mlx.mlx_co, data->mlx.mlx_win);
	mlx_destroy_display(data->mlx.mlx_co);
	free(data->mlx.mlx_co);
	exit(EXIT_SUCCESS);
}

void	handle_up(t_data *data)
{
	t_player	*player;
	t_speed		*speed;
	t_keys		*keys;

	player = &data->player;
	speed = &data->speed;
	keys = &data->keys;
	if (data->parsing.map_int[keys->next_map_x_up][keys->curr_map_y] == 0)
		player->pos_x += player->dir_x * speed->mov;
	if (data->parsing.map_int[keys->curr_map_x][keys->next_map_y_up] == 0)
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
	if (data->parsing.map_int[keys->next_map_x_down][keys->curr_map_y] == 0)
		player->pos_x -= player->dir_x * speed->mov;
	if (data->parsing.map_int[keys->curr_map_x][keys->next_map_y_down] == 0)
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
	if (data->parsing.map_int[keys->next_map_x_right][keys->curr_map_y] == 0)
		player->pos_x += cam->plane_x * speed->mov;
	if (data->parsing.map_int[keys->curr_map_x][keys->next_map_y_right] == 0)
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
	if (data->parsing.map_int[keys->next_map_x_left][keys->curr_map_y] == 0)
		player->pos_x -= cam->plane_x * speed->mov;
	if (data->parsing.map_int[keys->curr_map_x][keys->next_map_y_left] == 0)
		player->pos_y -= cam->plane_y * speed->mov;
}
