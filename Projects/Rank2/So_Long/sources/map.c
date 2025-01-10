/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpedro-c <joaopcrema@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:38:22 by Jpedro-c          #+#    #+#             */
/*   Updated: 2025/01/10 15:38:39 by Jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"
#include "../mlx_linux/mlx.h"
#include "../Mylib/libft.h"

void	load_map(t_game *game, char *file)
{
	int		fd;
	char	*temp;
	int		i;

	c_map_height(game, file);
	fd = open(file, O_RDONLY);
	game->map = ft_calloc(game->map_height + 1, sizeof(char *));
	game->map_temp = ft_calloc(game->map_height + 1, sizeof(char *));
	if (!game->map || !game->map_temp)
		close_game(game, "Memory allocation failed!");
	i = -1;
	while (++i < game->map_height)
	{
		game->map[i] = get_next_line(fd);
		game->map_temp[i] = ft_strdup(game->map[i]);
	}
	temp = get_next_line(fd);
	free(temp);
	game->map[i] = NULL;
	game->map_temp[i] = NULL;
	close(fd);
	game->map_witdh = ft_strlen(game->map[0]) - 1;
}

void	render_tile(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall_image, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collect_image, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit_close_image, x * TILE_SIZE, y * TILE_SIZE);
		if (game->exit_open)
			mlx_put_image_to_window(game->mlx, game->win,
				game->exit_open_image, x * TILE_SIZE, y * TILE_SIZE);
	}
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player_image, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->ground_image, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_witdh)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
}
