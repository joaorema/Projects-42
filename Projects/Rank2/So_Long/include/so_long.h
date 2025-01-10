/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jpedro-c <joaopcrema@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:35:32 by jpedro-c          #+#    #+#             */
/*   Updated: 2025/01/10 15:38:36 by Jpedro-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE_SIZE 32

# include "../Mylib/libft.h"
# include "../mlx_linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_game
{
	void	*walls;
	void	*ground;
	void	*mlx;
	void	*win;
	void	*wall_image;
	void	*ground_image;
	void	*player_image;
	void	*player_image_right;
	void	*player_image_left;
	void	*collect_image;
	void	*exit_close_image;
	void	*exit_open_image;
	char	**map;
	char	**map_temp;
	int		players;
	int		player_x;
	int		player_y;
	int		exit;
	int		collect;
	int		check_collect;
	int		path;
	int		moves;
	int		exit_open;
	int		map_height;
	int		map_witdh;
}	t_game;

void	check_map(t_game *game);
void	check_letters(t_game *game);
void	check_letter(t_game *game, int x, int y);
void	check_wall(t_game *game);
void	c_map_height(t_game *game, char *text);
void	check_tile(t_game *game, t_position pos, t_position *stack, int *top);
void	flood_fill_check(t_game *game);
void	ft_clear(t_game *game);
void	close_game(t_game *game, char *text);
void	load_map(t_game *game, char *file);
void	c_map_width(t_game *game, char *text);
void	load_images(t_game *game);
void	start_window(t_game *game);
void	render_map(t_game *game);
void	render_tile(t_game *game, int x, int y);
void	user_input(t_game *game);
void	player_move(t_game *game, int dx, int dy);
void	update_game(t_game *game);
void	destroy_game(t_game *game);

int		check_form(t_game *game);
int		handle_keyboard(int keycode, t_game *game);
int		handle_mouse(int keycode, t_game game);
int		valid_position(t_game *game, int x, int y);
int		close_game_clean(t_game *game);
int		main_loop(t_game *game);
t_game	start_game(t_game *game);

#endif
