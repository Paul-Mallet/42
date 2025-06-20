/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:16:41 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/07 15:42:56 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	is_simulation_stopped(t_data *data)
{
	bool	is_stopped;

	is_stopped = false;
	handle_mutex(&data->write_mutex, LOCK);
	if (data->simulation_stop)
		is_stopped = true;
	handle_mutex(&data->write_mutex, UNLOCK);
	return (is_stopped);
}

void	is_philos_all_eaten(t_data *data)
{
	bool			all_eaten;
	unsigned int	i;

	if (data->must_eat_count > 0)
	{
		all_eaten = true;
		i = 0;
		while (i < data->num_philos)
		{
			handle_mutex(&data->write_mutex, LOCK);
			if (data->philos[i].meals_eaten < data->must_eat_count)
			{
				handle_mutex(&data->write_mutex, UNLOCK);
				all_eaten = false;
				break ;
			}
			handle_mutex(&data->write_mutex, UNLOCK);
			i++;
		}
		handle_mutex(&data->write_mutex, LOCK);
		if (all_eaten)
			data->simulation_stop = true;
		handle_mutex(&data->write_mutex, UNLOCK);
	}
}

void	is_philo_died(t_data *data)
{
	unsigned int	i;
	time_t			curr_time;
	time_t			time_since_last_meal;

	i = 0;
	while (i < data->num_philos)
	{
		handle_mutex(&data->write_mutex, LOCK);
		curr_time = get_current_time_in_ms();
		time_since_last_meal = (curr_time - data->philos[i].last_meal_time);
		handle_mutex(&data->write_mutex, UNLOCK);
		if (time_since_last_meal > data->tt_die)
		{
			handle_mutex(&data->read_mutex, LOCK);
			curr_time = get_current_time_in_ms();
			printf("%ld %d died\n", (curr_time - data->start_time),
				data->philos[i].id);
			handle_mutex(&data->read_mutex, UNLOCK);
			handle_mutex(&data->write_mutex, LOCK);
			data->simulation_stop = true;
			handle_mutex(&data->write_mutex, UNLOCK);
			break ;
		}
		i++;
	}
}
