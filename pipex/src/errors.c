/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:47:57 by pamallet          #+#    #+#             */
/*   Updated: 2025/03/18 15:47:53 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	handle_errors(t_data *data, char *cmd, int status) //va_list?(*)
{
	if (status == PATH_ERR)
		close_pipe(data);
	else if (status == OPEN_FILE_ERR)
		free(cmd);
	perror("bash");
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
