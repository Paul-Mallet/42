/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:53:05 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/03/15 18:09:11 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/wait.h>

# define BUF_SIZE 1024

typedef enum	s_err
{
	SYNTAX_ERR,
	NOT_FOUND_ERR,
	PERMISSION_ERR,
}		t_err;

typedef struct  s_cmd
{
	struct s_cmd	*next;
	char			**args; //for execve();
	char			**paths;//for cmds exec (aka: usr/bin/...)
	char			*path;	//absolute / relative path for cmd
	int				fd[2];	//fd for input / output redirs fd
}       t_cmd;

typedef struct	s_data
{
	t_cmd	*cmds;
	char	*delim;			//only _ || A-Z || a-z, after << + space || <<
	char	*file_names[2];	//redir stdin to files[0], stdout of last cmd to files[1]
	int		is_here_doc;	//if find "here_doc" in av[1], >> in same exec
	int		fd[2];			//fd for stdin / stdout
}		t_data;

//	CMDS

//	Init t_cmd
t_cmd	*init_cmds(int ac, char **av, char **env);
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

//	SYNTAX

//	Valid argv syntax to fit files, cmds, args and redirs
int 	valid_syntax(int ac, char **av);

//	ERRORS

//	Print error based on status
void	handle_errors(t_data *data, char *cmd, int status);

//	PRINTS

//	Print args, paths from ["arg1", "arg2"...]
void	print_strs(char **strs);

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