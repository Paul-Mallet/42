/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:40:58 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/03/19 00:46:16 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	init_data(t_data *data)
{
	data->cmds = NULL;
	data->paths = NULL;
	data->file_names[0] = NULL;
	data->file_names[1] = NULL;
	data->is_first_cmd = 1;
	data->pipe_fd[0] = -1;
	data->pipe_fd[1] = -1;
}

void	fill_data(t_data *data, int ac, char **av, char **envp)
{
	init_cmds(data, ac, av);
	data->file_names[0] = ft_strdup(av[1]);
	data->file_names[1] = ft_strdup(av[ac - 1]);
	get_paths(data, envp);
}

void	close_pipe(t_data *data)
{
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
}

void	wait_forks(t_data *data)
{
	t_cmd	*curr;

	curr = data->cmds;
	while (curr)
	{
		wait(NULL);
		curr = curr->next;
	}
}

void	exec_data(t_data *data, char **envp)
{
	t_cmd	*curr;

	if (pipe(data->pipe_fd) == -1)
		handle_errors(data, NULL, -1);
	curr = data->cmds;
	while (curr)
	{
		if (data->is_first_cmd)
			exec_first_cmd(data, curr, envp);
		else
			exec_last_cmd(data, curr, envp);
		curr = curr->next;
	}
	close_pipe(data);
	wait_forks(data);
}
