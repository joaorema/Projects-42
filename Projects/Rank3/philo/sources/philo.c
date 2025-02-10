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
    return 0;
      
}
/* void  *dinner_simulation(void *data)
{
  t_philo *philo;

  philo = (t_philo *)data;

  // check if all threads are crated 
    wait_all_thread(philo->table);

  //set timer before meals

  //run simulation
  while(!simulation_finish(philo->table))
  {
    // is philo full?
    if(get_long())
      break;
    // eat

    //sleep

    //think
  }
} */
/*
static void eat(t_philo *philo)
{
  safe_mutex(&philo->first_fork->fork, LOCK);
  write_status(FIRST_FORK, philo);
  safe_mutex(&philo->second_fork->fork, LOCK);
  write_status(SECOND_FORK, philo);


}
*/