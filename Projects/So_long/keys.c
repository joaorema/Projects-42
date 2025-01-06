#include "so_long.h"
#include "mlx_linux/mlx.h"
#include "Mylib/libft.h"

int     handle_keyboard(int keycode, void *param)  // para controlar keyboard
{
    t_setup *vars = (t_setup *)param; 
    if(keycode == 65307)
    {
        ft_printf("ESC key pressed, closing window.\n");
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
    if(keycode == 119 || keycode == 65362)  // andar para cima
    {
        ft_printf("W key pressed.\n");
         
    }
    if(keycode == 115 || keycode == 65364)  // andar para baixo
    {
        ft_printf("S key pressed.\n");
    }
    if(keycode == 97 || keycode == 65361)  // andar para esquerda
    {
        ft_printf("A key pressed.\n");
    } 
    if(keycode == 100 || keycode == 65363)  // andar para direita
    {
        ft_printf("D key pressed.\n");
    }
    return 0;
}

int handle_mouse(int keycode, void *param)  // para controlar mouse
{
    t_setup *vars = (t_setup *)param;
    (void)vars;
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
