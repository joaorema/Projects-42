/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpedro-c <joaopcrema@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:38:26 by Jpedro-c          #+#    #+#             */
/*   Updated: 2025/01/10 15:38:38 by Jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"
#include "../mlx_linux/mlx.h"
#include "../Mylib/libft.h"

int	check_form(t_game *game)
{
	int		i;
	size_t	size;

	if (!game->map || game->map_height == 0)
		return (0);
	i = 0;
	size = ft_strlen(game->map[0]);
	while (i < game->map_height -1)
	{
		if (ft_strlen(game->map[i]) != size)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	check_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_witdh)
	{
		if (game->map[0][i] != '1' || game->map[game->map_height - 1][i] != '1')
			close_game(game, "Error, map is file not valid");
		i++;
	}
	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->map_witdh - 1] != '1')
			close_game(game, "Error, map is file not valid");
		i++;
	}
}

void	check_letter(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'P')
	{
		game->players++;
		game->player_x = x;
		game->player_y = y;
	}
	else if (game->map[y][x] == 'E')
		game->exit++;
	else if (game->map[y][x] == 'C')
		game->collect++;
	else if (game->map[y][x] != 'C' && game->map[y][x] != 'E'
			&& game->map[y][x] != 'P' && game->map[y][x] != '1'
			&& game->map[y][x] != '0')
		close_game(game, "Error, map is file not valid");
}

void	check_letters(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_witdh)
		{
			check_letter(game, x, y);
			x++;
		}
		y++;
	}
}

void	check_map(t_game *game)
{
	if (!check_form(game))
		close_game(game, "Error, map is not the correct shape");
	check_wall(game);
	check_letters(game);
	if (game->collect <= 0 || game->exit != 1 || game->players != 1)
		close_game(game, "Error, map is not valid!.");
}
