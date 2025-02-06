#include "../include/philo.h"

int main(int ac, char *av[])
{
    t_table table;
    (void)av;
    long teste1 = ft_atol(av[1]);
    long teste2 = ft_atol(av[2]);
    long teste3 = ft_atol(av[3]);
    long teste4 = ft_atol(av[4]);
    long teste5 = ft_atol(av[5]);

    if(ac == 5 || ac == 6)
    {
        teste1 = ft_atol(av[1]);
        teste2 = ft_atol(av[2]);
        teste3 = ft_atol(av[3]);
        teste4 = ft_atol(av[4]);
        teste5 = ft_atol(av[5]);   
        printf(GREEN "nbr of philosophers : %ld / nb of milisecond until philo dies from hunger : %ld / how much time it takes to eat : %ld / time needed for sleep: %ld / how many times they need to eat : %ld \n"RESET, teste1, teste2, teste3, teste4, teste5);
    }
    else
    error_exit("Wrong number of arguments! Try:\n"
                GREEN"./philo 5 800 200 200 [5]"RESET);
    return 0;
}
