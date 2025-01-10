/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpedro-c <joaopcrema@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:38:19 by Jpedro-c          #+#    #+#             */
/*   Updated: 2025/01/10 15:38:39 by Jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"
#include "../mlx_linux/mlx.h"
#include "../Mylib/libft.h"

int	main(int ac, char *av[])
{
	t_game	game;

	game = start_game(&game);
	if (ac != 2)
		return (ft_printf("Error. To start game ./so_long <map_file>\n"));
	load_map(&game, av[1]);
	check_map(&game);
	flood_fill_check(&game);
	load_images(&game);
	start_window(&game);
	render_map(&game);
	user_input(&game);
	mlx_loop_hook(game.mlx, main_loop, &game);
	mlx_hook(game.win, 17, 0, close_game_clean, &game);
	mlx_loop(game.mlx);
}

int	main_loop(t_game *game)
{
	user_input(game);
	return (0);
}
