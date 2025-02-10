define dis
display table->nbr_philo
display table->time_to_die   
display table->time_to_eat  
display table->time_to_sleep
display table->max_meals
display table->start_simulation
display table->end_simulation
display table->philos
display table->forks
display i
display table->fork[i].id_fork

end

define parse
break parse_nb
run
display table->nbr_philo
display table->time_to_die 
display table->time_to_eat 
display table->time_to_sleep
display table->max_meals
end

define init
break init_data
run
display i
display table->end_simulation
display table->fork[i].fork
display forks[i].id_fork
