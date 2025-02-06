#include "../include/philo.h"

void    error_exit(const char *error)
{
    printf(RED"%s\n"RESET, error);
    exit(EXIT_FAILURE);

}

static bool is_space(char c)
{
    return((c >= 9 && c <= 13) || c == 32);
}

static bool is_number(char c)
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

