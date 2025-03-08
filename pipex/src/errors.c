/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:47:57 by pamallet          #+#    #+#             */
/*   Updated: 2025/03/08 15:19:22 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	handle_errors(int status)
{
	if (status == SYNTAX_ERR)
		ft_printf("Syntax error!\n");
	exit(EXIT_FAILURE);
}
