/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 23:53:05 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/02/12 00:09:29 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>

typedef struct  s_pipex
{
    int     infile;
    int     outfile;
    int     **pipes;
    int     cmd_nb;
    int     ***cmds;
    char    **paths;
    char    **envp;
    int     heredoc;
}       t_pipex;

#endif