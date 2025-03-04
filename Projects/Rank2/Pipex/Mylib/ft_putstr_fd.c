/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:00:13 by jpedro-c          #+#    #+#             */
/*   Updated: 2024/10/23 14:04:30 by jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}
/*
#include <fcntl.h>
#include "libft.h"

int main(void)
{
    int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1)
    {
        return 1; // Error opening file
    }

    ft_putstr_fd("Hello, world!", fd);

    close(fd);
    return 0;
}
*/
