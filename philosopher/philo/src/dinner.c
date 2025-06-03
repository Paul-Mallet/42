/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:03:53 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/03 20:43:44 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	handle_single_philo(t_data *data)
{
	int			i;
	t_philo		*philo;

	i = 0;
	philo = &data->philos[i];
	philo->last_meal_time = data->start_time;
	handle_thread(data, i, CREATE, true);
	handle_thread(data, i, CREATE, false);
	while (!is_simulation_stopped(data))
		precise_usleep(1000);
	handle_thread(data, i, JOIN, false);
	handle_thread(data, i, JOIN, true);
}

static void	handle_multiple_philos(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->num_philos)
	{
		data->philos[i].last_meal_time = data->start_time;
		i++;
	}
	handle_thread(data, 0, CREATE, true);
	i = 0;
	while (i < data->num_philos)
	{
		handle_thread(data, i, CREATE, false);
		i++;
	}
	while (!is_simulation_stopped(data))
		precise_usleep(1000); // < 1000?
	i = 0;
	while (i < data->num_philos)
	{
		handle_thread(data, i, JOIN, false);
		i++;
	}
	handle_thread(data, 0, JOIN, true);
}

void	start_dinner(t_data *data)
{
	data->start_time = get_current_time_in_ms();
	if (data->num_philos == 0 || data->must_eat_count == 0)
		return ;
	else if (data->num_philos == 1)
		handle_single_philo(data);
	else
		handle_multiple_philos(data);
}
