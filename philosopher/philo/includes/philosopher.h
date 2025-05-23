/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:06:40 by pamallet          #+#    #+#             */
/*   Updated: 2025/05/23 11:38:36 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H

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
typedef enum e_philo_state {
	THINKING,
	EATING,
	SLEEPING,
	TAKING_FORK_1,
	TAKING_FORK_2,
	DIED,
} t_philo_state;

typedef enum e_err_code {
	/* PARSING */
	EMPTY_ERR,
	SPACES_ERR,
	DIGITS_ERR,
	SIGN_ERR,
	OVERFLOW_ERR,
	/* MUTEX */
	INIT,
	LOCK,
	UNLOCK,
	DESTROY,
	/* THREAD */
	CREATE,
	JOIN,
	DETACH
} t_err_code;

/* STRUCTS */
typedef struct s_fork
{
	unsigned int	id;
	t_mtx			fork;
} t_fork;

typedef struct s_philo
{
    unsigned int	id;                   // Philosopher ID (0 to num_philos-1)
    unsigned int	meals_eaten;          // Counter for meals eaten(to reach must_eat_count)
    t_fork			*left_fork;			  // Min fork id, always taking 1rstly
    t_fork			*right_fork;		  // Max fork id, always taking 2ndly
    time_t			last_meal_time;       // Timestamp of last meal(started before philos thread creations, updated during routine)
	pthread_t		thread;               // Thread ID
    t_data			*data;                // Pointer to shared data
} t_philo;

typedef struct s_data
{
	unsigned int	num_philos;			  // 1rst arg
	time_t			tt_die;				  // 2nd arg
	time_t			tt_eat;				  // 3rd arg
	time_t			tt_sleep;		  	  // 4th arg
	unsigned int	must_eat_count;       // Optional(5th arg): number of times each philosopher must eat
	bool			simulation_stop;      // Flag to stop simulation(simulation_is_over())
	time_t			start_time;           // Simulation start timestamp
	t_philo			*philos;              // Array of philos threads
	t_fork			*forks;               // Array of fork mutexes
	pthread_t		monitor;			  // Monitor to continuously check philos states
	/* Could only need 3 mutexesphilo -> all actions | table(read) and write) */
	//t_mtx
} t_data;

/* FUNCTIONS */
/* PARSING */
void		parsing(char **av);

/* DATA */
void		init_data(t_data *data, char **av);

/* HANDLING */
void    	handle_mutex(t_mtx *fork, t_err_code code);
void    	handle_thread(t_data *data, int i, t_err_code code, bool is_monitor); //???

/* DINNER */
void		start_dinner(t_data *data);

/* ROUTINES */
void		*routine(void *arg);
void 		*monitor_routine(void *arg);
void		*single_routine(void *arg);

/* ROUTINES UTILS */
void    	is_philos_all_eaten(t_data *data);
void    	is_philo_died(t_data *data);

/* ERRORS */
void    	handle_input_error(t_err_code code);
void		*handle_malloc_error(size_t bytes);
void		handle_mutex_error(int status, t_err_code code);
void		handle_thread_error(int status, t_err_code code); //???
void		error_exit(const char *msg);

/* CLEAN */
void		clean_data(t_data *data);

/* PARSING_UTILS */
int			ft_strlen(const char *s);
int			ft_isspace(const char c);
int			ft_issign(const char c);
int			ft_isdigit(int c);
int			is_overflow(char *s);

/* CONVERSION_UTILS */
time_t		get_current_time_in_ms();
void		precise_usleep(time_t usec);
int			ft_atoi(const char *nptr); //???

/* PRINT_DATA(DEBUG) */
void		print_data(t_data *data);

#endif