#include "../include/philo.h"

int main(int ac, char *av[])
{
    t_table table;

    if(ac == 5 || ac == 6)
    {
      parse_nb(&table, av);
      init_data(&table);
      philo_init(&table);
      printf("nbr of philos : %ld\n", table.nbr_philo);       
    }
    else
        error_exit("Invalid nbr of arguments!");
      
}
