#include "so_long.h"
#include "mlx_linux/mlx.h"
#include "Mylib/libft.h"
#include <unistd.h>

void c_map_height(t_game *game, char text)  // verifica a extensao do file , nr de linhas e incrementa o map_height para o tamanho correto
{
    int fd;
    char *line;

    game->map_height = 0;
    fd = open(text, O_RDONLY);
    if(fd < 0 || ft_strcmp(text + (ft_strlen(text) - 4), ".ber") != 0)
    {
        close_game(game,"Error, file not valid");
    }
    line = get_next_line(fd);
    if(!line)
        close_game(game,"Error, file not valid");  
    while(line != NULL)
    {
        free(line);
        line = get_next_line(fd);
        game->map_height++;
    }
    close(fd);
}

int c_map_width(t_game *game, char text)  // calcula o tamanho da primeira linha e verifica se todas tem o mesmo tamanho
{
    int fd;
    int counter;
    char *line;
    int first;

    game->map_witdh = 0;
    fd = open(text, O_RDONLY);
    line = get_next_line(fd);
    counter = ft_strlen(line);
    first = counter;
    if(!line)
        close_game(game,"Error, file not valid");  
    counter = ft_strlen(line);
    first = counter;
    while(line != NULL && first == counter)
    {   
        free(line);
        line = get_next_line(fd);
        if(!line)
            close_game(game,"Error, file not valid");  
        counter = ft_strlen(line);
    }
    game->map_witdh = first;
}

int check_form(t_game *game)
{
    int i;
    int size;

    if(!game->map || game->map_height == 0)
        return 0;
    i = 0;
    size = ft_strlen(game->map[0]);  //calcula o tamanho da primeira linha
    while(i < game->map_height)
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
        if(game->map[i][0] != 1 || game->map[i][game->map_witdh - 1] != '1')
            close_game(game,"Error, map is file not valid");
        i++;
    }
}

    void check_letter(t_game *game, int x, int y)
    {
        if(game->map[y][x] == 'P')  // encontra p , incrementa o player e define a posicao dele na grid
        {
            game->player++;
            game->player_x = x;
            game->player_y - y;
        }
        else if(game->map[y][x] == 'E')  // encontra a saida e incrementa
            game->exit++;
        else if(game->map[y][x] == 'C')  // encontra collectible e incrementa 
            game->collect++;
        else if (game->map[y][x] != 'C' && game->map[y][x] != 'E'   
                && game->map[y][x] != 'P' && game->map[y][x] != "1"
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
        if(check_form == 0)
        {
            

        }
    }