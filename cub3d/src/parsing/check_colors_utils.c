/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiquet <bfiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:58:24 by bfiquet           #+#    #+#             */
/*   Updated: 2025/07/04 15:16:01 by bfiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_duplicates(char identifier, t_data *data)
{
	if (identifier == 'C' && data->parsing.color_c != -1)
		return (printf("Error\nDuplicate ceiling color\n"), -1);
	else if (identifier == 'F' && data->parsing.color_f != -1)
		return (printf("Error\nDuplicate floor color\n"), -1);
	return (0);
}

int	verif_values(t_data *data)
{
	if (data->parsing.color_c == -1 || data->parsing.color_f == -1)
		return (0);
	if (!data->parsing.text_ea || !data->parsing.text_we
		|| !data->parsing.text_no || !data->parsing.text_so)
		return (0);
	return (1);
}

int	print_error(t_data *data)
{
	if (!data->parsing.is_empty)
		return (printf("Error\nFound invalid non empty line\n"), 1);
	if (data->parsing.color_c == -1)
		return (printf("Error\nCeiling color not found\n"), -1);
	if (data->parsing.color_f == -1)
		return (printf("Error\nFloor color not found\n"), -1);
	if (!data->parsing.text_no)
		return (printf("Error\nNorth texture not found\n"), -1);
	if (!data->parsing.text_so)
		return (printf("Error\nSouth texture not found\n"), -1);
	if (!data->parsing.text_ea)
		return (printf("Error\nEast texture not found\n"), -1);
	if (!data->parsing.text_we)
		return (printf("Error\nWest texture not found\n"), -1);
	if (!data->parsing.is_empty)
		return (printf("Error\nFound invalid non empty line\n"), -1);
	return (0);
}
