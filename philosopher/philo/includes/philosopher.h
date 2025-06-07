/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:06:40 by pamallet          #+#    #+#             */
/*   Updated: 2025/06/07 16:26:35 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <errno.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

/* MACROS */
typedef pthread_mutex_t	t_mtx;
typedef struct s_data	t_data;

/* ENUMS */
typedef enum e_philo_state
{
	THINKING,
	EATING,
	SLEEPING,
	TAKING_FORK_1,
	TAKING_FORK_2,
	DIED,
}	t_philo_state;

typedef enum e_err
{
	SUCCESS,
	/* PARSING */
	ARGUMENTS,
	EMPTY_ERR,
	SPACES_ERR,
	DIGITS_ERR,
	SIGN_ERR,
	OVERFLOW_ERR,
	PHILO_NUM,
	MEAL_NUM,
	MALLOC,
	TIME,
	/* MUTEX */
	INIT,
	LOCK,
	UNLOCK,
	DESTROY,
	/* THREAD */
	CREATE,
	JOIN,
	DETACH
}	t_err;

/* STRUCTS */
typedef struct s_fork
{
	unsigned int	id;
	t_mtx			fork;
}	t_fork;

/*
	id: Philosopher ID (0 to num_philos-1)
	meals_eaten: Counter for meals eaten(to reach must_eat_count)
	left_fork: Min fork id, always taking 1rstly
	right_fork: Max fork id, always taking 2ndly
	last_meal_time: Timestamp of last meal
		(started before philos thread creations, updated during routine)
	philo_mutex: Mutex to wrap each actions???
	thread: Thread ID
	data: Pointer to shared data
*/
typedef struct s_philo
{
	unsigned int	id;
	unsigned int	meals_eaten;
	t_fork			*left_fork;
	t_fork			*right_fork;
	time_t			last_meal_time;
	t_mtx			philo_mutex;
	pthread_t		thread;
	t_data			*data;
}	t_philo;

/*
	num_philos: 1rst arg, must be > 0
	tt_die: 2nd arg, must be > 60
	tt_eat: 3rd arg, must be > 60
	tt_sleep: 4th arg, must be > 60
	must_eat_count: 5th arg(optional), num of times each philosopher must eat
	simulation_stop: Flag to stop simulation(simulation_is_over())
	start_time: Simulation start timestamp
	philos: Array of philos threads
	forks: Array of fork mutexes
	monitor: Monitor to continuously check philos states
	write_mutex: 
	read_mutex: 
*/
typedef struct s_data
{
	unsigned int	num_philos;
	time_t			tt_die;
	time_t			tt_eat;
	time_t			tt_sleep;
	unsigned int	must_eat_count;
	bool			simulation_stop;
	time_t			start_time;
	t_philo			*philos;
	t_fork			*forks;
	pthread_t		monitor;
	t_mtx			write_mutex;
	t_mtx			read_mutex;
}	t_data;

/* FUNCTIONS */
/* PARSING */
int				parsing(char **av);

/* DATA */
bool			init_data(t_data *data, char **av);

/* HANDLING */
void			handle_mutex(t_mtx *fork, t_err code);
void			handle_thread(t_data *data, int i, t_err code, bool is_monitor);

/* DINNER */
void			start_dinner(t_data *data);

/* ROUTINES */
void			*routine(void *arg);
void			*monitor_routine(void *arg);
void			*single_routine(void *arg);

/* SUB-ROUTINES */
// t_mtx			*forks_ordering(t_philo *philo);
bool			is_taking_forks(t_philo *philo, t_mtx *fst_fork, t_mtx *sd_fork);
bool			is_eating(t_philo *philo, t_mtx *fst_fork, t_mtx *sd_fork);
bool			is_sleeping(t_philo *philo);
bool			is_thinking(t_philo *philo);

/* ROUTINES UTILS */
bool			is_simulation_stopped(t_data *data);
void			is_philos_all_eaten(t_data *data);
void			is_philo_died(t_data *data);

/* ERRORS */
int				handle_input_error(t_err code);
void			handle_mutex_error(int status, t_err code);
void			handle_thread_error(int status, t_err code);
int				error_exit(const char *msg, int status);

/* CLEAN */
void			clean_data(t_data *data);

/* PARSING_UTILS */
int				ft_strlen(const char *s);
int				ft_isspace(const char c);
int				ft_issign(const char c);
int				ft_isdigit(int c);
int				is_overflow(char *s);

/* CONVERSION_UTILS */
time_t			get_current_time_in_ms(void);
unsigned int	ft_atoui(const char *nptr);

/* PRINT_DATA(DEBUG) */
void			print_data(t_data *data);

#endif