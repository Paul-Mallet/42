/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:20:53 by pamallet          #+#    #+#             */
/*   Updated: 2025/04/02 18:23:43 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	init_data(t_data *data, char **av)
{
	data->philos = (t_philo *)malloc((ft_atoi(av[1]) + 1) * sizeof(t_philo));
	data->forks = (pthread_mutex_t *)malloc((ft_atoi(av[1]) + 1) * sizeof(pthread_mutex_t));
	data->is_dead = 0;
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->num_meals_to_eat = ft_atoi(av[5]);
}

int	check_data(t_data *data)
{
	if (!data->philos)
		return (0);
	if (!data->forks)
		return (0);
	return (1);
}
