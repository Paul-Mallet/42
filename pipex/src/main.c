/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:40:53 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/03/16 17:40:53 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*
	To do:
	./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
	< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2

	./pipex here_doc DELIM cmd cmd1 file
	cmd << LIMITER | cmd1 >> file

	Files handlers
	int open(const char *path, int flags, mode_t mode);
	int close(int fd);
	ssize_t read(int fd, void *buf, size_t count);
	ssize_t write(int fd, const void *buf, size_t count); //ft_strlen();
	int access(const char *path, int mode);
	int unlink(const char *path);
	
	Memory handlers
	void *malloc(size_t size);
	void free(void *ptr);

	Error handlers
	void perror(const char *s);
	char *strerror(int errnum);

	Inter-process
	int pipe(int pipefd[2]);
	
	Redirection fds
	int dup(int oldfd);
	int dup2(int oldfd, int newfd);

	Exec cmds
	int execve(const char *path, char **const argv, char **const envp);
	
	Process handlers
	pid_t fork(void);
	pid_t wait(int *wstatus);
	pid_t waitpid(pid_t pid, int *wstatus, int options);
	void exit(int status);
	
	
	How to implement?
	
	Parsing - Error handlers
	
	Files Names
	Allowed chars: A-Z, a-z, 0-9, -, _, . everywhere
	Max size: 255

	input[1] -> file1 -> infile (must exist, or whole cmd until END or | not exec)
		fd = open(filename, O_RDONLY);
	input[ac - 1] -> file2 -> outfile (will create / update it)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
*/
void	init_data(t_data *data)
{
	data->cmds = NULL;
	data->delim = NULL;
	data->file_names[0] = NULL;
	data->file_names[1] = NULL;
	data->is_here_doc = -1;
}

void    fill_data(t_data *data, int ac, char **av, char **env)
{
	data->cmds = init_cmds(ac, av, env);
	if (!ft_strcmp(av[1], "here_doc"))
	{
		data->delim = ft_strdup(av[1]);
		data->file_names[0] = NULL;
		data->file_names[1] = ft_strdup(av[ac - 1]);
		data->is_here_doc = 1;
	}
	else
	{
		data->delim = NULL;
		data->file_names[0] = ft_strdup(av[1]);
		data->file_names[1] = ft_strdup(av[ac - 1]);
		data->is_here_doc = 0;
	}
	init_paths(data);
}

int main(int ac, char **av, char **envp)
{
	t_data  data;

	(void)envp;
	if (ac > 4)
	{
		init_data(&data);
		if (!valid_syntax(ac, av) || !valid_len(ac, av)) //valid_len?
			handle_errors(&data, find_syntax_err(ac, av), SYNTAX_ERR);
		fill_data(&data, ac, av, envp);
		//exec_data(&data, envp);
		print_data(&data);
		free_rest(&data);
	}
	else
		ft_printf("Input must have at least 4 args!\n");
	return (0);
}