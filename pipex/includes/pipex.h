/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:53:05 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/03/16 23:44:09 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/wait.h>

# define BUF_SIZE 1024

typedef enum	s_err
{
	SYNTAX_ERR,
	NO_SUCH_FILE_ERR,
	NOT_FOUND_ERR,
	PERMISSION_ERR,
	INVALID_OPT_ERR,	//TODO
	PIPE_ERR,
	FORK_ERR,
	OPEN_FILE_ERR,
}		t_err;

typedef struct  s_cmd
{
	struct s_cmd	*next;
	char			**args; 	//for execve();
	char			**paths;	//for cmds exec (aka: usr/bin/...)
	char			*path;		//absolute / relative path for cmd
	int				fd[2];		//fd for input / output redirs fd
}       t_cmd;

typedef struct	s_data
{
	t_cmd	*cmds;
	char	*delim;			//only _ || A-Z || a-z, after << + space || <<
	char	*file_names[2];	//redir stdin to files[0], stdout of last cmd to files[1]
	int		infile;
	int		outfile;
	int		is_here_doc;	//if find "here_doc" in av[1], >> in same exec
	int		is_first_cmd;	//bool to know if it's 1rst cmd
}		t_data;

//	DATA

//	Init t_data
void	init_data(t_data *data);
//	Fill data based on here_doc redir
void    fill_data(t_data *data, int ac, char **av, char **env);
//	Exec data based on cmds & here_doc
void	exec_data(t_data *data, char **envp);

//	CMDS

//	Init t_cmd
void	init_cmds(t_data *data, int ac, char **av, char **env);
//	Create a new node to t_cmd
t_cmd	*init_cmd(void);
//	Fill a node t_cmd to create path later
void	fill_cmd(t_cmd *new, char *args, char **env);
//	Add to back of t_cmd linked list
void	cmd_add_back(t_cmd **cmds, t_cmd *new);

//	PATH

//	Init path to each cmds get with find_path
void	init_paths(t_data *data);
// 	Find path based on PATH=... from envp
char	*find_path(t_data *data, char **paths, char *cmd);
//	Get paths(...:...:...) from PATH in envp
char	**get_paths(char **env);
//	Construct path(try all paths from PATH)
char	*construct_path(char *dir, char *cmd);

//	EXEC

//	Exec first cmd
void    exec_first_cmd(t_data *data, t_cmd *cmd, char **envp);
//	Exec in between cmds
void    exec_mid_cmd(t_data *data, t_cmd *cmd, char **envp);
//	Exec last cmd
void    exec_last_cmd(t_data *data, t_cmd *cmd, char **envp);
//	Exec here_doc redirection
void    exec_here_doc(t_data *data, char **envp);

//	SYNTAX

//	Valid argv syntax to fit files, cmds, args and redirs
int 	valid_syntax(int ac, char **av);

//	ERRORS

//	Print error based on status
void	handle_errors(t_data *data, char *cmd, int status);
//	Find syntax errors and return the char concerned
char	*find_syntax_err(int ac, char **av);

//	PRINTS

//	Print cmds, delim, filenames, heredoc from data
void	print_data(t_data *data);

//	FREES

//	Free rest of data such as filenames and cmds
void	free_rest(t_data *data);
//	Free cmds from data
void	free_cmds(t_cmd *cmds);
//	Free args from t_cmd
void	free_strs(char **strs);

//	UTILS
//	Validate length of filenames & pathnames
int		valid_len(int ac, char **av);
//	Compare 2 strings
int		ft_strcmp(const char *s1, const char *s2);
//	Check valid chars '-', '_', '.', & '/'
int		ft_is_spechar(char c);

#endif