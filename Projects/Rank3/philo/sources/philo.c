#include "../include/philo.h"

int main(int ac, char *av[])
{
    t_table table;

    if(ac == 5 || ac == 6)
    {
      parse_nb(&table, av);   //takes the arguments and iniciates the values on the table
      init_data(&table);     //inserts the info and starts all the mutex init for forks 
      start_dinner(&table);
      clean(&table);
      
      return 0;      
    }
    else
        error_exit("Invalid nbr of arguments!");
    return 0;
      
}
