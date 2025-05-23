/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:26:00 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/03/19 02:48:11 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exec_first_cmd(t_data *data, t_cmd *cmd, char **envp)
{
	pid_t	pid;
	char	*path;

	data->is_first_cmd = 0;
	path = NULL;
	pid = fork();
	if (pid == -1)
		handle_errors(data, NULL, -1, NULL);
	else if (pid == 0)
	{
		path = check_path(data, cmd->args[0]);
		if (!path)
			handle_errors(data, cmd->args[0], PATH_ERR, path);
		close(data->pipe_fd[0]);
		data->infile = open(data->file_names[0], O_RDONLY);
		if (data->infile == -1)
			handle_errors(data, NULL, OPEN_FILE_ERR, path);
		dup2(data->infile, STDIN_FILENO);
		close(data->infile);
		dup2(data->pipe_fd[1], STDOUT_FILENO);
		close(data->pipe_fd[1]);
		execve(path, cmd->args, envp);
		handle_errors(data, NULL, -1, NULL);
	}
}

void	exec_last_cmd(t_data *data, t_cmd *cmd, char **envp)
{
	pid_t	pid;
	char	*path;

	path = NULL;
	pid = fork();
	if (pid == -1)
		handle_errors(data, NULL, -1, NULL);
	else if (pid == 0)
	{
		path = check_path(data, cmd->args[0]);
		if (!path)
		{
			printf("test");
			handle_errors(data, NULL, PATH_ERR, path);
		}
		close(data->pipe_fd[1]);
		dup2(data->pipe_fd[0], STDIN_FILENO);
		close(data->pipe_fd[0]);
		data->outfile = open(data->file_names[1],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (data->outfile == -1)
			handle_errors(data, NULL, OPEN_FILE_ERR, path);
		dup2(data->outfile, STDOUT_FILENO);
		close(data->outfile);
		execve(path, cmd->args, envp);
		handle_errors(data, NULL, -1, path);
	}
}
