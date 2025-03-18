/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:26:00 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/03/18 10:01:13 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//open pipe, fork(child process) cmd
// void    exec_first_cmd(t_data *data, t_cmd *cmd, char **envp)
// {
// 	pid_t   pid;
// 	// int     status;

// 	data->is_first_cmd = 0;
// 	if (pipe(data->pipe_fd) == -1)   //1. pipe(fds) - pipe fds(read, write), need 2 close()
// 		handle_errors(data, NULL, PIPE_ERR);
// 	pid = fork();               //2. fork() - child process
// 	if (pid == -1)
// 		handle_errors(data, NULL, FORK_ERR);
// 	else if (pid == 0)
// 	{
// 		close(data->pipe_fd[0]);
// 		data->infile = open(data->file_names[0], O_RDONLY);
// 		if (data->infile == -1)
// 			handle_errors(data, NULL, OPEN_FILE_ERR);
// 		dup2(data->infile, STDIN_FILENO);
// 		close(data->infile);
// 		dup2(data->pipe_fd[1], STDOUT_FILENO);
// 		close(data->pipe_fd[1]);
// 		execve(cmd->path, cmd->args, envp);
// 		handle_errors(data, NULL, EXECVE_ERR);
// 	}
// 	else
// 		wait(NULL);
// }

// void    exec_last_cmd(t_data *data, t_cmd *cmd, char **envp)
// {
// 	pid_t   pid;

// 	pid = fork();
// 	if (pid == -1)
// 		handle_errors(data, NULL, FORK_ERR);
// 	else if (pid == 0)
// 	{
// 		print_data(data);
// 		close(data->pipe_fd[1]);
// 		data->outfile = open(data->file_names[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 		if (data->outfile == -1)
// 			handle_errors(data, NULL, OPEN_FILE_ERR);
// 		dup2(data->outfile, STDOUT_FILENO);
// 		close(data->outfile);
// 		dup2(data->pipe_fd[0], STDIN_FILENO);
//         close(data->pipe_fd[0]);
// 		execve(cmd->path, cmd->args, envp);
// 		handle_errors(data, NULL, EXECVE_ERR);
// 	}
// 	else
// 		wait(NULL);
// }

// void    exec_mid_cmd(t_data *data, t_cmd *cmd, char **envp)
// {
// 	//open pipe, based on prev cmd
// }

// void    exec_here_doc(t_data *data, char **envp)
// {
// 	//...
// }
