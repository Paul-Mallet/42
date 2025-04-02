/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:06:40 by pamallet          #+#    #+#             */
/*   Updated: 2025/04/02 15:24:22 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

typedef enum e_msg {
	EMPTY_INPUT_ERR,
	ONLY_SPACES_ERR,
	INVALID_DIGITS_ERR,
	INVALID_SIGN_ERR,
	INVALID_OVERF_ERR,
}		t_msg;

typedef struct s_philo
{
	pthread_t	thread;
	int			id;
	int			meals_eaten;
	int			last_meal_time;
}		t_philo;

typedef struct s_data
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	int				is_dead;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_meals_to_eat;
}		t_data;

/* PARSING */
int	parsing(char **av);

/* UTILS */
int	ft_strlen(const char *s);
int	ft_isspace(const char c);
int	ft_issign(const char c);
int	ft_isdigit(int c);

#endif