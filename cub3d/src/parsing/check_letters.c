/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_letters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:35:23 by bfiquet           #+#    #+#             */
/*   Updated: 2025/06/28 09:31:38 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!check_char(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_char(char c)
{
	if (c == '0' || c == '1' || check_player_char(c))
		return (1);
	return (0);
}

int	check_letter(t_data *data)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = data->parsing.map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			while (map[i][j] && map[i][j] == ' ')
				j++;
			if (!map[i][j])
				break ;
			if (map[i][j] && !check_char(map[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
