/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpedro-c <joaopcrema@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:38:32 by Jpedro-c          #+#    #+#             */
/*   Updated: 2025/01/10 15:38:37 by Jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */\
#include "../include/so_long.h"
#include "../mlx_linux/mlx.h"
#include "../Mylib/libft.h"

void	c_map_height(t_game *game, char *text)
{
	int		fd;
	char	*line;

	game->map_height = 0;
	fd = open(text, O_RDONLY);
	if (fd < 0 || strcmp(text + (ft_strlen(text) - 4), ".ber") != 0)
	{
		close_game(game, "Error, file not valid");
	}
	line = get_next_line(fd);
	if (!line)
		close_game(game, "Error, file not valid");
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		game->map_height++;
	}
	close(fd);
}

void	c_map_width(t_game *game, char *text)
{
	int		fd;
	int		counter;
	char	*line;
	int		first;

	game->map_witdh = 0;
	fd = open(text, O_RDONLY);
	line = get_next_line(fd);
	counter = ft_strlen(line);
	first = counter;
	if (!line)
		close_game(game, "Error, file not valid");
	counter = ft_strlen(line);
	first = counter;
	while (line != NULL && first == counter)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			close_game(game, "Error, file not valid");
		counter = ft_strlen(line);
	}
	game->map_witdh = first;
}
