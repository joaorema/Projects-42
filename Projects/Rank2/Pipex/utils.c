/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpedro-c <joaopcrema@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:43:22 by jpedro-c          #+#    #+#             */
/*   Updated: 2025/01/23 14:35:55 by Jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fd(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

void	ft_free(char *str[])
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	check_envp(char *envp[])
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

char	*find_dir(char *cmd, char *envp[])
{
	char	*half_path;
	char	**full_path;
	char	*path;
	int		i;

	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	full_path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (full_path[i])
	{
		half_path = ft_strjoin(full_path[i], "/");
		path = ft_strjoin(half_path, cmd);
		free(half_path);
		if (access(path, F_OK | X_OK) == 0)
			return (ft_free(full_path), path);
		free(path);
		i++;
	}
	return (ft_free(full_path), NULL);
}

void	ft_cmd(char *av, char *envp[], int *fd)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	path = find_dir(cmd[0], envp);
	if (!path)
	{
		ft_free(cmd);
		ft_printf("not a valid path!");
		close_fd(fd);
		exit(WRONGPATH);
	}
	if (execve(path, cmd, envp) == -1)
	{
		ft_free(cmd);
		close_fd(fd);
		exit(FAILURE);
	}
}
