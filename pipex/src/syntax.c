/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:17:15 by pamallet          #+#    #+#             */
/*   Updated: 2025/03/16 12:18:28 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	valid_file(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isalnum(str[i]) && !ft_is_spechar(str[i]))
			return (0);
	}
	return (1);
}

static int	valid_args(char **args) //["ls", "-l", NULL], not handle "---"
{
	int	i;
	int	j;

	i = -1;
	while (args[++i])
	{
		j = -1;
		while (args[i][++j])
		{
			if (!ft_isalnum(args[i][j]) && !ft_is_spechar(args[i][j]))
				return (0);
		}
	}
	return (1);
}

static int	valid_cmd(char *cmd) //not handle redir!
{
	char	*trimmed;
	char	**args;
	int		res;

	trimmed = ft_strtrim(cmd, " ");
	args = ft_split(trimmed, ' ');
	res = valid_args(args);
	free(trimmed);
	free_strs(args);
	return (res);
}

static int	valid_heredoc(char *heredoc, char *delim)
{
	return (!ft_strcmp(heredoc, "here_doc") && valid_file(delim));
}

int valid_syntax(int ac, char **av)
{
	int i;

	i = 0;
	while (++i < ac)
	{
		if ((i == 1 || i == (ac - 1)) && !valid_file(av[i]))
			return (0);
		if ((i > 1 && i < (ac - 1)) && !valid_cmd(av[i]))
			return (0);
		if ((i == 1) && ac != 6 && valid_heredoc(av[i], av[i + 1]))
			return (0);
	}
	return (1);
}
