/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 20:03:53 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/03 20:06:07 by pamallet         ###   ########.fr       */
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
    // printf("\nphilo->last_meal_time: %ld\n", philo->last_meal_time);

	/* CREATE MONITOR */
	handle_thread(data, i, CREATE, true);

	// CREATE SINGLE PHILO
	handle_thread(data, i, CREATE, false);

	/* CONDITION BEFORE JOIN! */
    // printf("\nsimulation_stop in handle_single_philo: %d\n", data->simulation_stop);	
	while (1)
	{
		if (is_simulation_stopped(data))
			break ;
		precise_usleep(500);
	}
    // printf("\nsimulation_stop in handle_single_philo: %d\n", data->simulation_stop);

	handle_thread(data, i, JOIN, false);
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
    	// printf("\nphilo[%u]->last_meal_time: %ld\n", i, data->philos[i].last_meal_time);
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

	/* CONDITION BEFORE JOIN! */
    // printf("\nsimulation_stop in handle_multi_philo: %d\n", data->simulation_stop);	
	while (!is_simulation_stopped(data))
		precise_usleep(1000);
    // printf("\nsimulation_stop in handle_multi_philo: %d\n", data->simulation_stop);

	/* ALL PHILOS THREADS JOIN(2) */
	i = 0;
	while (i < data->num_philos)
	{
		handle_thread(data, i, JOIN, false);
		i++;
	}

	// MONITOR JOIN
	handle_thread(data, 0, JOIN, true);
}

void	start_dinner(t_data *data)
{
	/* START SIMULATION TIME & PHILOS LAST_MEAL_TIME */
	data->start_time = get_current_time_in_ms();
    printf("\ndata->start_time: %ld\n", data->start_time);

	/* CHECK SPECIAL CASES */
	if (data->num_philos == 0 || data->must_eat_count == 0)
		return ;
	else if (data->num_philos == 1)
		handle_single_philo(data);
	else
		handle_multiple_philos(data);
}
