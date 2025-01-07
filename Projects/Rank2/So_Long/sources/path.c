#include "../include/so_long.h"
#include "../mlx_linux/mlx.h"
#include "../Mylib/libft.h"

int valid_position(t_game *game, int x, int y)
{
    return(x >= 0 && y >= 0 && x < game->map_witdh && y < game->map_height       //verificamos se comeca numa possicao valida
            && game->map_temp[y][x] != 'F' && game->map_temp[y][x] != '1');        //Usamos F(found) para marcar as posicoes ja visitadas , 1 = parede.
}

void check_tile(t_game *game, t_position pos, t_position *stack, int *top)
{
    if(game->map_temp[pos.y][pos.x] == 'C')                         
        game->check_collect++;
    if(game->map_temp[pos.y][pos.x] == 'E')
        game->path = 1;
    if(game->map_temp [pos.y][pos.x] == 'E'
        && game->check_collect != game->collect)
        {
            game->map_temp[pos.y][pos.x] = 'F';
            return;
        }
    game->map_temp[pos.y][pos.x] = 'F' ;
    if(*top + 4 >= game->map_witdh * game->map_height)
    {
        free(stack);
        close_game(game, "Error , stack overflow!");
    }   
    stack[++(*top)] = (t_position){pos.x + 1, pos.y};
    stack[++(*top)] = (t_position){pos.x - 1, pos.y};
    stack[++(*top)] = (t_position){pos.x, pos.y + 1};
    stack[++(*top)] = (t_position){pos.x, pos.y - 1};
}  

void flood_fill_check(t_game *game)
{
    t_position *stack;
    t_position pos;
    int top;

    top = -1;
    stack = ft_calloc((game->map_height * game->map_witdh), sizeof(t_position));
    if(!stack)
        close_game(game, "Error: memory allocation failed");
    game->check_collect = 0;
    game->path = 0;
    stack[++top] = (t_position){game->player_x, game->player_y};  // stack = a primeira posicao do player ++ para iterar pelo mapa
    while(top >= 0)   // enquanto existir lugares nao visitados 
    {
        pos = stack[top--];    //pos fica a ser a primeira posicao do player --para retirar essa posicao da stack
        if(valid_position(game, pos.x, pos.y) == 0) // posicao valida fazemos check_tile e retepimos o processo
            continue;   
        check_tile(game, pos, stack, &top);
    }
    free(stack);
    if(game->check_collect != game->collect || game->path != 1)
        close_game(game , "Error , no possible path!");
}
