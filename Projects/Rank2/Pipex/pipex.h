/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:51:02 by jpedro-c          #+#    #+#             */
/*   Updated: 2025/01/21 13:51:04 by jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define SUCCESS 0
# define FAILURE 1
# define WRONG_AC 2
# define WRONGPATH 3

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include "Mylib/libft.h"

void	close_fd(int *fd);
void	main_process(char *av[], int *fd, char *envp[]);
void	second_process(char *av[], int *fd, char *envp[]);
void	close_fd(int *fd);
void	ft_free(char *str[]);
char	*find_dir(char *cmd, char *envp[]);
void	ft_cmd(char *av, char *envp[], int *fd);

#endif 
