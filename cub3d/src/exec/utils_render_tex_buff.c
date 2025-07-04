/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render_tex_buff.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:16:43 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/28 10:07:46 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(unsigned int *)dst = color;
}

void	clear_lines(t_data *data)
{
	ft_memset(data->img.addr, 0, S_HEIGHT * data->img.line_len);
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
