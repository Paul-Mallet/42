/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 23:16:29 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/06 12:47:27 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*single_routine(void *arg)
{
	t_philo	*philo;
	time_t	curr_time;

	philo = (t_philo *)arg;
	curr_time = get_current_time_in_ms();
	handle_mutex(&philo->left_fork->fork, LOCK);
	printf("%ld %d has taken a fork\n",
		(curr_time - philo->data->start_time), philo->id);
	handle_mutex(&philo->left_fork->fork, UNLOCK);
	while (1)
	{
		if (is_simulation_stopped(philo->data))
			break ;
		precise_usleep(500);
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->left_fork->id < philo->right_fork->id)
		{
			if (!is_taking_forks(philo, &philo->left_fork->fork,
					&philo->right_fork->fork))
				break ;
		}
		else
		{
			if (!is_taking_forks(philo, &philo->right_fork->fork,
					&philo->left_fork->fork))
				break ;
		}
		if (!is_sleeping(philo))
			break ;
		if (!is_thinking(philo))
			break ;
	}
	return (NULL);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (!is_simulation_stopped(data))
	{
		is_philos_all_eaten(data);
		is_philo_died(data);
		precise_usleep(500);
	}
	return (NULL);
}
