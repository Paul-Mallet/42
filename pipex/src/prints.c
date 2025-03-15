/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:39:19 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/03/15 16:15:03 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print_strs(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		ft_printf("str[%d]: %s\n", i, strs[i]);
}
