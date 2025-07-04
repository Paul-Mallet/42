/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:47:27 by bfiquet           #+#    #+#             */
/*   Updated: 2025/07/03 16:00:41 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
		if (data->parsing.map_int[grid->map_x][grid->map_y] > 0)
			grid->wall.is_hit = true;
	}
}

void	speed_modifiers(t_data *data)
{
	t_speed	*speed;

	speed = &data->speed;
	speed->mov = 0.005 * 5.0;
	speed->rot = 0.005 * 4.0;
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
	generate_textures(data, textures);
	floor_casting(data);
	while (screen->x < S_WIDTH)
	{
		draw_my_pixel_line(data, textures, tex_buff);
		screen->x++;
	}
	draw_tex_buff(data, tex_buff);
	speed_modifiers(data);
	mlx_put_image_to_window(mlx->mlx_co, mlx->mlx_win,
		data->img.img_ptr, 0, 0);
}
