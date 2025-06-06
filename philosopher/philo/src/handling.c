/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:53:52 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/06 17:32:08 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	handle_mutex(t_mtx *fork, t_err code)
{
	if (code == INIT)
		handle_mutex_error(pthread_mutex_init(fork, NULL), code);
	else if (code == LOCK)
		handle_mutex_error(pthread_mutex_lock(fork), code);
	else if (code == UNLOCK)
		handle_mutex_error(pthread_mutex_unlock(fork), code);
	else if (code == DESTROY)
		handle_mutex_error(pthread_mutex_destroy(fork), code);
}

void	handle_thread(t_data *data, int i, t_err code, bool is_monitor)
{
	if (code == CREATE && is_monitor)
		pthread_create(&data->monitor, NULL, &monitor_routine, data);
	else if (code == CREATE && data->num_philos == 1)
	{
		pthread_create(&data->philos[i].thread, NULL,
				&single_routine, (data->philos + i));
	}
	else if (code == CREATE && data->num_philos > 1)
	{
		pthread_create(&data->philos[i].thread, NULL, &routine,
			&data->philos[i]);
	}
	else if (code == JOIN && is_monitor)
		pthread_join(data->monitor, NULL);
	else if (code == JOIN)
		pthread_join(data->philos[i].thread, NULL);
}
