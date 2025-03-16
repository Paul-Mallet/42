/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:39:19 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/03/16 17:50:10 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	print_str(char *custom, char *str)
{	
	ft_printf("%s: %s\n", custom, str);
}

static void	print_strs(char *custom, char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		ft_printf("%s[%d]: %s\n", custom, i, strs[i]);
}

static void	print_cmds(t_cmd *cmds)
{
	t_cmd	*curr;

	curr = cmds;
	while (curr)
	{
		if (curr->args)
			print_strs("args", curr->args);
		if (curr->paths)
			print_strs("paths", curr->paths);
		if (curr->path)
			print_str("path", curr->path);
		ft_printf("fd[0]: %d\nfd[1]: %d\n", curr->fd[0], curr->fd[1]);
		curr = curr->next;
	}
}

void	print_data(t_data *data)
{
	if (data->cmds)
		print_cmds(data->cmds);
	if (data->delim)
		print_str("delim", data->delim);
	if (data->file_names[0] && data->file_names[1])
		ft_printf("file_names[0]: %s\nfile_name[1]: %s\n",
			data->file_names[0], data->file_names[1]);
	ft_printf("is_here_doc: %d\n", data->is_here_doc);
}
