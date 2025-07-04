/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiquet <bfiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:07:37 by bfiquet           #+#    #+#             */
/*   Updated: 2025/07/04 15:16:20 by bfiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line [i] != ' ')
			return (printf("Error\nLast line is not closed\n"), 0);
		i++;
	}
	return (1);
}

int	flood_fill(int x, int y, t_fill_data *fill)
{
	int	len;

	len = ft_strlen(fill->map[y]);
	if (x < 0 || y < 0 || x >= len || y >= fill->rows)
		return (-1);
	if (fill->map[y][x] == '1' || fill->map[y][x] == 'V')
		return (0);
	if (fill->map[y][x] == ' ')
		return (-1);
	fill->map[y][x] = 'V';
	if (flood_fill(x + 1, y, fill) == -1
		|| flood_fill(x - 1, y, fill) == -1
		|| flood_fill(x, y + 1, fill) == -1
		|| flood_fill(x, y - 1, fill) == -1
		|| flood_fill(x + 1, y + 1, fill) == -1
		|| flood_fill(x - 1, y - 1, fill) == -1
		|| flood_fill(x - 1, y + 1, fill) == -1
		|| flood_fill(x + 1, y - 1, fill) == -1)
		return (-1);
	return (0);
}

int	init_fill(t_data *data, t_fill_data	*fill)
{
	char		**map_copy;
	int			i;

	map_copy = malloc(sizeof(char *) * (data->parsing.map_line_number + 2));
	if (!map_copy)
	{
		fill->map = NULL;
		return (1);
	}
	i = 0;
	while (data->parsing.map[i])
	{
		map_copy[i] = ft_strdup(data->parsing.map[i]);
		i++;
	}
	map_copy[i] = NULL;
	fill->map = map_copy;
	fill->rows = data->parsing.map_line_number;
	fill->cols = data->parsing.map_col_number;
	return (0);
}

int	check_walls(t_data *data)
{
	int			i;
	int			j;
	t_fill_data	fill;

	if (!check_line(data->parsing.map[data->parsing.map_line_number - 1])
		|| check_spaces(data) == -1 || init_fill(data, &fill) == 1)
		return (-1);
	i = 0;
	while (fill.map[i])
	{
		j = 0;
		while (fill.map[i][j])
		{
			if (fill.map[i][j] == '0')
			{
				if (flood_fill(j, i, &fill) == -1)
					return (printf("Error\nMap is not closed\n"),
						free_tab(fill.map), -1);
			}
			j++;
		}
		i++;
	}
	return (free_tab(fill.map), 0);
}
