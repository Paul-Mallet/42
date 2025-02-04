/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:31:37 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/04 19:17:49 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_log_ops(t_data *data)
{
	data->log_index = 0;
	data->log_ops = (char **)malloc((data->nb_ops + 1) * sizeof(char *)); //TODO only 1, instead of 2!
	if (!data->log_ops)
		handle_error(ERROR_MSG);
}

void	ft_free_log_ops(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->log_index)
		free(data->log_ops[i]);
	free(data->log_ops);
}
