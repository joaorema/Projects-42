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

int close_game_clean(t_game *game)
{
    if(game->map)
    {
        ft_clear(game);
    }
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

t_game start_game(t_game *game)
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
    game->collect_image = NULL;
    game->exit_close_image = NULL;
    game->exit_open_image = NULL;
    return (*game);
}
