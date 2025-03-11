/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:05:55 by pamallet          #+#    #+#             */
/*   Updated: 2025/03/11 15:08:26 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**get_paths(char **env) //["PATH=/home/pamallet/bin:/home/pamallet/bin:..."]
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (ft_split(ft_strchr(env[i], '='), ':')); //+1 to skip =
	}
	return (NULL);
}

char	*construct_path(char *dir, char *cmd)
{
	char	*temp;
	char	*path;

	temp = ft_strjoin(dir, "/");
	path = NULL;
	if (temp)
	{
		path = ft_strjoin(temp, cmd);
		free(temp);
	}
	// free(temp);
	return (path);
}

char	*find_path(char **paths, char *cmd)
{
	int		i;
	char	*road;

	if (!cmd)
		return (NULL);
	if (ft_strchr(cmd, '/') && access(cmd, F_OK) == 0)
		return (ft_strdup(cmd));
	i = 0;
	while (paths[i])
	{
		road = construct_path(paths[i], cmd);
		if (road && access(road, X_OK) == 0)
			return (road);
		free(road);
		i++;
	}
	return (NULL);
}
