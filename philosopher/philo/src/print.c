/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:06:25 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/03 20:50:05 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	print_forks(t_data *data)
{
	unsigned int	i;

	i = 0;
	printf("\nnum_forks: %u\n", data->num_philos);
	while (i < data->num_philos)
	{
		printf("fork id: %u\n", data->forks[i].id);
		i++;
	}
	printf("\n");
}

static void	print_philos(t_data *data)
{
	unsigned int	i;
	t_philo			*philo;

	i = 0;
	printf("\nphilos:\n");
	while (i < data->num_philos)
	{
		philo = &data->philos[i];
		printf("- id : %u\n- meals_eaten : %u\n"
			"- left_fork id : %u\n- right_fork id: %u\n"
			"- data->num_philos: %u\n",
			philo->id,
			philo->meals_eaten,
			philo->left_fork->id,
			philo->right_fork->id,
			philo->data->num_philos);
		i++;
	}
	printf("\n");
}

void	print_data(t_data *data)
{
	printf("\nnum_philos: %u\ntt_die: %ld\ntt_eat: %ld\ntt_sleep: %ld\n"
		"must_eat_count_meals: %u\nsimulation_stop: %d\n",
		data->num_philos,
		data->tt_die,
		data->tt_eat,
		data->tt_sleep,
		data->must_eat_count,
		data->simulation_stop);
	print_philos(data);
	print_forks(data);
}
