#include "../Mylib/libft.h"
#include "../mlx_linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

typedef struct s_data{
    void    *img;
    char    *addr;
    int bits_per_pixel;
    int line_lenght;
    int endian;
}       t_data;

typedef struct s_setup {
    void    *mlx;
    void    *win;
}   t_setup;

typedef struct s_position {
    int x;
    int y;
}       t_position;

typedef struct s_game {
    int map_height; // nr de linha do mapa
    int map_witdh; 
    char **map;
    char **map_temp;
    int players;
    int player_x;
    int player_y;
    int exit;
    int collect;
    int check_collect;
    int path;
    void *walls;
    void *ground;
}   t_game;

void my_mlx_pixel_put(t_data *data, int x, int y, int color);
void check_map(t_game *game);
void check_letters(t_game *game);
void check_letter(t_game *game, int x, int y);
void check_wall(t_game *game);
void c_map_height(t_game *game, char *text);
void check_tile(t_game *game, t_position pos, t_position *stack, int *top);
void flood_fill_check(t_game *game);
void ft_clear(t_game *game);
void close_game(t_game *game, char *text);
void load_map(t_game *game, char *file);
void c_map_width(t_game *game, char *text);

int check_form(t_game *game);
int handle_keyboard(int keycode, void *param);
int handle_mouse(int keycode, void *param);
int valid_position(t_game *game, int x, int y);
