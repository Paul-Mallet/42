/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:42:05 by pamallet          #+#    #+#             */
/*   Updated: 2025/03/16 20:23:18 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_cmd	*init_cmd(void)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->args = NULL;
	new->path = NULL;
	new->fd[0] = -1;
	new->fd[1] = -1;
	return (new);
}

void	fill_cmd(t_cmd *new, char *args, char **env)
{
	new->next = NULL;
	new->args = ft_split(args, ' ');	//"ls -l" -> ["ls", "-l", NULL]
	new->paths = get_paths(env);		//"...:...:..." -> ["...", "...", NULL]
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

void	init_cmds(t_data *data, int ac, char **av, char **env)
{
	t_cmd	*head;
	t_cmd	*new;
	int		i;

	head = NULL;
	new = NULL;
	i = 1;
	while(++i < ac - 1) //not [1] & [ac - 1] -> files
	{
		new = init_cmd();
		if (!new)
			return (NULL);
		fill_cmd(new, av[i], env);
		cmd_add_back(&head, new);
	}
	data->cmds = head;
}
