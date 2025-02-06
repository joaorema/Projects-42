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

static const char *valid_nb(const char *str)
{
    int len;
    const char *nb;
    int i;

    i = 0;
    len = 0;
    while(is_space(str[i]))
        i++;
    if(str[i] == '+')
        i++;
    else if(str[i] == '-')
        error_exit("Error. Program only take positive numbers!\n");
    if(!is_number(str[i]))
        error_exit("Error. Input need to be numbers!");
    nb = str;
    while(is_number(str[i++]))
        len++;
    if(len > 10)
        error_exit("Error. The number is to big / int_max is the limit!");
    return nb;
}

long	ft_atol(const char *str)
{
	long    nb;

    nb = 0;
    str = valid_nb(str);

	while (is_number(*str))
	{
		nb = nb * 10 + (*str - '0');
        str++;
	}
	if(nb > INT_MAX)
        error_exit("Error. The number is to big / int_max is the limit!");
    return nb;
}   