/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render_tex_gen.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:15:15 by pamallet          #+#    #+#             */
/*   Updated: 2025/07/02 21:58:03 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// this function and the 2nd of this file are not supposed to be here but its ok
// recalculate next player possible position to avoid passing through walls
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

// to choose which texture(N, S, E, W) set to textures array
int	get_tex_index(t_data *data)
{
	t_grid	*grid;
	t_ray	*ray;

	grid = &data->grid;
	ray = &data->ray;
	if (grid->wall.which_side == 0)
	{
		if (ray->dir_x > 0)
			return (1);
		else
			return (0);
	}
	else
	{
		if (ray->dir_y > 0)
			return (3);
		else
			return (2);
	}
}

void	copy_texture_data(t_tex *tex,
	int texture_slot[TEX_HEIGHT*TEX_WIDTH])
{
	int	x;
	int	y;
	int	*pixel_data;
	int	pixel_color;

	pixel_data = (int *)tex->tex_addr;
	y = -1;
	while (++y < TEX_HEIGHT)
	{
		x = -1;
		while (++x < TEX_WIDTH)
		{
			pixel_color = pixel_data[((tex->tex_line_len / 4) * y) + x];
			texture_slot[TEX_WIDTH * y + x] = pixel_color;
		}
	}
}

void	load_image(t_data *data,
	int texture_slot[TEX_HEIGHT*TEX_WIDTH],
	char *pathname)
{
	int		tex_w;
	int		tex_h;
	t_tex	*tex;

	tex = &data->tex;
	tex->tex_img = mlx_xpm_file_to_image(data->mlx.mlx_co, pathname,
			&tex_w, &tex_h);
	if (!tex->tex_img)
	{
		printf("Error\nFailed to load texture: %s\ntex->tex_img: %p\n",
			pathname, tex->tex_img);
		return ;
	}
	tex->tex_addr = mlx_get_data_addr(tex->tex_img,
			&tex->tex_bpp, &tex->tex_line_len, &tex->tex_endian);
	copy_texture_data(tex, texture_slot);
	mlx_destroy_image(data->mlx.mlx_co, tex->tex_img);
}

void	generate_textures(t_data *data,
	int textures[TEX_NUM][TEX_HEIGHT*TEX_WIDTH])
{
	load_image(data, textures[0], data->parsing.text_no);
	load_image(data, textures[1], data->parsing.text_so);
	load_image(data, textures[2], data->parsing.text_we);
	load_image(data, textures[3], data->parsing.text_ea);
}
