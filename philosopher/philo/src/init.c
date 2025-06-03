/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:20:53 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/03 20:49:02 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	init_mutexes(t_data *data)
{
	handle_mutex(&data->write_mutex, INIT);
	handle_mutex(&data->read_mutex, INIT);
}

static void	init_forks(t_data *data)
{
	unsigned int	i;

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
		philo->left_fork = &data->forks[i];
		philo->right_fork = &data->forks[(i + 1) % data->num_philos];
		handle_mutex(&philo->philo_mutex, INIT);
		philo->data = data;
		i++;
	}
}

void	init_data(t_data *data, char **av)
{
	data->num_philos = ft_atoui(av[1]);
	data->tt_die = ft_atoui(av[2]);
	data->tt_eat = ft_atoui(av[3]);
	data->tt_sleep = ft_atoui(av[4]);
	if (av[5])
		data->must_eat_count = ft_atoui(av[5]);
	data->simulation_stop = false;
	data->forks = handle_malloc_error(data->num_philos * sizeof(t_fork));
	data->philos = handle_malloc_error(data->num_philos * sizeof(t_philo));
	init_mutexes(data);
	init_forks(data);
	init_philos(data);
}
