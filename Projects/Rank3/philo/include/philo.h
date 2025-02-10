#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdbool.h>
#include <limits.h>
#include <errno.h>

# define RESET  "\033[0m"
# define RED    "\033[1;31m"
# define GREEN  "\033[1;32m"

typedef struct s_fork t_fork;
typedef struct s_philo t_philo;
typedef struct s_table t_table;
typedef pthread_mutex_t t_mtx;

typedef enum e_status
{
    EATING,
    SLEEPING,
    THINKING,
    FIRST_FORK,
    SECOND_FORK,
    DIED,
}           t_philo_status;

typedef enum s_code
{
    LOCK,
    UNLOCK,
    INIT,
    DESTROY,
    CREATE,
    JOIN,
    DETACH,
}           t_code;

typedef enum s_time_code
{
    SECOND,
    MILLISECOND,
    MICROSECOND,
}           t_time_code;

typedef struct s_fork
{
    t_mtx       fork;
    int         id_fork;

}               t_fork;

typedef struct s_philo
{
    int     id;
    long    counter;
    long    time_of_last_meal;
    long     full;
    t_fork  *first_fork;
    t_fork  *second_fork;
    pthread_t thread_id; 
    t_table  *table;
}              t_philo;

typedef struct s_table
{
    long    nbr_philo;      // 5
    long    time_to_die;    // 800
    long    time_to_eat;    // 200
    long    time_to_sleep;  // 200
    long    max_meals;     //[5]
    long    start_simulation;
    bool    end_simulation;  // a philo dies or they are full;
    t_mtx   table_mutex;
    t_mtx   write_mutex;
    t_fork  *forks;    // array of forks
    t_philo *philos;  // array of philosophers;
}               t_table;

static const char *valid_nb(const char *str);
bool    is_number(char c);
bool    is_space(char c);
bool    get_long(t_mtx *mutex, bool *value);
bool    get_bool(t_mtx *mutex, bool *value);
bool    simulation_finish(t_table *table);
long	ft_atol(const char *str);
long    get_time(t_time_code time_code);
void    error_exit(const char *error);
void    parse_nb(t_table *table, char *av[]);
void    *safe_malloc(size_t bytes);
void    safe_mutex(t_mtx *mutex, t_code code);
void    mutex_error(int status, t_code code);
void    safe_thread(pthread_t *thread, void *(*ft)(void *), void *data, t_code code);
void    thread_error(int status, t_code code);
void    philo_init(t_table *table);
void    init_data(t_table *table);
void    set_long(t_mtx *mutex, bool *dest, bool value);
void    set_bool(t_mtx *mutex, bool *dest, bool value);
void    precise_usleep(long usec, t_table *table);
void    write_status(t_philo_status status, t_philo *philo);

#endif