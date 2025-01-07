#include "../include/so_long.h"
#include "../mlx_linux/mlx.h"
#include "../Mylib/libft.h"

void load_map(t_game *game, char *file)
{
    int fd;
    char *temp;
    int i;

    c_map_height(game, file);        
    fd = open(file, O_RDONLY);
    game->map = ft_calloc(game->map_height + 1, sizeof(char *));
    game->map_temp = ft_calloc(game->map_height + 1, sizeof(char *));
    if(!game->map || !game->map_temp)
        close_game(game, "Memory allocation failed!");
    i = -1;
    while(++i < game->map_height)
    {
        game->map[i] = get_next_line(fd);
        game->map_temp[i] = ft_strdup(game->map[i]);
    }
    temp = get_next_line(fd);
    free(temp);
    game->map[i] = NULL;
    game->map_temp[i] = NULL;
    close(fd);
    game->map_witdh = ft_strlen(game->map[0]) - 1;
}
