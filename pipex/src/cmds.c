/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:42:05 by pamallet          #+#    #+#             */
/*   Updated: 2025/03/09 19:51:30 by pamallet         ###   ########.fr       */
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

t_cmd	*new_cmd(char *args, char **env)
{
	t_cmd	*new;
	char	**paths;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->args = ft_split(args, ' ');
	paths = get_paths(env);
	new->path = find_path(paths, new->args[0]);
	new->fd[0] = -1;
	new->fd[1] = -1;
	return (new);
}

t_cmd	*init_cmds(int ac, char **av, char **env)
{
	t_cmd	*head;
	t_cmd	*new;
	int		i;

	head = NULL;
	new = NULL;
	i = 1;
	while(++i < ac - 1) //not [1] & [ac - 1] -> files
	{
		new = new_cmd(av[i], env);
		cmd_add_back(&head, new);
		print_args(new->args);
	}
	return (head);
}
