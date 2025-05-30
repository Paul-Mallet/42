/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:53:52 by pamallet          #+#    #+#             */
/*   Updated: 2025/05/30 16:08:21 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void    handle_mutex(t_mtx *fork, t_err_code code)
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

void    handle_thread(t_data *data, int i, t_err_code code, bool is_monitor)
{
    pthread_t   thread;

    thread = data->philos[i].thread;
    if (code == CREATE && is_monitor)
    {
        printf("\nmonitor [i]: %u\n", i);
        handle_thread_error(pthread_create(&data->monitor, NULL,
        &monitor_routine, &data), code);
    }
    else if (code == CREATE && data->num_philos == 1)
    {
        printf("\nsingle philo [i]: %u\n", i);
        handle_thread_error(pthread_create(&thread, NULL,
        &single_routine, &data), code);
    }
    else if (code == CREATE && data->num_philos > 1)
    {
        printf("\nphilos [i]: %u\n", i);
        handle_thread_error(pthread_create(&thread, NULL,
        &routine, &data), code);
    }
    else if (code == JOIN)
        handle_thread_error(pthread_join(thread, NULL), code);
    else if (code == JOIN && is_monitor)
        handle_thread_error(pthread_join(data->monitor, NULL), code);
}
