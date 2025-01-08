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
    {
        close_game(game, "ESC key pressed, closing window.");
    }
    if(keycode == 119 || keycode == 65362)  // andar para cima
    {
        ft_printf("Moving Up.\n");
         
    }
    if(keycode == 115 || keycode == 65364)  // andar para baixo
    {
        ft_printf("Moving down.\n");
    }
    if(keycode == 97 || keycode == 65361)  // andar para esquerda
    {
        ft_printf("Moving left.\n");
    } 
    if(keycode == 100 || keycode == 65363)  // andar para direita
    {
        ft_printf("Moving right.\n");
    }
    return 0;
}

int handle_mouse(int keycode, t_game game)  // para controlar mouse
{
    if(keycode == 1)
    {
        ft_printf("left mouse button clicked\n");
    }
    if(keycode == 2)
    {
        ft_printf("right mouse button clicked\n");
    }
    if(keycode == 3)
    {
        ft_printf("middle mouse button clicked\n");
    }
    if(keycode == 4)
    {
        ft_printf("scroll up mouse button clicked\n");
    }
    if(keycode == 5)
    {
        ft_printf("scroll down mouse button clicked\n");
    }
    return 0;
}
