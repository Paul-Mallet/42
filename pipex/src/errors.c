/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:47:57 by pamallet          #+#    #+#             */
/*   Updated: 2025/03/16 19:58:58 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	handle_errors(t_data *data, char *cmd, int status) //va_list?(*)
{
	if (status == SYNTAX_ERR)
		ft_printf("bash: syntax error near unexpected token '%c'\n", cmd[0]);
	else if (status == NO_SUCH_FILE_ERR)
		ft_printf("bash: %s: No such file or directory\n", cmd);
	else if (status == NOT_FOUND_ERR)
		ft_printf("bash: %s: command not found\n", cmd);
	else if (status == PERMISSION_ERR)
		ft_printf("bash: %s: Permission denied\n", cmd); //not add_back yet !(*)
	else if (status == INVALID_OPT_ERR)
		ft_printf("%s: invalid option -- '%c'\n", data->cmds->args[1][0]); //find wrong -arg
	else if (status == PIPE_ERR)
		ft_printf("bash: %s: Pipefd is not valid\n", cmd);
	else if (status == FORK_ERR)
		ft_printf("bash: %s: Pipefd is not valid\n", cmd);
	if (data)
		free_rest(data);
	exit(EXIT_FAILURE);
}

char	*find_syntax_err(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac) //i = 1
	{
		j = -1;
		while (av[i][++j]) //j = 0
		{
			if (!ft_isalnum(av[i][j]) && !ft_is_spechar(av[i][j]))
				return (&av[i][j]);
		}
	}
	return (NULL);
}
