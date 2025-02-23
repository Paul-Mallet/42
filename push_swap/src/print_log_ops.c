/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:16:26 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/22 13:43:56 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	similar_rotate(t_data *data)
{
	int	i;
	int	n;
	int	m;

	i = -1;
	n = 0;
	m = 0;
	while (++i < data->log_index)
	{
		if (!ft_strcmp(data->log_ops[i], "ra"))
			n++;
		if (!ft_strcmp(data->log_ops[i], "rb"))
			m++;
	}
	while (n > 0 && m > 0)
	{
		ft_printf("rr\n");
		n--;
		m--;
	}
	print_rest(n, m, "ra", "rb");
}

static void	similar_rev_rotate(t_data *data)
{
	int	i;
	int	n;
	int	m;

	i = -1;
	n = 0;
	m = 0;
	while (++i < data->log_index)
	{
		if (!ft_strcmp(data->log_ops[i], "rra"))
			n++;
		if (!ft_strcmp(data->log_ops[i], "rrb"))
			m++;
	}
	while (n > 0 && m > 0)
	{
		ft_printf("rrr\n");
		n--;
		m--;
	}
	print_rest(n, m, "rra", "rrb");
}

static int	ft_only_includes_rotates(char **log_ops, int log_index)
{
	int	i;

	i = 0;
	while (i < log_index)
	{
		if (ft_strcmp(log_ops[i], "ra")
			&& ft_strcmp(log_ops[i], "rb"))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_only_includes_rev_rotates(char **log_ops, int log_index)
{
	int	i;

	i = 0;
	while (i < log_index)
	{
		if (ft_strcmp(log_ops[i], "rra")
			&& ft_strcmp(log_ops[i], "rrb"))
			return (0);
		i++;
	}
	return (1);
}

void	print_log_ops(t_data *data)
{
	if (ft_only_includes_rotates(data->log_ops, data->log_index))
		similar_rotate(data);
	else if (ft_only_includes_rev_rotates(data->log_ops, data->log_index))
		similar_rev_rotate(data);
	else
		print_all_log_ops(data);
}
