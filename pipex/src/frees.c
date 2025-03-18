/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:38:28 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/03/18 15:04:07 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    free_strs(char **strs)
{
    int i;

    i = -1;
    while (strs[++i])
        free(strs[i]);
    free(strs);
}

void    free_cmds(t_cmd *cmds)
{
    t_cmd   *curr;
    t_cmd   *next;

    curr = cmds;
    while (curr)
    {
        next = curr->next;
        if (curr->args)
            free_strs(curr->args);
        if (curr->path)
            free(curr->path);
        free(curr);
        curr = next;
    }
}

void	free_rest(t_data *data)
{
	if (data->cmds)
		free_cmds(data->cmds);
	if (data->delim)
		free(data->delim);
	if (data->file_names[0] && data->file_names[1])
	{
		free(data->file_names[0]);
		free(data->file_names[1]);
	}
    if (data->paths)
        free_strs(data->paths);
}
