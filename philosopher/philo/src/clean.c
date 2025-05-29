/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:54:54 by pamallet          #+#    #+#             */
/*   Updated: 2025/05/23 14:53:45 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	destroy_mutexes(t_data *data)
{
	unsigned int	i;

	/* PHILO MUTEXES */
	i = 0;
	while (i < data->num_philos)
	{
		handle_mutex(&data->philos->philo_mutex, DESTROY);
		i++;
	}
	/* GLOBAL MUTEXES */
	handle_mutex(&data->write_mutex, DESTROY);
	handle_mutex(&data->read_mutex, DESTROY);
}

static void	destroy_forks(t_data *data)
{
	unsigned int	i;

	/* LOOP INIT FORKS MUTEXES(0) */
	i = 0;
	while (i < data->num_philos)
	{
		handle_mutex(&data->forks[i].fork, DESTROY);
		i++;
	}
}

void	clean_data(t_data *data)
{
	destroy_mutexes(data);
	destroy_forks(data);
	free(data->philos);
	free(data->forks);
}
