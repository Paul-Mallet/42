/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:27:20 by bfiquet           #+#    #+#             */
/*   Updated: 2025/07/04 15:55:01 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_color(t_data *data, int *components, char identifier)
{
	unsigned int	color;
	int				i;

	i = 0;
	while (i < 3)
	{
		if (components[i] < 0 || components[i] > 255)
			return (printf("Error\nColor value %d must be between 0 and 255\n",
					components[i]), -1);
		i++;
	}
	color = (components[0] << 16) | (components[1] << 8) | components[2];
	if (identifier == 'C' && data->parsing.color_c == -1)
		data->parsing.color_c = color;
	if (identifier == 'F' && data->parsing.color_f == -1)
		data->parsing.color_f = color;
	return (0);
}

int	get_color(t_data *data, char *line)
{
	int	i;

	i = check_components(data, line);
	if (i == -1)
		return (-1);
	while (ft_isspace(line[i]))
		i++;
	if (line[i] && !ft_isspace(line[i]) && ft_strcmp(&line[i], "\n"))
		return (printf("Error\nInvalid char detected in color\n"), -1);
	if (check_color(data, data->components, line[0]) == -1)
		return (-1);
	return (0);
}

static int	set_texture(char **split, char *trim, char **tex, char *name)
{
	char	*tmp;

	if (*tex)
	{
		free_tab(split);
		free(trim);
		ft_printf("Error\nDuplicate %s texture\n", name);
		return (-1);
	}
	tmp = ft_strdup(trim);
	free(trim);
	if (!tmp)
	{
		free_tab(split);
		ft_printf("Error\nMalloc failed\n");
		return (-1);
	}
	*tex = tmp;
	free_tab(split);
	return (0);
}

int	get_texture(t_data *data, char *line)
{
	char	**split_line;
	char	*trimmed;

	split_line = ft_split(line, ' ');
	if (!split_line || !split_line[0] || !split_line[1] || split_line[2])
		return (ft_printf("Error\nInvalid texture line : %s\n", line),
			free_tab(split_line), -1);
	trimmed = ft_strtrim(split_line[1], "\n");
	if (!trimmed)
		return (ft_printf("Error\nMalloc failed\n"), free_tab(split_line), 1);
	if (ft_strcmp(split_line[0], "WE") == 0)
		return (set_texture(split_line, trimmed, &data->parsing.text_we, "WE"));
	if (ft_strcmp(split_line[0], "EA") == 0)
		return (set_texture(split_line, trimmed, &data->parsing.text_ea, "EA"));
	if (ft_strcmp(split_line[0], "NO") == 0)
		return (set_texture(split_line, trimmed, &data->parsing.text_no, "NO"));
	if (ft_strcmp(split_line[0], "SO") == 0)
		return (set_texture(split_line, trimmed, &data->parsing.text_so, "SO"));
	printf("Error\nUnknown texture identifier: %s\n", split_line[0]);
	free_tab(split_line);
	free(trimmed);
	return (-1);
}

int	get_textures_and_colors(t_data *data)
{
	int		i;
	char	identifier;

	i = 0;
	while (data->parsing.file[i])
	{
		identifier = data->parsing.file[i][0];
		if (identifier == 'C' || identifier == 'F')
		{
			if (check_rgb_during(data, identifier, i) == -1)
				return (-1);
		}
		else if (identifier == 'S' || identifier == 'N'
			|| identifier == 'W' || identifier == 'E')
		{
			if (get_texture(data, data->parsing.file[i]) == -1)
				return (-1);
		}
		else if (verif_values(data) && ft_strchr(data->parsing.file[i], '1'))
			return (read_map(data, i));
		else if (check_empty_line(data, i) == -1)
			break ;
		i++;
	}
	return (print_error(data), -1);
}
