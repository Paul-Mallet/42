/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:59:24 by bfiquet           #+#    #+#             */
/*   Updated: 2025/07/03 18:36:10 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_errors(t_data *data)
{
	if (get_textures_and_colors(data) == -1
		|| verif_textures(data) == -1
		|| check_player(data) == -1
		|| check_player_surrounded(data) == -1)
		return (-1);
	if (check_letter(data) == -1)
		return (ft_printf("Error\nInvalid char detected\n"), -1);
	return (0);
}

static void	init_mlx(t_data *data)
{
	data->mlx.name = "cub3d_screen";
	data->mlx.mlx_co = mlx_init();
	if (!data->mlx.mlx_co)
		handle_err("Error\nMalloc failed\n", data);
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx_co,
			S_WIDTH, S_HEIGHT, data->mlx.name);
	if (!data->mlx.mlx_win)
	{
		mlx_destroy_display(data->mlx.mlx_co);
		free(data->mlx.mlx_co);
		handle_err("Error\nMalloc failed\n", data);
	}
	data->img.img_ptr = mlx_new_image(data->mlx.mlx_co, S_WIDTH, S_HEIGHT);
	if (!data->img.img_ptr)
	{
		mlx_destroy_window(data->mlx.mlx_co, data->mlx.mlx_win);
		mlx_destroy_display(data->mlx.mlx_co);
		free(data->mlx.mlx_win);
		free(data->mlx.mlx_co);
		handle_err("Error\nMalloc failed\n", data);
	}
	data->img.addr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.bpp, &data->img.line_len, &data->img.endian);
}

static int	init_data(t_data *data, char **argv)
{
	data->parsing.is_empty = 1;
	data->parsing.text_ea = NULL;
	data->parsing.text_we = NULL;
	data->parsing.text_no = NULL;
	data->parsing.text_so = NULL;
	data->parsing.img_ea = NULL;
	data->parsing.img_we = NULL;
	data->parsing.img_no = NULL;
	data->parsing.img_so = NULL;
	data->parsing.player_x = 0;
	data->parsing.player_y = 0;
	data->parsing.map = NULL;
	data->parsing.file = NULL;
	data->parsing.orientation = NULL;
	data->parsing.player_count = 0;
	data->parsing.file_line_number = count_lines(argv[1], data);
	if (data->parsing.file_line_number == -1)
		return (1);
	data->parsing.color_c = -1;
	data->parsing.color_f = -1;
	init_mlx(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (printf("Error\nInvalid arguments\n"));
	if (init_data(&data, argv) == 1)
		return (1);
	if (!check_format(argv[1]))
		return (close_game(&data), 1);
	read_file(argv[1], &data);
	if (check_errors(&data) == -1)
		return (close_game(&data), 1);
	data.parsing.map_col_number = count_cols(&data);
	if (check_walls(&data) == -1)
		return (close_game(&data));
	init(&data);
	render(&data);
	mlx_hook(data.mlx.mlx_win,
		DestroyNotify, StructureNotifyMask, &handle_close, &data);
	mlx_hook(data.mlx.mlx_win,
		KeyPress, KeyPressMask, &handle_keys_press, &data);
	mlx_hook(data.mlx.mlx_win,
		KeyRelease, KeyReleaseMask, &handle_keys_release, &data);
	mlx_loop_hook(data.mlx.mlx_co, &handle_keys, &data);
	mlx_loop(data.mlx.mlx_co);
	return (0);
}
