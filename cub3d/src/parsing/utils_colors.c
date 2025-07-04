/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:56:29 by pamallet          #+#    #+#             */
/*   Updated: 2025/07/04 15:55:07 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_isspace(const char c)
{
	return (c == ' ');
}

int	check_before_rgb(char *line, int i)
{
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] && !ft_isdigit(line[i]) && ft_strcmp(&line[i], "\n"))
		return (printf("Error\nInvalid char detected in color\n"), -1);
	return (i);
}

int	check_rgb_during(t_data *data, char identifier, int i)
{
	if (check_duplicates(identifier, data) == -1)
		return (-1);
	if (get_color(data, data->parsing.file[i]) == -1)
		return (-1);
	return (0);
}

int	check_empty_line(t_data *data, int i)
{
	int	j;

	j = 0;
	if (i == data->parsing.file_line_number)
	{
		if (ft_strlen(data->parsing.file[i - 1]) == 0)
			return (0);
	}
	while (data->parsing.file[i][j] == '\n')
		j++;
	if (j == 0)
	{
		data->parsing.is_empty = 0;
		return (-1);
	}
	return (0);
}

int	check_components(t_data *data, char *line)
{
	int		i;
	int		j;

	j = 0;
	i = check_before_rgb(line, 1);
	if (i == -1)
		return (-1);
	while (line[i])
	{
		data->components[j] = ft_atoi(&line[i]);
		j++;
		while (line[i] && ft_isdigit(line[i]))
			i++;
		if (line[i] && line[i] == ',' && j < 3)
			i++;
		if (line[i] && !ft_isdigit(line[i]))
			break ;
		if (!line[i])
			break ;
	}
	if (j != 3)
		return (printf("Error\ncolor must have 3 components\n"), -1);
	return (i);
}
