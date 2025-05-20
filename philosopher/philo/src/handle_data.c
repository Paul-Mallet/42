/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:20:53 by pamallet          #+#    #+#             */
/*   Updated: 2025/05/20 17:12:53 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// check parsing of all args(atoi is enough?) !!!
void	init_data(t_data *data, char **av)
{
	data->num_philos = ft_atoi(av[1]);
	data->philos = (t_philo *)malloc(data->num_philos * sizeof(t_philo)); //need + 1?
	if (!data->philos)
		return (handle_error()); //#TODO
	data->forks = (pthread_mutex_t *)malloc(data->num_philos * sizeof(pthread_mutex_t));
	if (!data->forks)
		return (handle_error()); //#TODO
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->must_eat_count = 0;
	if (av[5])
		data->must_eat_count = ft_atoi(av[5]);
	data->simulation_stop = 0;
}

int	check_data(t_data *data)
{
	if (!data->philos)
		return (0);
	if (!data->forks)
		return (0);
	return (1);
}
