/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:54:54 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/06 17:29:17 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	destroy_mutexes(t_data *data)
{
	unsigned int	i;
	t_philo			*philo;

	i = 0;
	while (i < data->num_philos)
	{
		philo = data->philos + i;
		handle_mutex(&philo->philo_mutex, DESTROY);
		i++;
	}
	handle_mutex(&data->write_mutex, DESTROY);
	handle_mutex(&data->read_mutex, DESTROY);
}

static void	destroy_forks(t_data *data)
{
	unsigned int	i;

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
	if (data->philos)
		free(data->philos);
	if (data->forks)
		free(data->forks);
}
