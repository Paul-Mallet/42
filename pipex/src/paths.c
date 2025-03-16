/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:05:55 by pamallet          #+#    #+#             */
/*   Updated: 2025/03/16 12:05:50 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**get_paths(char **env) //["PATH=/home/pamallet/bin:/home/pamallet/bin:..."]
{
	char	*skip_key;
	int		i;

	i = -1;
	skip_key = NULL;
	while (env[++i])
	{
		skip_key = ft_strchr(env[i], '=');
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (ft_split(skip_key + 1, ':'));
	}
	return (NULL);
}

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

int	find_path_cmd(t_data *data, char *cmd)
{
	if (ft_strchr(cmd, '/') && access(cmd, F_OK) == -1)
		handle_errors(data, cmd, NO_SUCH_FILE_ERR);
	else if (!ft_strchr(cmd, '/'))
		return (0);
	return (1);
}

void	not_find_cmd(t_data *data, char *road, char *cmd)
{
	if (access(road, F_OK) == -1)
	{
		free(road);
		handle_errors(data, cmd, NOT_FOUND_ERR);
	}
}

void	not_perm_cmd(t_data *data, char *road, char *cmd)
{
	if (access(road, X_OK) == -1)
	{
		free(road);
		handle_errors(data, cmd, PERMISSION_ERR);
	}
}

void	not_find_path(t_data *data, char *road, char *cmd)
{
	not_find_cmd(data, road, cmd);
	not_perm_cmd(data, road, cmd);
}

char	*find_path(t_data *data, char **paths, char *cmd)
{
	char	*road;
	int		i;

	if (!paths || !cmd)
		return (NULL);	//malloc error
	if (find_path_cmd(data, cmd))
		return (ft_strdup(cmd)); //ready to exec, free!
	i = -1;
	while (paths[++i])
	{
		road = construct_path(paths[i], cmd);
		if (!road)
			return (NULL);	//malloc error
		if (access(road, X_OK) == 0)	//ready to exec, free!
			return (road);
		if (!(paths[i + 1]))
			not_find_path(data, road, cmd);
		free(road);
	}
	return (NULL);
}

void	init_paths(t_data *data)
{
	t_cmd	*curr;

	curr = data->cmds;	//["ls -l", "cmd2", "cmd3", NULL]
	while (curr)
	{
		curr->path = find_path(data, curr->paths, curr->args[0]); //always ls
		curr = curr->next;
	}
}
