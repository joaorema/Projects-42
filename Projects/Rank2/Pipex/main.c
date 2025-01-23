/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpedro-c <joaopcrema@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:38:52 by jpedro-c          #+#    #+#             */
/*   Updated: 2025/01/23 14:33:40 by Jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char *envp[])
{
	int		fd[2];
	pid_t	pid;

	check_envp(envp);
	if (ac == 5)
	{
		pipe(fd);
		if (pipe(fd) == -1)
			perror("pipe failed");
		pid = fork();
		if (pid == -1)
		{
			perror("fork failed");
			close_fd(fd);
		}
		else if (pid == 0)
			second_process(av, fd, envp);
		main_process(av, fd, envp);
	}
	else
	{
		ft_printf("Error. Try using : ./pipex file1 cmd1 cmd2 file2\n");
		exit (WRONG_AC);
	}
	return (0);
}

void	main_process(char *av[], int *fd, char *envp[])
{
	int	fd_nb;

	close(fd[1]);
	fd_nb = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_nb == -1)
	{
		perror(av[4]);
		close_fd(fd);
		exit (FAILURE);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(fd_nb, STDOUT_FILENO);
	ft_cmd(av[3], envp, fd);
}

void	second_process(char *av[], int *fd, char *envp[])
{
	int	fd_nb;

	close(fd[0]);
	fd_nb = open(av[1], O_RDONLY, 0777);
	if (fd_nb == -1)
	{
		perror(av[1]);
		close_fd(fd);
		exit (FAILURE);
	}
	dup2(fd[1], STDOUT_FILENO);
	dup2(fd_nb, STDIN_FILENO);
	ft_cmd(av[2], envp, fd);
}
