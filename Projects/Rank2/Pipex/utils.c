/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:43:22 by jpedro-c          #+#    #+#             */
/*   Updated: 2025/01/21 13:43:25 by jpedro-c         ###   ########.fr       */
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

char	*find_dir(char *cmd, char *envp[])
{
	char	*half_path;
	char	**full_path;
	char	*path;
	int		i;

	i = 0;
	if (!envp[i])
		exit (FAILURE);
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
