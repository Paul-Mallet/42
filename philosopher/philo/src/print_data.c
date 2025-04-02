/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:06:25 by pamallet          #+#    #+#             */
/*   Updated: 2025/04/02 18:27:37 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// void	print_philos(t_philo *philos)
// {
// 	int	i;

// 	i = -1;
// 	while (philos[++i])
// 		printf("philos[%d], meals_eaten: %d\n", philos->id, philos->meals_eaten);
// }

// void	print_forks(pthread_mutex_t *forks)
// {
// 	int	i;

// 	i = -1;
// 	while (forks[++i])
// 		printf("fork[%d]: %d\n", i, forks[i]);
// }

void	print_data(t_data *data)
{
	// print_philos(data.philos);
	// print_forks(data.forks);
	printf("is_dead: %d, tt_die: %d, tt_eat: %d, tt_sleep: %d, num_meals_to_eat: %d\n",
		data->is_dead,
		data->time_to_die,
		data->time_to_eat,
		data->time_to_sleep,
		data->num_meals_to_eat);
}
