/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:53:05 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/03/08 15:21:04 by pamallet         ###   ########.fr       */
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
# define SYNTAX_ERR 1
typedef struct  s_cmd
{
	struct s_cmd	*next;
	char			**args; //for execve();
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

/*
	Syntax
*/
int 	valid_syntax(int ac, char **av);

/*
	Errors
*/
void	handle_errors(int status);

/*
	Utils
*/
int		valid_len(int ac, char **av);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_is_spechar(char c);

#endif