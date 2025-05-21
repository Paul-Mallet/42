/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:06:25 by pamallet          #+#    #+#             */
/*   Updated: 2025/05/21 10:09:57 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_data(t_data *data)
{
	int	i;

	i = -1;
	while (i < data->num_philos)
		printf("philo[%d], meals_eaten: %d\n", data->philos[i].id, data->philos[i].meals_eaten);
	// i = -1;
	// while (i < data->num_philos)
	// 	printf("fork[%d]: %d\n", i, data->forks[i]);
	printf("simulation_stop: %d, tt_die: %d, tt_eat: %d, tt_sleep: %d, must_eat_count_meals: %d\n",
		data->simulation_stop,
		data->tt_die,
		data->tt_eat,
		data->tt_sleep,
		data->must_eat_count);
}
