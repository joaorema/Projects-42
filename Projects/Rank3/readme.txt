The problem :
Make a program that simulates the philosophers problem ( one table , x nbr of philos and same nr of forks)

For this we are gonna use 3 structs.

s_philos :
this struct has 3 long variables:
- id 
- counter (nbr of meal already eaten), 
- time_of_last_meal (time since last meal)) 
will also have 2 s_forks (1 for each fork the philo will have) 1 s_table(to connect to philo to the table)1 mutex called philo_mutex so we can start and change things in the threads and finaly a thread called thread_id to keep track of the threads id.

s_fork : 
this struct will have 1 long called id_fork so its easy to identify wich fork is being picked by a philosopher. We also have a mutex for the fork so that we can avoid race conditions while the philos are trying to pick them up

s_table : 
this is were the simulation will happen so its the bigger of the 3 and were most of the fuctions will work with. for this struct we have 7 long variables:

- nbr_philos = nbr of philos that we are working. (will be defined by the av[1])
- time_to_die = time in milliseconds that will define how long can a philo survive without eating(this value will be the av[2] and will be converted to milliseconds)
- time_to_eat = how long it take in milliseconds for a philo to eat (av[3])
- time_to_sleep = how long it takes in milliseconds for a philo to sleep(av[4])
- max_meals : the nbr of meals needed to end the simulation. this variable is not mandatory for the program to work but when called will gather the av[5] and export the info for this variable
- start_simulation = where we store the time when simulation start to be easier to keep treck of the timestamps.
- nbr_threads_running = used to spinlock while we wait for all threads to be on the same place. (while nbr_threads_running < nbr_philos )

This struct also has 2 boolean variables:

- end_simulation = starts false if it turns true means the simulation ended ( exemples : philo dies, philo full etc)
- threads_ready = similiar to nbr_threads_running , will spinlock once all threads reach the simulation.

finaly this table has 1 s_fork , 1 s_philos, 2 mutex (write_mutex to write the output and table_mutex to run the simulation) and 1 thread called monitor that will check on the other running threads to check for dead condition.

Once this was set i decided to start first with parsing the arguments that are gonna be received to be sure to just accept valid inputs:

To achive this i made a parse_nb fuction that will work with 2 other fuction:

-valid_nbr(const char *str) : will take a string and skips spaces, skip plus sign , report error if a negative nbr is used (since we can't take negative time) and check if the str only contain numbers. to finish we calculated the lenght just to be sure if the number is not bigger than a long variable (len > 10 error exit)

-atol(const char *str) : will first check if the str is a valid_nbr with the previous ft. if the str is valid we will aplly a formula to turn the argument into longs.

so in summary in our main we first call parse_nb(t_table *table, char *av[]) that will put the values already in the table struct, will work with *av[] and we will already turn them values into milliseconds by * 1000. (if the values are to low we just close and return error message)
{
	table->nbr_philo = ft_atol(av[1]);   
	table->time_to_die = ft_atol(av[2]) * 1000;
	table->time_to_eat = ft_atol(av[3]) * 1000;
	table->time_to_sleep = ft_atol(av[4]) * 1000;
	if (table->time_to_die < 60000 || table->time_to_eat < 60000
		|| table->time_to_sleep < 60000)
		error_exit("Timestamp should be bigger than 60miliseconds!");
	if (av[5])
		table->max_meals = ft_atol(av[5]);
}

so once parsing is done and we have entered the correct values in the expected variables we will do the second part of our main :
void	init_data(t_table *table) this ft will define some starting values for some important variables, will alloc the necessary memory for each philo and for each fork and also start the mutex for table_mutex and write_mutex.
	table->end_simulation = false;
	table->threads_ready = false;
	table->nbr_threads_running = 0;
	table->philos = safe_malloc(sizeof(t_philo) * table->nbr_philo); // array of philos
	table->forks = safe_malloc(sizeof(t_fork) * table->nbr_philo); // array of forks
	safe_mutex(&table->table_mutex, INIT);	//void	safe_mutex(t_mtx *mutex, t_code code) *
	safe_mutex(&table->write_mutex, INIT);  

*safe mutex is done to keep the code cleared and avoid writing pthread_mutex_lock(mutex) or unlock over and over again. 

/////////////////////////////////////////////////////////////////////////////////////////////////////


after this our init_data is going to create a mutex for each fork and assign each one with a id:
i = -1;
	while (++i < table->nbr_philo)
	{
		safe_mutex(&table->forks[i].fork, INIT);
		table->forks[i].id_fork = i;
	}
finaly we call our void	philo_init(t_table *table) that will assign a id for each philo , will set the full boolean to false (since we are still starting) , will set the counter to 0 , export the info from the table to the philo,start the mutex for philo_mutex 
i = - 1
while (++i < table->nbr_philo)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->counter = 0;
		philo->table = table;
		safe_mutex(&philo->philo_mutex, INIT);
		give_forks(philo, table->forks, i);
	}
lastly assing the forks for each philo with our static void	give_forks(t_philo *philo, t_fork *forks, int index)
the give_fork will check if the philo is even or odd and then assign a fork for each one (the fork index starts at 0 and philo starts at 1)

If the philo is odd : 
if (!philo->id % 2 == 0)  // exemple first philo -> 
	{
		philo->first_fork = &forks[(index + 1) % nbr_philos];/fork index + 1 % nbr philos = fork 1
		philo->second_fork = &forks[index]; /fork index = fork 0
	}
the odd philo will first take left fork and then right fork

if the philo is even: 
if (philo->id % 2 == 0)
	{
		philo->first_fork = &forks[index]; 
		philo->second_fork = &forks[(index + 1) % nbr_philos];
	}
the even philo will first take the right fork and the left fork
once init_data is done we will the mutex for forks id , will have all the forks and philos made and all philos will know wich fork to pick.


///////////////////////////////////////////////////////////////////////////////////////////////////////

after doing init_data we will now call start_dinner that will run the simulation: 
void	start_dinner(t_table *table)

first we check if the nbr_meals = 0; if it is we just return else we continue
next we check is the nbr_philos = 1; if it is we create a single thread that will run a solo_philo ft
if nbr_philo > 1 we will create for each philo a thread that will be pointed to the fuction dinner_simulation
i = -1 
while (++i < table->nbr_philo)
		{
			s_thr(&table->philos[i].thread_id,
				dinner_simulation, &table->philos[i], CREATE);
		}
after that we create a new thread that will check_dinner (waits for all threads to be ready and on the same place, and while !simulation_finish it will keep track if any philos died. for this we set a variable elapsed that is the current time since simulation started - time_of_last_meal (so our current time - the starting time) and t_to_die that is the same value of time_to_die.
if (elapsed > t_to_die) then one philo died if not we continue to check while the simulation runs.
after that we set the start simulation time :
- table->start_simulation = get_time(MILLISECOND);
now that we have the starting time and have all threads prepared to start we set the bool threads_ready to true making removing all the spinlock and forcing all the threads to run there respective fuctions.
to end we join all the threads in philos to be sure we wait for all of them to execute and once thats done we set end simulation to true and wait for the monitor to also finish.
i = -1;
	while (++i < table->nbr_philo)
		s_thr(&table->philos[i].thread_id,NULL, NULL, JOIN);
	set_bool(&table->table_mutex, &table->end_simulation, true);
	s_thr(&table->monitor, NULL, NULL, JOIN);


		

