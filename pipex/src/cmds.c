/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:42:05 by pamallet          #+#    #+#             */
/*   Updated: 2025/03/11 15:53:48 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_cmd	*new_cmd(char *args, char **env)
{
	t_cmd	*new;
	char	**paths;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->args = ft_split(args, ' '); //free all!
	paths = get_paths(env);
	new->path = find_path(paths, new->args[0]);
	new->fd[0] = -1;
	new->fd[1] = -1;
	return (new);
}

void	cmd_add_back(t_cmd **cmds, t_cmd *new)
{
	t_cmd	*current;

	if (!cmds || !new)
		return ;
	if (!*cmds)
	{
		*cmds = new;
		return ;
	}
	current = *cmds;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
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
