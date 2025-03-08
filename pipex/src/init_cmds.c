/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:42:05 by pamallet          #+#    #+#             */
/*   Updated: 2025/03/08 15:47:14 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_cmd	*new_cmd(char **cmds)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->args = cmds;
	new->fd[0] = -1;
	new->fd[1] = -1;
	return (new);
}

t_cmd	*init_cmds(char **av)
{
	char	**cmd;
	char	**args;
	t_cmd	*head;
	t_cmd	*new;
	int		i;

	cmd = NULL;
	args = NULL;
	head = NULL;
	new = NULL;
	i = 0;
	while(av[++i])
	{
		cmd = malloc_cmd(av[i]); //only malloc by calculating len ""
		if (!cmd)
			return (NULL);
		args = build_cmd(av[i], cmd);
		new = new_cmd(args);
		cmd_struct_add_back(&head, new);
		print_cmd(new->args);
	}
	return (head);
}
