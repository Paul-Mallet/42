/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log_ops2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:24:49 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/09 17:25:57 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_rest(int n, int m, char *s1, char *s2)
{
	if (n > 0)
	{
		n++;
		while (--n > 0)
			ft_printf("%s\n", s1);
	}
	else
	{
		m++;
		while (--m > 0)
			ft_printf("%s\n", s2);
	}
}

void	print_all_log_ops(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->log_index)
		ft_printf("%s\n", data->log_ops[i++]);
}
