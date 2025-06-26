/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:44:43 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/26 12:39:59 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_side_dist_x(t_ray *ray, t_player *player, t_grid *grid)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - grid->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (grid->map_x + 1.0 - player->pos_x)
			* ray->delta_dist_x;
	}
}

void	init_side_dist_y(t_ray *ray, t_player *player, t_grid *grid)
{
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - grid->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (grid->map_y + 1.0 - player->pos_y)
			* ray->delta_dist_y;
	}
}

void	get_init_side_dist(t_data *data)
{
	t_ray		*ray;
	t_player	*player;
	t_grid		*grid;

	ray = &data->ray;
	player = &data->player;
	grid = &data->grid;
	grid->map_x = (int)data->player.pos_x;
	grid->map_y = (int)data->player.pos_y;
	init_side_dist_x(ray, player, grid);
	init_side_dist_y(ray, player, grid);
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
}

void	digit_diff_analyzer(t_data *data)
{
	t_ray	*ray;
	t_grid	*grid;

	ray = &data->ray;
	grid = &data->grid;
	data->grid.wall.is_hit = 0;
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
		if (world_map[grid->map_x][grid->map_y] > 0)
			grid->wall.is_hit = true;
	}
}

void	put_texel_color(t_data *data,
	int textures[TEX_NUM][TEX_HEIGHT*TEX_WIDTH],
	u_int32_t tex_buff[S_HEIGHT][S_WIDTH])
{
	t_tex		*tex;
	t_grid		*grid;
	t_draw		*draw;
	t_screen	*screen;
	int			y;

	tex = &data->tex;
	grid = &data->grid;
	draw = &data->draw;
	screen = &data->screen;
	y = draw->draw_start;
	tex->tex_index = world_map[grid->map_x][grid->map_y] - 1;
	tex->step = 1.0 * TEX_HEIGHT / draw->line_height;
	tex->pos = (draw->draw_start - S_HEIGHT / 2 + draw->line_height / 2)
		* tex->step;
	while (y < draw->draw_end)
	{
		tex->y = (int)tex->pos & (TEX_HEIGHT - 1);
		tex->pos += tex->step;
		tex->color = textures[tex->tex_index][TEX_HEIGHT * tex->y + tex->x];
		if (data->grid.wall.which_side == 1)
			tex->color = (tex->color >> 1) & 8355711;
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

void	texturing_vert_line(t_data *data,
	int textures[TEX_NUM][TEX_HEIGHT*TEX_WIDTH],
	u_int32_t tex_buff[S_HEIGHT][S_WIDTH])
{
	wall_hit_to_tex_x(data);
	compute_tex_x(data);
	put_texel_color(data, textures, tex_buff);
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
	texturing_vert_line(data, textures, tex_buff);
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

void	get_time_frames(t_data *data)
{
	t_time	*time;

	time = &data->time;
	time->old = time->curr;
	time->curr = get_ticks();
	time->frame = (time->curr - time->old) / 1000.0;
}

void	speed_modifiers(t_data *data)
{
	t_time	*time;
	t_speed	*speed;

	time = &data->time;
	speed = &data->speed;
	speed->mov = time->frame * 30.0;
	speed->rot = time->frame * 20.0;
}

void	clear_lines(t_data *data)
{
	ft_memset(data->img.addr, 0, S_HEIGHT * data->img.line_len);
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
		printf("Failed to load texture: %s\ntex->tex_img: %p\n",
			pathname, tex->tex_img);
		return ;
	}
	tex->tex_addr = mlx_get_data_addr(tex->tex_img,
			&tex->tex_bpp, &tex->tex_line_len, &tex->tex_endian);
	copy_texture_data(tex, texture_slot);
	mlx_destroy_image(data->mlx.mlx_co, tex->tex_img);
}

// rm unused textures slots + resize TEX_NUM tests
void	generate_textures(t_data *data,
	int textures[TEX_NUM][TEX_HEIGHT*TEX_WIDTH])
{
	load_image(data, textures[0], "./assets/eagle.xpm");
	load_image(data, textures[1], "./assets/bluestone.xpm");
	load_image(data, textures[2], "./assets/barrel.xpm");
	load_image(data, textures[3], "./assets/colorstone.xpm");
	load_image(data, textures[4], "./assets/eagle.xpm");
	load_image(data, textures[5], "./assets/bluestone.xpm");
	load_image(data, textures[6], "./assets/barrel.xpm");
	load_image(data, textures[7], "./assets/colorstone.xpm");
}

void	draw_tex_buff(t_data *data, u_int32_t tex_buff[S_HEIGHT][S_WIDTH])
{
	int	x;
	int	y;

	y = -1;
	while (++y < S_HEIGHT)
	{
		x = -1;
		while (++x < S_WIDTH)
		{
			if (tex_buff[y][x] != 0)
				my_mlx_pixel_put(data, x, y, tex_buff[y][x]);
		}
	}
}

void	clear_tex_buff(t_data *data, u_int32_t tex_buff[S_HEIGHT][S_WIDTH])
{
	int	x;
	int	y;

	clear_lines(data);
	y = -1;
	while (++y < S_HEIGHT)
	{
		x = -1;
		while (++x < S_WIDTH)
		{
			tex_buff[y][x] = 0;
		}
	}
}

void	texturing_horiz_line(t_data *data,
	int textures[TEX_NUM][TEX_WIDTH *TEX_HEIGHT],
	u_int32_t tex_buff[S_HEIGHT][S_WIDTH],
	int y)
{
	int		x;
	t_floor	*floor;
	t_tex	*tex;

	floor = &data->floor;
	tex = &data->tex;
	x = -1;
	while (++x < S_WIDTH)
	{
		floor->cell_x = (int)floor->x;
		floor->cell_y = (int)floor->y;
		tex->floor_x = (int)
			(TEX_WIDTH * (floor->x - floor->cell_x)) & (TEX_WIDTH - 1);
		tex->floor_y = (int)
			(TEX_HEIGHT * (floor->y - floor->cell_y)) & (TEX_HEIGHT - 1);
		floor->x += floor->step_x;
		floor->y += floor->step_y;
		tex->color = textures[1][TEX_WIDTH * tex->floor_y + tex->floor_x];
		tex->color = (tex->color >> 1) & 8355711;
		tex_buff[y][x] = tex->color;
		tex->color = textures[3][TEX_WIDTH * tex->floor_y + tex->floor_x];
		tex->color = (tex->color >> 1) & 8355711;
		tex_buff[S_HEIGHT - y - 1][x] = tex->color;
	}
}

void	floor_casting(t_data *data,
	int textures[TEX_NUM][TEX_WIDTH *TEX_HEIGHT],
	u_int32_t tex_buff[S_HEIGHT][S_WIDTH])
{
	int			y;
	t_ray		*ray;
	t_floor		*floor;

	ray = &data->ray;
	floor = &data->floor;
	y = S_HEIGHT / 2;
	while (++y < S_HEIGHT)
	{
		ray->dir_x_left = data->player.dir_x - data->cam.plane_x;
		ray->dir_y_left = data->player.dir_y - data->cam.plane_y;
		ray->dir_x_right = data->player.dir_x + data->cam.plane_x;
		ray->dir_y_right = data->player.dir_y + data->cam.plane_y;
		floor->pos_y = y - S_HEIGHT / 2;
		floor->pos_z = 0.5 * S_HEIGHT;
		floor->row_dist = floor->pos_z / (double)floor->pos_y;
		floor->step_x = floor->row_dist
			* (ray->dir_x_right - ray->dir_x_left) / S_WIDTH;
		floor->step_y = floor->row_dist
			* (ray->dir_y_right - ray->dir_y_left) / S_WIDTH;
		floor->x = data->player.pos_x + floor->row_dist * ray->dir_x_left;
		floor->y = data->player.pos_y + floor->row_dist * ray->dir_y_left;
		texturing_horiz_line(data, textures, tex_buff, y);
	}
}

void	render(t_data *data)
{
	t_mlx		*mlx;
	t_screen	*screen;
	u_int32_t	tex_buff[S_HEIGHT][S_WIDTH];
	int			textures[TEX_NUM][TEX_HEIGHT * TEX_WIDTH];

	mlx = &data->mlx;
	screen = &data->screen;
	screen->x = 0;
	screen->y = 0;
	clear_tex_buff(data, tex_buff);
	data->time.curr = get_ticks();
	generate_textures(data, textures);
	floor_casting(data, textures, tex_buff);
	while (screen->x < S_WIDTH)
	{
		draw_my_pixel_line(data, textures, tex_buff);
		screen->x++;
	}
	draw_tex_buff(data, tex_buff);
	get_time_frames(data);
	speed_modifiers(data);
	mlx_put_image_to_window(mlx->mlx_co, mlx->mlx_win,
		data->img.img_ptr, 0, 0);
}
