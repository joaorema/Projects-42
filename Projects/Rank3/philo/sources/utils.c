#include "../include/philo.h"

void    error_exit(const char *error)
{
    printf(RED"%s\n"RESET, error);
    exit(EXIT_FAILURE);

}

bool is_space(char c)
{
    return((c >= 9 && c <= 13) || c == 32);
}

bool is_number(char c)
{
    return(c >= '0' && c <= '9');
}

void    *safe_malloc(size_t bytes)
{
    void *ret;
    
    ret = malloc(bytes);
    if(!ret)
        error_exit("Error with MAlloc!");
    return (ret);
}

long    get_time(t_time_code time_code)
{
    struct timeval time;
    
    if(gettimeofday(&time, NULL))   // will write the time on the time variable (seconds, microseconds)
        error_exit("Failed gettimeofday!");
    if(time_code == SECOND)
        return(time.tv_sec + (time.tv_usec / 1000000));  
    else if(time_code == MILLISECOND)
        return((time.tv_sec * 1000) + (time.tv_usec / 1000));
    else if(time_code == MICROSECOND)
        return ((time.tv_sec * 1000000) + time.tv_usec);
    else    
        error_exit("Wrong input to gettime!");
    return (69);
}

void    precise_usleep(long usec, t_table *table)
{
    long start;
    long elasped;
    long remaining;

    start = get_time(MICROSECOND);
    while(get_time(MICROSECOND) - start < usec)   ///
    {
        if(simulation_finish(table))
            break;
        elasped = get_time(MICROSECOND) - start;
        remaining = usec - elasped;
        if(remaining > 1000) // if remaining bigger than 1millisecond
            usleep(remaining / 2);
        else
        {
            while(get_time(MICROSECOND) - start < usec)
                ;
        }
    }
}