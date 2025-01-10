#include "../include/so_long.h"
#include "../mlx_linux/mlx.h"
#include "../Mylib/libft.h"

void user_input(t_game *game)
{
    mlx_key_hook(game->win, handle_keyboard, game);
    mlx_hook(game->win, 4, 1L<<2, handle_mouse, game);
}

int     handle_keyboard(int keycode, t_game *game)
{ 
    if(keycode == 65307)
        close_game(game, "ESC key pressed, closing window.");
    if(keycode == 119 || keycode == 65362)  // andar para cima
        player_move(game, 0, -1);
    if(keycode == 115 || keycode == 65364)  // andar para baixo
        player_move(game, 0, 1);
    if(keycode == 97 || keycode == 65361)  // andar para esquerda
    {
        game->player_image = game->player_image_left;
        player_move(game, -1, 0);
    }
    if(keycode == 100 || keycode == 65363)  // andar para direita
    {   
        game->player_image = game->player_image_right;
        player_move(game, 1, 0);
    }
    return 0;
}

int handle_mouse(int keycode, t_game game)  // para controlar mouse
{
    if(keycode == 1)
        ft_printf("left mouse button clicked\n");
    if(keycode == 2)
        ft_printf("right mouse button clicked\n");
    if(keycode == 3)
        ft_printf("middle mouse button clicked\n");
    if(keycode == 4)
        ft_printf("scroll up mouse button clicked\n");
    if(keycode == 5)
        ft_printf("scroll down mouse button clicked\n");
    return 0;
}

void update_game(t_game *game)
{
    if(game->map[game->player_y][game->player_x] == 'C')
    {
        game->collect--;
        game->map[game->player_y][game->player_x] = '0';
        if(game->collect <= 0)
            game->exit_open = 1;
    }
    if(game->map[game->player_y][game->player_x] == 'E' && game->exit_open)
        close_game(game, "You won!");
    if(game->map[game->player_y][game->player_x] == '0')
        game->map[game->player_y][game->player_x] = 'P';
    
}

void player_move(t_game *game, int dx, int dy)
{
    if(game->map[game->player_y + dy][game->player_x + dx] == '1')
        return;
    game->player_x = game->player_x + dx;
    game->player_y = game->player_y + dy;
    if(game->map[game->player_y][game->player_x] == 'E' && !game->exit_open)
    {
        game->player_x = game->player_x - dx;
        game->player_y = game->player_y - dy;
    }
    else
    {
        game->map[game->player_y - dy][game->player_x - dx] = '0';
        game->moves++;
        ft_printf("Move: %d\n", game->moves);
        update_game(game);
        render_map(game);
    }
}


