/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:26:00 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/03/16 23:47:14 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//open pipe, fork(child process) cmd
void    exec_first_cmd(t_data *data, t_cmd *cmd, char **envp)
{
    pid_t   pid;
    data->is_first_cmd = 0;

    if (pipe(cmd->fd) == -1)    //1. pipe(fds) - pipe fds(read, write), need 2 close()
        handle_errors(data, NULL, PIPE_ERR);
    pid = fork();               //2. fork() - child process
    if (pid == -1)
        handle_errors(data, NULL, FORK_ERR);
    else if (pid == 0)
    {
        close(cmd->fd[0]);
        data->infile = open(data->file_names[0], O_RDONLY);
        if (data->infile == -1)
            handle_errors(data, NULL, OPEN_FILE_ERR);
        dup2(data->infile, STDIN_FILENO);
        close(data->infile);
        dup2(cmd->fd[1], STDOUT_FILENO);
        close(cmd->fd[1]);
        execve(cmd->path, cmd->args, envp);
    }
    // else
    //     waitpid(pid);
}

void    exec_mid_cmd(t_data *data, t_cmd *cmd, char **envp)
{
    //open pipe, based on prev cmd
}

void    exec_last_cmd(t_data *data, t_cmd *cmd, char **envp)
{
    //not open pipe, based on prev cmd
}

void    exec_here_doc(t_data *data, char **envp)
{
    //...
}
