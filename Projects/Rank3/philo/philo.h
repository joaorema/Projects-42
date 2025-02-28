/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpedro-c <joaopcrema@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:47:37 by Jpedro-c          #+#    #+#             */
/*   Updated: 2025/02/27 15:19:19 by Jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>
# include <errno.h>

# define RESET  "\033[0m"
# define RED    "\033[1;31m"
# define GREEN  "\033[1;32m"

# define DEBUG_MODE 0

typedef struct s_fork	t_fork;
typedef struct s_philo	t_philo;
typedef struct s_table	t_table;
typedef pthread_mutex_t	t_mtx;

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	FIRST_FORK,
	SECOND_FORK,
	DIED,
}		t_philo_status;

typedef enum s_code
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}		t_code;

typedef enum s_time_code
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}		t_time_code;

typedef struct s_fork
{
	t_mtx	fork;
	long	id_fork;

}		t_fork;

typedef struct s_philo
{
	long		id;
	long		counter;
	long		time_of_last_meal;
	bool		full;
	pthread_t	thread_id;
	t_mtx		philo_mutex;
	t_fork		*first_fork;
	t_fork		*second_fork;
	t_table		*table;
}			t_philo;

typedef struct s_table
{
	long		nbr_philo;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		max_meals;
	long		start_simulation;
	long		nbr_threads_running;
	bool		end_simulation;
	bool		threads_ready;
	pthread_t	monitor;
	t_mtx		table_mutex;
	t_mtx		write_mutex;
	t_fork		*forks;
	t_philo		*philos;
}			t_table;

const char	*valid_nb(const char *str);

bool		is_number(char c);
bool		is_space(char c);
bool		get_bool(t_mtx *mutex, bool *value);
bool		simulation_finish(t_table *table);
bool		check_threads(t_mtx *mutex, long *threads, long philo_nbr);

long		get_long(t_mtx *mutex, long *value);
long		ft_atol(const char *str);
long		get_time(t_time_code time_code);

void		error_exit(const char *error);
void		parse_nb(t_table *table, char *av[]);
void		*safe_malloc(size_t bytes);
void		safe_mutex(t_mtx *mutex, t_code code);
void		mutex_error(int status, t_code code);
void		s_thr(pthread_t *thread, void *(*ft)(void *),
				void *data, t_code code);
void		thread_error(int status, t_code code);
void		philo_init(t_table *table);
void		init_data(t_table *table);
void		set_long(t_mtx *mutex, long *dest, long value);
void		set_bool(t_mtx *mutex, bool *dest, bool value);
void		precise_usleep(long usec, t_table *table);
void		write_status(t_philo_status status, t_philo *philo);
void		wait_threads(t_table *table);
void		*dinner_simulation(void *data);
void		start_dinner(t_table *table);
void		thinking(t_philo *philo, bool b_simulation);
void		increment_long(t_mtx *mutex, long *value);
void		*check_dinner(void *data);
void		*solo_philo(void *arg);
void		clean(t_table *table);
void		fair(t_philo *philo);

int			check_number(char *av);

#endif
