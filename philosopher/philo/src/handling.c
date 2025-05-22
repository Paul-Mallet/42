/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:53:52 by pamallet          #+#    #+#             */
/*   Updated: 2025/05/21 23:24:07 by pamallet         ###   ########.fr       */
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

//???
void    handle_thread(t_data *data, int i, t_err_code code)
{
    pthread_t   thread;

    thread = data->philos[i].thread;
    if (code == CREATE && data->num_philos == 1)
        handle_thread_error(pthread_create(&thread, NULL, &single_routine, &data), code);
    else if (code == CREATE && data->num_philos > 1)
        handle_thread_error(pthread_create(&thread, NULL, &routine, &data), code);
    else if (code == JOIN)
        handle_thread_error(pthread_join(thread, NULL), code);
    else if (code == DETACH)
        handle_thread_error(pthread_detach(thread), code);
}
