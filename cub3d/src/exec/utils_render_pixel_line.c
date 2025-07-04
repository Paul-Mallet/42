/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render_pixel_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:23:40 by pamallet          #+#    #+#             */
/*   Updated: 2025/07/02 21:53:15 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_texel_color(t_data *data,
	int textures[TEX_NUM][TEX_HEIGHT*TEX_WIDTH],
	u_int32_t tex_buff[S_HEIGHT][S_WIDTH])
{
	t_tex		*tex;
	t_draw		*draw;
	t_screen	*screen;
	int			y;

	tex = &data->tex;
	draw = &data->draw;
	screen = &data->screen;
	y = draw->draw_start;
	tex->tex_index = get_tex_index(data);
	tex->step = 1.0 * TEX_HEIGHT / draw->line_height;
	tex->pos = (draw->draw_start - S_HEIGHT / 2 + draw->line_height / 2)
		* tex->step;
	while (y < draw->draw_end)
	{
		tex->y = (int)tex->pos & (TEX_HEIGHT - 1);
		tex->pos += tex->step;
		tex->color = textures[tex->tex_index][TEX_HEIGHT * tex->y + tex->x];
		tex_buff[y][screen->x] = tex->color;
		y++;
	}
}

void	compute_tex_x(t_data *data)
{
	t_tex		*tex;
	t_grid		*grid;
	t_ray		*ray;

	tex = &data->tex;
	grid = &data->grid;
	ray = &data->ray;
	tex->x = (int)(tex->wall_x * (double)TEX_WIDTH);
	if (grid->wall.which_side == 0 && ray->dir_x > 0)
		tex->x = TEX_WIDTH - tex->x - 1;
	if (grid->wall.which_side == 1 && ray->dir_y < 0)
		tex->x = TEX_WIDTH - tex->x - 1;
}

void	wall_hit_to_tex_x(t_data *data)
{
	t_player	*player;
	t_grid		*grid;
	t_tex		*tex;
	t_ray		*ray;

	player = &data->player;
	grid = &data->grid;
	tex = &data->tex;
	ray = &data->ray;
	if (grid->wall.which_side == 0)
		tex->wall_x = player->pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		tex->wall_x = player->pos_x + ray->perp_wall_dist * ray->dir_x;
	tex->wall_x -= floor(tex->wall_x);
}

void	handle_vert_line(t_data *data,
	int textures[TEX_NUM][TEX_HEIGHT*TEX_WIDTH],
	u_int32_t tex_buff[S_HEIGHT][S_WIDTH])
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
	wall_hit_to_tex_x(data);
	compute_tex_x(data);
	put_texel_color(data, textures, tex_buff);
}

void	draw_my_pixel_line(t_data *data,
	int textures[TEX_NUM][TEX_HEIGHT*TEX_WIDTH],
	u_int32_t tex_buff[S_HEIGHT][S_WIDTH])
{
	t_cam		*cam;
	t_ray		*ray;
	t_player	*player;

	cam = &data->cam;
	ray = &data->ray;
	player = &data->player;
	cam->camera_x = ((2 * data->screen.x) / (double)S_WIDTH) - 1;
	ray->dir_x = player->dir_x + (cam->plane_x * cam->camera_x);
	ray->dir_y = player->dir_y + (cam->plane_y * cam->camera_x);
	get_next_side_dist(data);
	get_init_side_dist(data);
	digit_diff_analyzer(data);
	if (data->grid.wall.which_side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	handle_vert_line(data, textures, tex_buff);
	return ;
}
