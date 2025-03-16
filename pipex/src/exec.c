/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:26:00 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/03/16 20:34:48 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    exec_first_cmd(t_data *data, t_cmd *cmd)
{
    //open pipe, fork(child process) cmd
    data->is_first_cmd = 0;
}

void    exec_mid_cmd(t_data *data, t_cmd *cmd)
{
    //open pipe, based on prev cmd
}

void    exec_last_cmd(t_data *data, t_cmd *cmd)
{
    //not open pipe, based on prev cmd
}

void    exec_here_doc(t_data *data)
{
    //...
}
