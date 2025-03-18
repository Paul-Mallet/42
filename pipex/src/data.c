/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:40:58 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/03/18 10:45:15 by paul_mallet      ###   ########.fr       */
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
	data->pipe_fd[0] = -1;
	data->pipe_fd[1] = -1;
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
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	curr = data->cmds;
    if (pipe(data->pipe_fd) == -1)
        handle_errors(data, NULL, PIPE_ERR);
	pid1 = fork();
	if (pid1 == -1)
		handle_errors(data, NULL, FORK_ERR);
    else if (pid1 == 0)
	{
		printf("test");
		data->infile = open(data->file_names[0], O_RDONLY);
		if (data->infile == -1)
			handle_errors(data, NULL, OPEN_FILE_ERR);
		dup2(data->infile, STDIN_FILENO);
		close(data->infile);

        dup2(data->pipe_fd[1], STDOUT_FILENO);
        close(data->pipe_fd[0]);
        close(data->pipe_fd[1]);

        execve(curr->path, curr->args, NULL);
		handle_errors(data, NULL, EXECVE_ERR);
    }

	curr = curr->next;

	pid2 = fork();
	if (pid2 == -1)
		handle_errors(data, NULL, FORK_ERR);
	else if (pid2 == 0)
	{
		dup2(data->pipe_fd[0], STDIN_FILENO);
        close(data->pipe_fd[0]);
        close(data->pipe_fd[1]);

        data->outfile = open(data->file_names[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (data->outfile == -1)
			handle_errors(data, NULL, OPEN_FILE_ERR);

        dup2(data->outfile, STDOUT_FILENO);
        close(data->outfile);
        execve(curr->path, curr->args, envp);
        handle_errors(data, NULL, EXECVE_ERR);
    }
    close(data->pipe_fd[0]);
    close(data->pipe_fd[1]);
    waitpid(pid1, &status, 0);
    waitpid(pid2, &status, 0);
}
