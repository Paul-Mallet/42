/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:16:41 by pamallet          #+#    #+#             */
/*   Updated: 2025/05/22 18:21:52 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void    is_philos_all_eaten(t_data *data)
{
    unsigned int     i;
    bool            all_eaten;

    if (data->must_eat_count > 0)
    {
        all_eaten = true;
        i = 0;
        pthread_mutex_lock(&data->meal_mutex);
        while (i < data->num_philos)
        {
            if (data->philos[i].meals_eaten < data->must_eat_count)
            {
                all_eaten = false;
                break ;
            }
            i++;
        }
        pthread_mutex_unlock(&data->meal_mutex);
        pthread_mutex_lock(&data->simulation_mutex);
        if (all_eaten)
            data->simulation_stop = true;
        pthread_mutex_unlock(&data->simulation_mutex);
    }
}

void    is_philo_died(t_data *data)
{
    unsigned int    i;
    time_t	        curr_time;
	time_t	        time_since_last_meal;

    i = 0;
    while (i < data->num_philos)
    {
        curr_time = get_current_time_in_ms();
        
        pthread_mutex_lock(&data->meal_mutex);
        time_since_last_meal = curr_time - data->philos[i].last_meal_time;
        pthread_mutex_unlock(&data->meal_mutex);

        if (time_since_last_meal > data->tt_die)
        {
            curr_time = get_current_time_in_ms();
            pthread_mutex_lock(&data->simulation_mutex);
            printf("%ld %d died\n", curr_time - data->start_time, data->philos[i].id);
            data->simulation_stop = true;
            pthread_mutex_unlock(&data->simulation_mutex);
            break ;
        }
    }
}
