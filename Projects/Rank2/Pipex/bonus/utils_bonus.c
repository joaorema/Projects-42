#include "../pipex.h"

void    ft_close_fd(int *fd)
{
    close(fd[0]);
    close(fd[1]);

}

void    ft_free_bonus(char *str[])
{
    int     i;

    i = 0;
    while(str[i])
        free(str[i++]);
    free(str);
}

int     set_files(char *file, int n)
{
    int     i;

    if(n == 1)
        i = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if(n == 2)
        i = open(file, O_RDONLY | O_CREAT | O_APPEND, 0777);
    if(i == -1)
        exit(1);
    return(i);
}

char    *find_dir_bonus(char *cmd, char *envp[])
{
    char    **inicial_path;
    char    *half_path;
    char    *path;
    int     i;

    i = 0;
    while(ft_strnstr(envp[i], "PATH=", 5) == 0)
        i++;
    inicial_path = ft_split(envp[i] + 5, ':');
    i = 0;
    while(inicial_path[i])
    {
        half_path = ft_strjoin(inicial_path[i], "/");
        path = ft_strjoin(half_path, cmd);
        free(half_path);
        if(access(path, F_OK | X_OK) == 0)
            return(ft_free_bonus(inicial_path), path);
        free(path);
        i++;
    }
    return (ft_free_bonus(inicial_path), NULL);
}

void    run_cmd(char *av, char *envp[], int *fd)
{
    char    **cmd;
    char    *path;

    cmd = ft_split(av, ' ');
    path = find_dir_bonus(cmd[0], envp);
    if(!path)
    {
        ft_free_bonus(cmd);
        ft_putstr_fd("Path is not valid!", 2);
        ft_close_fd(fd);
        exit(1);
    }
    if(execve(path, cmd, envp) == -1)
    {
        ft_free_bonus(cmd);
        ft_close_fd(fd);
        ft_putstr_fd("Can't execute command!", 2);
        exit (1);
    }
}