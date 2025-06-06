/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:03:53 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/06 18:58:28 by pamallet         ###   ########.fr       */
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
		usleep(1000);
	handle_thread(data, i, JOIN, false);
	handle_thread(data, i, JOIN, true);
}

static void	handle_multiple_philos(t_data *data)
{
	int	i;

	i = -1;
	while ((unsigned int)++i < data->num_philos)
		data->philos[i].last_meal_time = data->start_time;
	handle_thread(data, 0, CREATE, true);
	i = 1;
	while ((unsigned int)i < data->num_philos)
	{
		handle_thread(data, i, CREATE, false);
		i += 2;
	}
	usleep(100);
	i = 0;
	while ((unsigned int)i < data->num_philos)
	{
		handle_thread(data, i, CREATE, false);
		i += 2;
	}
	while (!is_simulation_stopped(data))
		usleep(1000);
	i = -1;
	while ((unsigned int)++i < data->num_philos)
		handle_thread(data, i, JOIN, false);
	handle_thread(data, 0, JOIN, true);
}

void	start_dinner(t_data *data)
{
	data->start_time = get_current_time_in_ms();
	if (data->num_philos == 0)
		error_exit("Need 1 meal to start.", PHILO_NUM);
	else if (data->must_eat_count == 0)
		error_exit("Need 1 meal to start.", MEAL_NUM);
	else if (data->num_philos == 1)
		handle_single_philo(data);
	else if (data->num_philos > 1)
		handle_multiple_philos(data);
}
