/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:52:11 by pamallet          #+#    #+#             */
/*   Updated: 2025/02/22 13:43:37 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stacks(t_data *data)
{
	free(data->a.arr);
	free(data->b.arr);
	free(data->cpy.arr);
}
