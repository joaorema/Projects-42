/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpedro-c <joaopcrema@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:38:34 by Jpedro-c          #+#    #+#             */
/*   Updated: 2025/01/10 15:38:35 by Jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"
#include "../mlx_linux/mlx.h"
#include "../Mylib/libft.h"

void	close_game(t_game *game, char *text)
{
	if (game->map)
		ft_clear(game);
	if (text)
		ft_printf("%s\n", text);
	exit (0);
}

int	close_game_clean(t_game *game)
{
	if (game->map)
	{
		ft_clear(game);
	}
	exit (0);
}

void	ft_clear(t_game *game)
{
	int	i;

	if (!game || !game->map)
		return ;
	i = 0;
	while (i < game->map_height)
	{
		free(game->map[i]);
		free(game->map_temp[i]);
		i++;
	}
	free(game->map);
	free(game->map_temp);
	destroy_game(game);
	game->map = NULL;
	game->map_temp = NULL;
}

t_game	start_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->map_temp = NULL;
	game->map_height = 0;
	game->map_witdh = 0;
	game->player_y = 0;
	game->player_x = 0;
	game->collect = 0;
	game->players = 0;
	game->exit = 0;
	game->moves = 0;
	game->path = 0;
	game->exit_open = 0;
	game->wall_image = NULL;
	game->ground_image = NULL;
	game->player_image = NULL;
	game->player_image_left = NULL;
	game->player_image_right = NULL;
	game->collect_image = NULL;
	game->exit_close_image = NULL;
	game->exit_open_image = NULL;
	return (*game);
}

void	destroy_game(t_game *game)
{
	if (game->wall_image)
		mlx_destroy_image(game->mlx, game->wall_image);
	if (game->player_image)
		mlx_destroy_image(game->mlx, game->player_image);
	if (game->ground_image)
		mlx_destroy_image(game->mlx, game->ground_image);
	if (game->collect_image)
		mlx_destroy_image(game->mlx, game->collect_image);
	if (game->exit_close_image)
		mlx_destroy_image(game->mlx, game->exit_close_image);
	if (game->exit_open_image)
		mlx_destroy_image(game->mlx, game->exit_open_image);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}
