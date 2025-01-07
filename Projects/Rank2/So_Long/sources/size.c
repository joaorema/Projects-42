#include "../include/so_long.h"
#include "../mlx_linux/mlx.h"
#include "../Mylib/libft.h"

void c_map_height(t_game *game, char *text)  // verifica a extensao do file , nr de linhas e incrementa o map_height para o tamanho correto
{
    int fd;
    char *line;

    game->map_height = 0;
    fd = open(text, O_RDONLY);
    if(fd < 0 || strcmp(text + (ft_strlen(text) - 4), ".ber") != 0)
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

void c_map_width(t_game *game, char *text)  // calcula o tamanho da primeira linha e verifica se todas tem o mesmo tamanho
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
