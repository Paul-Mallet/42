/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:50:26 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/30 16:51:58 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_valid_char(char c)
{
	return (c == '1' || c == ' ' || c == 'V');
}

void	fill_tab(int *di, int *dj)
{
	di[0] = -1;
	di[1] = -1;
	di[2] = 0;
	di[3] = 1;
	di[4] = 1;
	di[5] = 1;
	di[6] = 0;
	di[7] = -1;
	dj[0] = 0;
	dj[1] = 1;
	dj[2] = 1;
	dj[3] = 1;
	dj[4] = 0;
	dj[5] = -1;
	dj[6] = -1;
	dj[7] = -1;
}

static int	check_neighbor(t_data *data, int i, int j, int dir)
{
	int	di[8];
	int	dj[8];
	int	new_i;
	int	new_j;
	int	len;

	fill_tab(di, dj);
	new_i = i + di[dir];
	new_j = j + dj[dir];
	if (new_i < 0 || new_i >= data->parsing.map_line_number)
		return (0);
	len = ft_strlen(data->parsing.map[new_i]);
	if (new_j < 0 || new_j >= len)
		return (0);
	if (!is_valid_char(data->parsing.map[new_i][new_j]))
		return (-1);
	if (data->parsing.map[new_i][new_j] == ' ')
		return (check_space(data, new_i, new_j));
	return (0);
}

int	check_space(t_data *data, int i, int j)
{
	int	len;

	if (i < 0 || i >= data->parsing.map_line_number)
		return (-1);
	len = ft_strlen(data->parsing.map[i]);
	if (j < 0 || j >= len)
		return (-1);
	if (data->parsing.map[i][j] == 'V')
		return (0);
	if (data->parsing.map[i][j] != ' ')
		return (0);
	data->parsing.map[i][j] = 'V';
	if (check_neighbor(data, i, j, 0) == -1
		|| check_neighbor(data, i, j, 1) == -1
		|| check_neighbor(data, i, j, 2) == -1
		|| check_neighbor(data, i, j, 3) == -1
		|| check_neighbor(data, i, j, 4) == -1
		|| check_neighbor(data, i, j, 5) == -1
		|| check_neighbor(data, i, j, 6) == -1
		|| check_neighbor(data, i, j, 7) == -1)
		return (-1);
	return (0);
}

int	check_spaces(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->parsing.map[i])
	{
		j = 0;
		while (data->parsing.map[i][j] && data->parsing.map[i][j] == ' ')
			j++;
		while (data->parsing.map[i][j])
		{
			if (data->parsing.map[i][j] == ' ')
				if (check_space(data, i, j) == -1)
					return (printf("Error\nCharacter %c at"
							" x : %d, y : %d is not surrounded by walls\n",
							data->parsing.map[i][j], j + 1, i + 1), -1);
			j++;
		}
		i++;
	}
	return (0);
}
