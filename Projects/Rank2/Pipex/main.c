#include "pipex.h"

int     main(int ac, char *av[], char *envp[])
{
    int     fd[2];
    pid_t   pid;

    if(ac == 5)
    {
        pipe(fd);
        if(pipe(fd) == -1)
            perror("pipe failed");
        pid = fork();
        if(pid == -1)
        {
            perror("fork failed");
            close_fd(fd);
        }    
        else if(pid == 0)
            second_process(av, fd, envp);
        main_process(av, fd, envp);
    }
    else
    {
        ft_printf("Error. Try using : ./pipex file1 cmd1 cmd2 file2\n");
        exit (WRONG_AC);
    }
    return 0;
}

void    main_process(char *av[], int *fd, char *envp[])     //segundo ficheiro
{
    int     fd_nb;

    close(fd[1]);
    fd_nb = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if(fd_nb == -1)
    {
        perror(av[4]);
        close_fd(fd);
        exit (FAILURE);
    }
    dup2(fd[0], STDIN_FILENO); // DEIXOU DE RECEBER DO TECLADO E LE DO PIPE
    dup2(fd_nb, STDOUT_FILENO); // VAI ESCREVER NO FILE2
    ft_cmd(av[3], envp, fd);
}

void    second_process(char *av[], int *fd, char *envp[])   //primeiro ficheiro
{   
    int     fd_nb;

    close(fd[0]);
    fd_nb = open(av[1], O_RDONLY, 0777);
    if(fd_nb == -1)
    {
        perror(av[1]);
        close_fd(fd);
        exit (FAILURE);
    }
    dup2(fd[1], STDOUT_FILENO);  // escrever no fd[1] = pipe
    dup2(fd_nb, STDIN_FILENO);  //receber info do file1
    ft_cmd(av[2], envp, fd);
}
