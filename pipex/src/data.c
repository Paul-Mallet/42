/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:40:58 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/03/16 23:23:10 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	init_data(t_data *data)
{
	data->cmds = NULL;
	data->delim = NULL;
	data->file_names[0] = NULL;
	data->file_names[1] = NULL;
	data->is_here_doc = 0;
	data->is_first_cmd = 1;
}

void    fill_data(t_data *data, int ac, char **av, char **env)
{
	init_cmds(data, ac, av, env);
	if (!ft_strcmp(av[1], "here_doc"))
	{
		data->delim = ft_strdup(av[1]);
		data->file_names[1] = ft_strdup(av[ac - 1]);
		data->is_here_doc = 1;
	}
	else
	{
		data->file_names[0] = ft_strdup(av[1]);
		data->file_names[1] = ft_strdup(av[ac - 1]);
	}
	init_paths(data);
}

//start, end || start, mid, end based on cmds->next
void	exec_data(t_data *data, char **envp)
{
	t_cmd	*curr;

	curr = data->cmds;
	if (data->is_here_doc)
		exec_here_doc(data, envp);
	else
	{
		while (curr)
		{
			if (data->is_first_cmd)
				exec_first_cmd(data, curr, envp);	//change bool in this function
			else if (!curr->next)
				exec_last_cmd(data, curr, envp);
			else
				exec_mid_cmd(data, curr, envp);
			curr = curr->next;
		}
	}
}
