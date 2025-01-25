#include "../pipex.h"

int	check_envp_bonus(char *envp[])
{
	int	i;

	i = 0;
	if (!envp[i])
	{
		ft_putstr_fd("No Enviroment Variables!\n", 2);
		exit (FAILURE);
	}
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (!envp[i])
	{
		ft_putstr_fd("No Path variable in the envp\n", 2);
		exit (4);
	}
	return (i);
}

void    main_process_bonus(char *av[], char *envp[])
{
    int     fd[2];
    pid_t   pid;

    check_envp_bonus(envp);
    if(pipe(fd) == -1)
        ft_putstr_fd("Pipe failed!", 2);
    pid = fork();
    if(pid == -1)
    {
        ft_putstr_fd("Fork failed!", 2);
        ft_close_fd(fd);
    }
    if(pid == 0)
    {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        run_cmd(*av, envp, fd);
    }
    close(fd[1]);
    dup2(fd[0], STDIN_FILENO);
    waitpid(pid, NULL, 0);
}

int     main(int ac, char *av[], char *envp[])
{
    int     i;
    int     file1;
    int     file2;

    if(ac >= 5)
    {
        i = 2;
        file1 = set_files(av[1], 2);
        file2 = set_files(av[ac - 1], 1);
        dup2(file1, STDIN_FILENO);
        while(i < ac - 2)
            main_process_bonus(&av[i++], envp);
        dup2(file2, STDOUT_FILENO);
        run_cmd(av[ac - 2], envp, NULL);
    }
    ft_putstr_fd("Invalid nbr of arguments!", 2);
}
