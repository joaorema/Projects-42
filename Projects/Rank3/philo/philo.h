#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>

# define RESET  "\033[0m"
# define RED    "\033[1;31m"
# define GREEN  "\033[1;32m"


void    error_exit(const char *error);
static const char *valid_nb(const char *str);
static bool is_number(char c);
static bool is_space(char c);
long	ft_atol(const char *str);


typedef struct s_fork t_fork;
typedef struct s_philo t_philo;
typedef struct s_table t_table;

typedef struct s_fork
{
    pthread_mutex_t fork;
    int             id_fork;

}               t_fork;

typedef struct s_philo
{
    int     id;
    long    counter;
    long    time_of_last_meal;
    int     full;
    t_fork  *left_fork;
    t_fork  *right_fork;
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