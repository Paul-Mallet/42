/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:17:15 by pamallet          #+#    #+#             */
/*   Updated: 2025/03/08 15:47:56 by pamallet         ###   ########.fr       */
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

	trimmed = ft_strtrim(cmd, " ");
	args = ft_split(trimmed, ' ');
	return (valid_args(args)); //free args!
}

static int	valid_heredoc(char *heredoc, char *delim)
{
	return (!ft_strcmp(heredoc, "here_doc") && valid_file(delim));
}

int valid_syntax(int ac, char **av) //["ls -l", "cat -e", ...] not builtins
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