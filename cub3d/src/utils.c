/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:59:38 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/30 16:21:08 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_textures_and_images(t_data *data)
{
	if (data->parsing.text_we)
		free(data->parsing.text_we);
	if (data->parsing.text_ea)
		free(data->parsing.text_ea);
	if (data->parsing.text_no)
		free(data->parsing.text_no);
	if (data->parsing.text_so)
		free(data->parsing.text_so);
	if (data->parsing.img_ea)
		mlx_destroy_image(data->mlx.mlx_co, data->parsing.img_ea);
	if (data->parsing.img_so)
		mlx_destroy_image(data->mlx.mlx_co, data->parsing.img_so);
	if (data->parsing.img_no)
		mlx_destroy_image(data->mlx.mlx_co, data->parsing.img_no);
	if (data->parsing.img_we)
		mlx_destroy_image(data->mlx.mlx_co, data->parsing.img_we);
	data->parsing.text_we = NULL;
	data->parsing.text_ea = NULL;
	data->parsing.text_no = NULL;
	data->parsing.text_so = NULL;
}

//	if (data->parsing.map_int)
// 		free_map_int(data);
// 	mlx_destroy_image(data->mlx.mlx_co, data->img.img_ptr);
// 	mlx_destroy_window(data->mlx.mlx_co, data->mlx.mlx_win);
// 	mlx_destroy_display(data->mlx.mlx_co);
// 	free(data->mlx.mlx_co);
// 	exit(EXIT_SUCCESS);
int	close_game(t_data *data)
{
	if (data->parsing.orientation)
		free(data->parsing.orientation);
	if (data->parsing.map)
		free_tab(data->parsing.map);
	if (data->parsing.file)
		free_tab(data->parsing.file);
	free_textures_and_images(data);
	mlx_destroy_image(data->mlx.mlx_co, data->img.img_ptr);
	mlx_destroy_window(data->mlx.mlx_co, data->mlx.mlx_win);
	mlx_destroy_display(data->mlx.mlx_co);
	free(data->mlx.mlx_co);
	exit(0);
	return (0);
}
