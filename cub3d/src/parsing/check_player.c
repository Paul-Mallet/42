/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:26:16 by bfiquet           #+#    #+#             */
/*   Updated: 2025/07/03 16:24:49 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_orientation(t_data *data, char c, int x, int y)
{
	data->parsing.player_x = x;
	data->parsing.player_y = y;
	if (c == 'N')
		data->parsing.orientation = ft_strdup("North");
	if (c == 'S')
		data->parsing.orientation = ft_strdup("South");
	if (c == 'E')
		data->parsing.orientation = ft_strdup("East");
	if (c == 'W')
		data->parsing.orientation = ft_strdup("West");
}

int	check_player_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	check_player_surrounded(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->parsing.map[++i])
	{
		j = -1;
		while (data->parsing.map[i][++j])
		{
			if (check_player_char(data->parsing.map[i][j]))
			{
				if (i == 0 || j == 0 || !data->parsing.map[i + 1]
					|| !data->parsing.map[i][j + 1])
					return (printf("Error\nPlayer at the "
							"edge of the map\n"), -1);
				if (data->parsing.map[i - 1][j] == ' '
					|| data->parsing.map[i + 1][j] == ' '
					|| data->parsing.map[i][j - 1] == ' '
					|| data->parsing.map[i][j + 1] == ' ')
					return (printf("Error\nPlayer is not "
							"properly surrounded\n"), -1);
			}
		}
	}
	return (0);
}

int	check_player_count(t_data *data)
{
	if (data->parsing.player_count != 1)
	{
		printf("Error\nNo player found\n");
		return (-1);
	}
	return (0);
}

int	check_player(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->parsing.map[++i])
	{
		j = -1;
		while (data->parsing.map[i][++j])
		{
			if (data->parsing.map[i][j]
				&& check_player_char(data->parsing.map[i][j])
				&& data->parsing.player_count == 1)
				return (printf("Error\nToo many players\n"), -1);
			if (data->parsing.map[i][j]
				&& check_player_char(data->parsing.map[i][j]))
			{
				data->parsing.player_count++;
				get_orientation(data, data->parsing.map[i][j], i, j);
			}
		}
	}
	return (check_player_count(data));
}
