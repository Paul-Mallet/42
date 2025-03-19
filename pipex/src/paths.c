/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:05:55 by pamallet          #+#    #+#             */
/*   Updated: 2025/03/19 00:31:22 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*construct_path(char *dir, char *cmd)
{
	char	*temp;
	char	*path;

	temp = ft_strjoin(dir, "/");
	if (!temp)
		return (NULL);
	path = ft_strjoin(temp, cmd);
	free(temp);
	return (path);
}

int	is_executable(t_data *data, char *cmd)
{
	if (access(cmd, F_OK) != 0)
	{
		close_pipe(data);
		handle_errors(data, NULL, -1);
	}
	else if (access(cmd, X_OK) != 0)
	{
		close_pipe(data);
		handle_errors(data, NULL, -1);
	}
	return (1);
}

char	*find_path(char **paths, char *cmd)
{
	char	*road;
	int		i;

	i = -1;
	while (paths[++i])
	{
		road = construct_path(paths[i], cmd);
		if (access(road, X_OK) == 0)
			return (road);
		free(road);
	}
	return (NULL);
}

char	*check_path(t_data *data, char *cmd)
{
	if (!cmd)
		return (NULL);
	if (!data->paths)
	{
		if (is_executable(data, cmd))
			return (cmd);
		return (NULL);
	}
	if (ft_strchr(cmd, '/'))
	{
		if (is_executable(data, cmd))
			return (cmd);
		return (NULL);
	}
	return (find_path(data->paths, cmd));
}

void	get_paths(t_data *data, char **envp)
{
	char	*skip_key;
	int		i;

	i = -1;
	skip_key = NULL;
	if (!envp)
		return ;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			skip_key = ft_strchr(envp[i], '=');
			data->paths = ft_split(skip_key + 1, ':');
			return ;
		}
	}
}
