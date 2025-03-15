/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:47:57 by pamallet          #+#    #+#             */
/*   Updated: 2025/03/15 18:08:50 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	handle_errors(t_data *data, char *cmd, int status) //va_list?(*)
{
	if (status == SYNTAX_ERR)
		ft_printf("bash: syntax error near unexpected token '...'\n");
	else if (status == NOT_FOUND_ERR)
		ft_printf("bash: %s: command not found\n", cmd);
	else if (status == PERMISSION_ERR)
		ft_printf("bash: %s: Permission denied\n", cmd); //not add_back yet !(*)
	if (data)
		free_rest(data);
	exit(EXIT_FAILURE);
}
