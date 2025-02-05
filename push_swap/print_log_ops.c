/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_log_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:16:26 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/05 14:03:02 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_rest(int n, int m, char *s1, char *s2)
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
	/* printf("n(ra): %d, m(rb): %d\n", n, m); */
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
	/* printf("n(rra): %d, m(rrb): %d\n", n, m); */
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
	printf("check_include_rotates\n");
	while (i < log_index)
	{
		if (ft_strcmp(log_ops[i], "ra")
			&& ft_strcmp(log_ops[i], "rb")) //1 = not same
			return (0);
		i++;
	}
	return (1);
}

void	print_log_ops(t_data *data)
{
	if (ft_only_includes_rotates(data->log_ops, data->log_index))
		similar_rotate(data);
	else
		similar_rev_rotate(data);
}
