/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:03:53 by pamallet          #+#    #+#             */
/*   Updated: 2025/05/23 16:17:52 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	handle_single_philo(t_data *data)
{
	int			i;
	t_philo		*philo;

	i = 0;
	philo = &data->philos[i];

	//START LAST_MEAL_TIME
	philo->last_meal_time = data->start_time;

	/* CREATE MONITOR BEFORE PHILOS ROUTINES*/
	handle_thread(data, i, CREATE, true);

	// CREATE THREAD(SINGLE PHILO)
	handle_thread(data, i, CREATE, false);

	// JOIN THREAD(SINGLE PHILO)
	handle_thread(data, i, JOIN, false);

	/* JOIN MONITOR LAST */
	handle_thread(data, i, JOIN, true);
}

static void	handle_multiple_philos(t_data *data)
{
	unsigned int	i;

	//BOOL to start routine when all_thread_ready?
	i = 0;
	while (i < data->num_philos)
	{
		data->philos[i].last_meal_time = data->start_time;
		i++;
	}

	/* MONITOR CREATE */
	handle_thread(data, 0, CREATE, true);

	/* PHILOS[i].THREADS CREATE(1) */
	//check all threads are running?
	i = 0;
	while (i < data->num_philos)
	{
		handle_thread(data, i, CREATE, false);
		i++;
	}

	while (!data->simulation_stop);

	/* PHILOS[i].THREADS JOIN(2) */
	// i = 0;
	// while (i < data->num_philos)
	// {
	// 	handle_thread(data, i, JOIN, false);
	// 	i++;
	// }

	// /* MONITOR JOIN */
	// handle_thread(data, 0, JOIN, true);
}

void	start_dinner(t_data *data)
{
	/* START SIMULATION TIME & PHILOS LAST_MEAL_TIME */
	data->start_time = get_current_time_in_ms();

	/* CHECK SPECIAL CASES */
	if (data->num_philos == 0 || data->must_eat_count == 0)
		return ; //back main
	else if (data->num_philos == 1)
		handle_single_philo(data);
	else
		handle_multiple_philos(data);
}
