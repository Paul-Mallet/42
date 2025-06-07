/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subroutines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:30:59 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/07 16:21:03 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static bool	unlock_after_stopped(t_philo *philo, t_mtx *fork1, t_mtx *fork2)
{
	if (is_simulation_stopped(philo->data))
	{
		if (fork2)
			handle_mutex(fork2, UNLOCK);
		handle_mutex(fork1, UNLOCK);
		return (true);
	}
	return (false);
}

bool	is_taking_forks(t_philo *philo, t_mtx *fst_fork, t_mtx *sd_fork)
{
	time_t	curr_time;

	handle_mutex(fst_fork, LOCK);
	if (unlock_after_stopped(philo, fst_fork, NULL))
		return (false);
	handle_mutex(&philo->data->read_mutex, LOCK);
	curr_time = get_current_time_in_ms();
	printf("%ld %d has taken a fork\n", (curr_time - philo->data->start_time),
		philo->id);
	handle_mutex(&philo->data->read_mutex, UNLOCK);
	handle_mutex(sd_fork, LOCK);
	if (unlock_after_stopped(philo, fst_fork, sd_fork))
		return (false);
	handle_mutex(&philo->data->read_mutex, LOCK);
	curr_time = get_current_time_in_ms();
	printf("%ld %d has taken a fork\n", (curr_time - philo->data->start_time),
		philo->id);
	handle_mutex(&philo->data->read_mutex, UNLOCK);
	if (unlock_after_stopped(philo, fst_fork, sd_fork))
		return (false);
	if (!is_eating(philo, fst_fork, sd_fork))
		return (false);
	handle_mutex(sd_fork, UNLOCK);
	handle_mutex(fst_fork, UNLOCK);
	return (true);
}

bool	is_eating(t_philo *philo, t_mtx *fst_fork, t_mtx *sd_fork)
{
	time_t	curr_time;

	handle_mutex(&philo->philo_mutex, LOCK);
	if (is_simulation_stopped(philo->data))
	{
		handle_mutex(&philo->philo_mutex, UNLOCK);
		handle_mutex(sd_fork, UNLOCK);
		handle_mutex(fst_fork, UNLOCK);
		return (false);
	}
	handle_mutex(&philo->data->read_mutex, LOCK);
	curr_time = get_current_time_in_ms();
	printf("%ld %d is eating\n", (curr_time - philo->data->start_time),
		philo->id);
	handle_mutex(&philo->data->read_mutex, UNLOCK);
	handle_mutex(&philo->philo_mutex, UNLOCK);
	handle_mutex(&philo->data->write_mutex, LOCK);
	philo->last_meal_time = get_current_time_in_ms();
	handle_mutex(&philo->data->write_mutex, UNLOCK);
	usleep(philo->data->tt_eat * 1000);
	handle_mutex(&philo->data->write_mutex, LOCK);
	philo->meals_eaten++;
	handle_mutex(&philo->data->write_mutex, UNLOCK);
	return (true);
}

bool	is_sleeping(t_philo *philo)
{
	time_t	curr_time;

	handle_mutex(&philo->philo_mutex, LOCK);
	if (is_simulation_stopped(philo->data))
	{
		handle_mutex(&philo->philo_mutex, UNLOCK);
		return (false);
	}
	handle_mutex(&philo->data->read_mutex, LOCK);
	curr_time = get_current_time_in_ms();
	printf("%ld %d is sleeping\n", (curr_time - philo->data->start_time),
		philo->id);
	handle_mutex(&philo->data->read_mutex, UNLOCK);
	handle_mutex(&philo->philo_mutex, UNLOCK);
	usleep(philo->data->tt_sleep * 1000);
	return (true);
}

bool	is_thinking(t_philo *philo)
{
	time_t			curr_time;
	unsigned int	tt_think;

	handle_mutex(&philo->philo_mutex, LOCK);
	if (is_simulation_stopped(philo->data))
	{
		handle_mutex(&philo->philo_mutex, UNLOCK);
		return (false);
	}
	handle_mutex(&philo->data->read_mutex, LOCK);
	curr_time = get_current_time_in_ms();
	printf("%ld %d is thinking\n", (curr_time - philo->data->start_time),
		philo->id);
	handle_mutex(&philo->data->read_mutex, UNLOCK);
	handle_mutex(&philo->philo_mutex, UNLOCK);
	if (philo->data->num_philos % 2 == 0)
		tt_think = 10;
	else
		tt_think = ((philo->data->tt_eat * 2 - philo->data->tt_sleep) * 1000);
	usleep(tt_think);
	return (true);
}
