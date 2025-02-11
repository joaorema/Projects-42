#include "../include/philo.h"

void    set_bool(t_mtx *mutex, bool *dest, bool value)
{
    safe_mutex(mutex, LOCK);
    *dest = value;
    safe_mutex(mutex, UNLOCK);
}

bool    get_bool(t_mtx *mutex, bool *value)
{
    bool ret;

    safe_mutex(mutex, LOCK);
    ret = *value;
    safe_mutex(mutex, UNLOCK);
    return 1;
}

void   set_long(t_mtx *mutex, long *dest, long value)
{
    safe_mutex(mutex, LOCK);
    *dest = value;
    safe_mutex(mutex, UNLOCK);
}

long    get_long(t_mtx *mutex, long *value)
{
    bool ret;

    safe_mutex(mutex, LOCK);
    ret = *value;
    safe_mutex(mutex, UNLOCK);
    return 1;
}

bool    simulation_finish(t_table *table)
{
    return(get_bool(&table->table_mutex, &table->end_simulation));
}