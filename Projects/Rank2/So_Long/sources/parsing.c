#include "../include/so_long.h"
#include "../mlx_linux/mlx.h"
#include "../Mylib/libft.h"

int check_form(t_game *game)
{
    int i;
    size_t size;

    if(!game->map || game->map_height == 0)
        return 0;
    i = 0;
    size = ft_strlen(game->map[0]);  //calcula o tamanho da primeira linha
    while(i < game->map_height -1)
    {
        if(ft_strlen(game->map[i]) != size) // verifica se todas as outras linhas tem o mesmo tamanho
        {
            return 0;
        }
        i++;    
    }
    return 1;
}

void check_wall(t_game *game)
{
    int i;

    i = 0;
    while(i < game->map_witdh)
    {
        if(game->map[0][i] != '1' || game->map[game->map_height - 1][i] != '1')
            close_game(game,"Error, map is file not valid");
        i++;
    }
    i = 0;
    while(i < game->map_height)
    {
        if(game->map[i][0] != '1' || game->map[i][game->map_witdh - 1] != '1')
            close_game(game,"Error, map is file not valid");
        i++;
    }
}

    void check_letter(t_game *game, int x, int y)
    {
        if(game->map[y][x] == 'P')  // encontra p , incrementa o player e define a posicao dele na grid
        {
            game->players++;
            game->player_x = x;
            game->player_y = y;
        }
        else if(game->map[y][x] == 'E')  // encontra a saida e incrementa
            game->exit++;
        else if(game->map[y][x] == 'C')  // encontra collectible e incrementa 
            game->collect++;
        else if (game->map[y][x] != 'C' && game->map[y][x] != 'E'   
                && game->map[y][x] != 'P' && game->map[y][x] != '1'
                && game->map[y][x] != '0')
                close_game(game,"Error, map is file not valid");
        
    }

    void check_letters(t_game *game)
    {
        int x; 
        int y;

        x = 0;
        y = 0;
        while(y < game->map_height)
        {
            x = 0;
            while(x < game->map_witdh)
            {
                check_letter(game, x, y);
                x++;
            }
            y++;
        }

    }

    void check_map(t_game *game)
    {
        if(!check_form(game))
            close_game(game, "Error, map is not the correct shape");
        check_wall(game);
        check_letters(game);
        if(game->collect <= 0 || game->exit != 1 || game->players != 1)
            close_game(game, "Error, Map needs to have 1 exit and 1 player and 1 and more collectibles.");
    }
    
