#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>
#include <errno.h>

# define RESET  "\033[0m"
# define RED    "\033[1;31m"
# define GREEN  "\033[1;32m"

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


static bool is_number(char c);
static bool is_space(char c);
void    error_exit(const char *error);
long	ft_atol(const char *str);
void    parse_nb(t_table *table, char *av[]);
void    *safe_malloc(size_t bytes);
void    safe_mutex(t_mtx *mutex, t_code code);
void    mutex_error(int status, t_code code);
void    safe_thread(pthread_t *thread, void *(*ft)(void *), void *data, t_code code);
void    thread_error(int status, t_code code);
void    philo_init(t_table *table);
void    init_data(t_table *table);
static const char *valid_nb(const char *str);

typedef struct s_fork t_fork;
typedef struct s_philo t_philo;
typedef struct s_table t_table;
typedef pthread_mutex_t t_mtx;

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
    int     full;
    t_fork  *first_fork;
    t_fork  *second_fork;
    pthread_t thread_id; 
    t_table  *table;
}              t_philo;

// philo 5 800 200 200 [5]

typedef struct s_table
{
    long    nbr_philo;      // 5
    long    time_to_die;    // 800
    long    time_to_eat;    // 200
    long    time_to_sleep;  // 200
    long    max_meals;     //[5]
    long    simulation;
    bool    end_simulation;  // a philo dies or they are full;
    t_fork  *forks;    // array of forks
    t_philo *philos;  // array of philosophers;
}               t_table;

#endif