/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:44:43 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/25 15:13:55 by pamallet         ###   ########.fr       */
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
	// printf("data->grid.map_x: %d\ndata->grid.map_y: %d\n", data->grid.map_x, data->grid.map_y);
	// printf("ray->side_dist_x: %f\nray->side_dist_y: %f\n", ray->side_dist_x, ray->side_dist_y);
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
	// printf("ray->delta_dist_x: %f\n", ray->delta_dist_x);
	// printf("ray->delta_dist_y: %f\n", ray->delta_dist_y);
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
	// printf("data->ray.step_x: %d (after dda)\ndata->ray.step_y: %d (after dda)\n", data->ray.step_x, data->ray.step_y);
	// printf("data->grid.map_x: %d (after dda)\ndata->grid.map_y: %d (after dda)\n", data->grid.map_x, data->grid.map_y);
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

void	texturing_vert_line(t_data *data,
	int textures[TEX_NUM][TEX_HEIGHT * TEX_WIDTH],
	u_int32_t tex_buff[S_HEIGHT][S_WIDTH])
{
	t_tex		*tex;
	t_grid		*grid;
	t_player	*player;
	t_ray		*ray;
	t_draw		*draw;
	t_screen	*screen;

	tex = &data->tex;
	grid = &data->grid;
	player = &data->player;
	ray = &data->ray;
	draw = &data->draw;
	screen = &data->screen;
	// texturing calculations
	tex->tex_index = world_map[grid->map_x][grid->map_y] - 1;
	// printf("grid->map_x: %d\ngrid->map_y: %d\ntex->tex_index: %d\n",
	// 	grid->map_x, grid->map_y, tex->tex_index);

	// wall_x = exact value where wall was hit, x/y coord of the wall, always x of the texture
	if (grid->wall.which_side == 0)
		tex->wall_x = player->pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		tex->wall_x = player->pos_x + ray->perp_wall_dist * ray->dir_x;
	tex->wall_x -= floor(tex->wall_x);
	// printf("tex->wall_x: %f\n", tex->wall_x);

	// x coordinate of the texture
	tex->x = (int)(tex->wall_x * (double)TEX_WIDTH);
	if (grid->wall.which_side == 0 && ray->dir_x > 0)
		tex->x = TEX_WIDTH - tex->x - 1;
	if (grid->wall.which_side == 1 && ray->dir_y < 0)
		tex->x = TEX_WIDTH - tex->x - 1;
	// printf("tex->x: %d\n", tex->x);

	// step = pre-compute slices between start/end of the line to draw
	// color = pixel color drawn based on texel of textures array
	// ask Nico if Pierre used mlx_png_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
	tex->step = 1.0 * TEX_HEIGHT / draw->line_height;
	// printf("draw->line_height: %d\ntex->step: %f\n", draw->line_height, tex->step);

	tex->pos = (draw->draw_start - S_HEIGHT / 2 + draw->line_height / 2) * tex->step;
	// printf("tex->pos: %f\n", tex->pos);

	int y = draw->draw_start;
	// printf("screen->y: %d\n", screen->y);
	while (y < draw->draw_end)
	{
		tex->y = (int)tex->pos & (TEX_HEIGHT - 1);
		// printf("tex->y: %d\n", tex->y);
		tex->pos += tex->step;
		// printf("tex->pos: %f(in draw loop)\n", tex->pos);
		tex->color = textures[tex->tex_index][TEX_HEIGHT * tex->y + tex->x];
		// printf("tex->tex_color: %" PRIu32 "(before which_side)\n", tex->color);
		if (grid->wall.which_side == 1)
			tex->color = (tex->color >> 1) & 8355711;
		// printf("tex->tex_color: %" PRIu32 "(after which_side)\n", tex->color);
		tex_buff[y][screen->x] = tex->color;
		y++;
	}

	// drawn tex->tex_buff, then cleared using updated (don't change mine while working)
	// is it the correct buffer that I draw on it / clear(see clear_lines buffer), maybe send tex_buff instead of ? to mlx_image
}

void	handle_vert_line(t_data *data, int textures[TEX_NUM][TEX_HEIGHT * TEX_WIDTH], u_int32_t tex_buff[S_HEIGHT][S_WIDTH])
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
	// choose_color(data);

	// texturing based on x/y square coordinates, 
	texturing_vert_line(data, textures, tex_buff);

	// draw stripe pixels as a vertical line, only works for untextured version
	// draw_vert_line(data, draw->draw_start, draw->draw_end, draw->color);

	// if textured version
	// draw entire tex_buff instead, outside of screen->x loop, after fullfilled tex_buff
}

void	draw_my_pixel_line(t_data *data, int textures[TEX_NUM][TEX_HEIGHT * TEX_WIDTH], u_int32_t tex_buff[S_HEIGHT][S_WIDTH])
{
	t_cam		*cam;
	t_ray		*ray;
	t_player	*player;

	cam = &data->cam;
	ray = &data->ray;
	player = &data->player;

	// ray position & direction
	// printf("screen.x: %d\n", data->screen.x);
	cam->camera_x = ((2 * data->screen.x) / (double)S_WIDTH) - 1; //[0 - 1]
	ray->dir_x = player->dir_x + (cam->plane_x * cam->camera_x);
	ray->dir_y = player->dir_y + (cam->plane_y * cam->camera_x);
	// printf("ray->dir_x: %f\nray->dir_y: %f\n", ray->dir_x, ray->dir_y);

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
	handle_vert_line(data, textures, tex_buff);
	
	// ray tracing loop done
	return ;
}

void	get_time_frames(t_data *data)
{
	t_time	*time;

	time = &data->time;
	time->old = time->curr;
	time->curr = get_ticks();
	// printf("get_time_frame() time->old: %f\n", time->old);
	// printf("get_time_frame() time->curr: %f\n", time->curr);
	time->frame = (time->curr - time->old) / 1000.0; //in sec.usec
	// printf("get_time_frame() time_frame: %f\n", time->frame);
}

//1.0 / 0.02 -> 50 fps
// void	get_fps_string(t_data *data, int fps)
// {
// 	t_screen	*screen;
// 	int			fps_len;
// 	int			i;

// 	screen = &data->screen;
// 	fps_len = ft_intlen(fps);
// 	screen->fps_str = (char *)malloc((fps_len + 1) * sizeof(char));
// 	if (!screen->fps_str)
// 		return ;
// 	i = fps_len - 1;
// 	while (fps > 9)
// 	{
// 		screen->fps_str[i] = (fps % 10) + '0';
// 		fps /= 10;
// 		i--;
// 	}
// 	screen->fps_str[i] = (fps % 10) + '0';
// 	screen->fps_str[fps_len] = '\0';
// 	printf("fps: %d\nscreen->fps_str: %s\n", fps, screen->fps_str);
// }

void	speed_modifiers(t_data *data)
{
	t_time	*time;
	t_speed	*speed;

	time = &data->time;
	speed = &data->speed;
	speed->mov = time->frame * 30.0;
	speed->rot = time->frame * 20.0;
	// printf("speed->move: %f\nspeed->rot: %f\n", speed->mov, speed->rot);
}

void	clear_lines(t_data *data)
{
	ft_memset(data->img.addr, 0, S_HEIGHT * data->img.line_len);
}

// void	load_textures(t_data *data, char *pathname, int textures[TEX_NUM][TEX_HEIGHT * TEX_WIDTH])
// {
// 	int	tex_w;
// 	int	tex_h;	// store the mlx_xpm_image() return (void *);

// 	mlx_xpm_file_to_image(data->mlx.mlx_co, pathname, &tex_w, &tex_h);
// }

void	generate_textures(t_data *data, int textures[TEX_NUM][TEX_HEIGHT * TEX_WIDTH])
{
	int		x;
	int		y;
	int		convert;
	t_tex	*tex;

	tex = &data->tex;
	x = -1;
	while (++x < TEX_WIDTH)
	{
		y = -1;
		while (++y < TEX_HEIGHT)
		{
			tex->xorcolor = (x * 256 / TEX_WIDTH) ^ (y * 256 / TEX_HEIGHT);
			// tex->xcolor = x * 256 / TEX_WIDTH; //no need
			tex->ycolor = y * 256 / TEX_HEIGHT;
    		tex->xycolor = y * 128 / TEX_HEIGHT + x * 128 / TEX_WIDTH;
			// printf("tex->xorcolor: %d\ntex->ycolor: %d\ntex->xycolor: %d\n",
			// 	tex->xorcolor, tex->ycolor, tex->xycolor);
			// once ok with these values, decomment in render() t_screen and tex_buff
			convert = TEX_WIDTH * y + x;
			textures[0][convert] = 65536 * 254 * (x != y && x != TEX_WIDTH - y); //flat red texture with black cross
			textures[1][convert] = tex->xycolor + 256 * tex->xycolor + 65536 * tex->xycolor; //sloped greyscale
			textures[2][convert] = 256 * tex->xycolor + 65536 * tex->xycolor; //sloped yellow gradient
			textures[3][convert] = tex->xorcolor + 256 * tex->xorcolor + 65536 * tex->xorcolor; //xor greyscale
			textures[4][convert] = 256 * tex->xorcolor; //xor green
			textures[5][convert] = 65536 * 192 * (x % 16 && y % 16); //red bricks
			textures[6][convert] = 65536 * tex->ycolor; //red gradient
			textures[7][convert] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
		}
	}
	// ---
	
	// load_texture(data, textures[0], "../assets/eagle.xpm");

	// real textures version, have only 4 !, so doublon
	// unsigned long tw, th;
	// load_image(textures[0], tw, th, "../assets/eagle.xpm");
	// load_image(textures[1], tw, th, "../assets/bluestone.xpm");
	// load_image(textures[2], tw, th, "../assets/barrel.xpm");
	// load_image(textures[3], tw, th, "../assets/colorstone.xpm");
	// load_image(textures[4], tw, th, "../assets/eagle.xpm"); //same twice
	// load_image(textures[5], tw, th, "../assets/bluestone.xpm");
	// load_image(textures[6], tw, th, "../assets/barrel.xpm");
	// load_image(textures[7], tw, th, "../assets/colorstone.xpm");
	// mlx_xpm_file_to_image(data->mlx.mlx_co, pathname, tw, th);
}

void	draw_tex_buff(t_data *data, u_int32_t tex_buff[S_HEIGHT][S_WIDTH])
{
	int	x;
	int	y;

	y = -1;
	while (++y < S_HEIGHT)
	{
		x = -1;
		while(++x < S_WIDTH)
		{
			if (tex_buff[y][x] != 0)
				my_mlx_pixel_put(data, x, y, tex_buff[y][x]);
		}
	}
}

void	clear_tex_buff(t_data* data, u_int32_t tex_buff[S_HEIGHT][S_WIDTH])
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

void	render(t_data *data)
{
	t_mlx		*mlx;
	t_screen	*screen;

	mlx = &data->mlx;
	screen = &data->screen;
	screen->x = 0;
	screen->y = 0;

	u_int32_t	tex_buff[S_HEIGHT][S_WIDTH];
	int			textures[TEX_NUM][TEX_HEIGHT * TEX_WIDTH];
	// cls for each single vert lines
	// clear_lines(data);

	// to clear by replacing by 0 all pixels of the 2D tex_buff prev filled by colors(from texturing_vert_line)
	clear_tex_buff(data, tex_buff);
	data->time.curr = get_ticks();
	// generate textures based on 2d flat texture generator
	generate_textures(data, textures); //#TODO
	// ray-casting loop on width screen
	while (screen->x < S_WIDTH)
	{
		draw_my_pixel_line(data, textures, tex_buff);
		screen->x++;
	}

	// draw tex_buff here
	draw_tex_buff(data, tex_buff);
	get_time_frames(data);

	// speed_modifiers(move & rotating hooks)
	speed_modifiers(data);

	// put fully drawn image to window
	mlx_put_image_to_window(mlx->mlx_co, mlx->mlx_win,
		data->img.img_ptr, 0, 0);
}
