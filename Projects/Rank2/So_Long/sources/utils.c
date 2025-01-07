#include "../include/so_long.h"
#include "../mlx_linux/mlx.h"
#include "../Mylib/libft.h"

void    close_game(t_game *game, char *text)
{
    if(game->map)
        ft_clear(game);
    if(text)
        ft_printf("%s\n", text);
    exit (0);
}

void ft_clear(t_game *game)
{
    int i;

    if(!game || !game->map)
        return ;
    i = 0;
    while(i++ < game->map_height)
    {
        free(game->map[i]);
        free(game->map_temp[i]);
    }
    free(game->map);
    free(game->map_temp);
    /*ft_delete(game);   // falta fazer (vai apagar tudo (player, exit, collectible etc)) */
    game->map = NULL;
    game->map_temp = NULL;
}
