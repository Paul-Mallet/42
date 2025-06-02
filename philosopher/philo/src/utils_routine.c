/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:16:41 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/02 11:05:16 by pamallet         ###   ########.fr       */
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
        while (i < data->num_philos)
        {
            printf("meals_eaten: %d\n", data->philos[i].meals_eaten);
            if (data->philos[i].meals_eaten < data->must_eat_count)
            {
                all_eaten = false;
                break ;
            }
            i++;
        }
        if (all_eaten)
            data->simulation_stop = true;
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
        
        time_since_last_meal = (curr_time - data->philos[i].last_meal_time);
        printf("time_since_last_meal: %ld\n", time_since_last_meal);
        if (time_since_last_meal > data->tt_die)
        {
            curr_time = get_current_time_in_ms();
            printf("%ld %d died\n", (curr_time - data->start_time), data->philos[i].id);
            data->simulation_stop = true;
            break ;
        }
    }
}
