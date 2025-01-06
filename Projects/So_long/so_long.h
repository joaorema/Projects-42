#include <stdio.h>
#include <stdlib.h>
#include "Mylib/libft.h"
#include <stdbool.h>

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

typedef struct s_game {
    int map_height; // nr de linha do mapa
    int map_witdh; 
    char **map;
    char **map_temp;
    int player;
    int player_x;
    int player_y;
    int exit;
    int collect;



   
}   t_game;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
int     handle_keyboard(int keycode, void *param);
int handle_mouse(int keycode, void *param);
