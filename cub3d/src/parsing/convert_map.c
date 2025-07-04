/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 08:58:13 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/07/04 12:36:45 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void	print_map_int(t_data *data)
// {
// 	int	x;
// 	int	y;

// 	x = -1;
// 	while (++x < data->parsing.map_line_number)
// 	{
// 		y = -1;
// 		while (data->parsing.map[x][++y])
// 			printf("%d", data->parsing.map_int[x][y]);
// 		printf("\n");
// 	}
// }
void	print_map_char(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	while (++x < data->parsing.map_line_number)
	{
		y = -1;
		while (++y < data->parsing.map_col_number)
			printf("%c", data->parsing.map[x][y]);
		printf("\n");
	}
}

static void	malloc_rows(t_data *data, int rows)
{
	data->parsing.map_int = (int **)malloc(rows * sizeof(int *));
	if (!data->parsing.map_int)
		handle_err("Error\nMalloc failed\n", data);
}

static void	malloc_cols(t_data *data, int rows)
{
	int	x;
	int	y;

	x = -1;
	while (++x < rows)
	{
		y = 0;
		while (data->parsing.map[x][y])
			y++;
		data->parsing.map_int[x] = (int *)malloc(y * sizeof(int));
		if (!data->parsing.map_int[x])
			handle_err("Error\nMalloc failed\n", data);
	}
}

// full fill empty(space already handle) in char** map;
// cause [x][y] try to access NULL value on shorter row's map
// = cubic / rect map
void	convert_map_to_int(t_data *data)
{
	int	x;
	int	y;
	int	rows;
	int	char_cell;

	rows = data->parsing.map_line_number;
	malloc_rows(data, rows);
	malloc_cols(data, rows);
	x = -1;
	while (++x < rows)
	{
		y = -1;
		while (data->parsing.map[x][++y])
		{
			char_cell = data->parsing.map[x][y];
			if (char_cell == 'N' || char_cell == 'S'
				|| char_cell == 'E' || char_cell == 'W')
				data->parsing.map_int[x][y] = 0;
			else if (char_cell == ' ')
				data->parsing.map_int[x][y] = 2;
			else
				data->parsing.map_int[x][y] = char_cell - '0';
		}
	}
}
