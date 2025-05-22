/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:06:25 by pamallet          #+#    #+#             */
/*   Updated: 2025/05/22 08:11:14 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	print_forks(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
		printf("fork id: %d\n", data->forks[i].id);
}

static void	print_philos(t_data *data)
{
	int	i;
	t_philo	*philo;

	i = -1;
	while (++i < data->num_philos)
	{
		philo = &data->philos[i];
		printf("philo: \n- id : %d\n- last_meal_time : %ld\n"
			"- left_fork id : %d\n- right_fork id: %d\n- meals_eaten : %d\n",
			philo->id, philo->last_meal_time,
			philo->left_fork, philo->right_fork, philo->meals_eaten);
	}
}

void	print_data(t_data *data)
{
	print_philos(data);
	print_forks(data);
	printf("simulation_stop: %d, tt_die: %d, tt_eat: %d, tt_sleep: %d, must_eat_count_meals: %d\n",
		data->simulation_stop,
		data->tt_die,
		data->tt_eat,
		data->tt_sleep,
		data->must_eat_count);
}
