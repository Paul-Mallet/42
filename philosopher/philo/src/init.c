/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:20:53 by pamallet          #+#    #+#             */
/*   Updated: 2025/05/22 17:58:09 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	init_mutexes(t_data *data)
{
	/* WRAPPERS SHARE DATA MUTEXES */
	handle_mutex(&data->meal_mutex, INIT);
	handle_mutex(&data->simulation_mutex, INIT);
	handle_mutex(&data->stop_mutex, INIT);
}

static void	init_forks(t_data *data)
{
	unsigned int	i;

	/* LOOP INIT FORKS MUTEXES(0) */
	i = 0;
	while (i < data->num_philos)
	{
		handle_mutex(&data->forks[i].fork, INIT);
		data->forks[i].id = i;
		i++;	
	}
}

static void	init_philos(t_data *data)
{
	unsigned int	i;
	t_philo			*philo;

	i = 0;
	while (i < data->num_philos)
	{
		philo = data->philos + i;
		philo->id = i + 1;
		philo->meals_eaten = 0;
		philo->left_fork = &data->forks[philo->id - 1]; //min [0 to 4]
		philo->right_fork = &data->forks[philo->id % data->num_philos]; //max [1 to 0]
		philo->data = data;
		i++;
		// all_threads_running ??? bool to start philo routine ???
		// philo->full_ate ??? bool to stop philo routine ???
	}
}

void	init_data(t_data *data, char **av)
{
	data->num_philos = ft_atoi(av[1]);
	data->tt_die = ft_atoi(av[2]);
	data->tt_eat = ft_atoi(av[3]);
	data->tt_sleep = ft_atoi(av[4]);
	data->must_eat_count = 0;
	if (av[5])
		data->must_eat_count = ft_atoi(av[5]);
	data->simulation_stop = false;
	data->philos = handle_malloc_error(data->num_philos * sizeof(t_philo));
	data->forks = handle_malloc_error(data->num_philos * sizeof(t_mtx));
	init_philos(data);
	init_forks(data);
	init_mutexes(data);
}
