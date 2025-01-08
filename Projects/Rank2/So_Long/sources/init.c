#include "../include/so_long.h"
#include "../mlx_linux/mlx.h"
#include "../Mylib/libft.h"

void load_images(t_game *game)
{
    int img_width;
    int img_height;

    game->moves = 0;
    game->mlx = mlx_init();
    if(!game->mlx)
        close_game(game, "Error, failed to start Mlx");
    game->wall_image = mlx_xpm_file_to_image(game->mlx, "./images/Wall.xpm",
            &img_width, &img_height);
    if(!game->wall_image)
        close_game(game, "falhou wall_image");
    game->player_image =  mlx_xpm_file_to_image(game->mlx, "./images/PlayerRight.xpm",
            &img_width, &img_height);
    if(!game->player_image)
        close_game(game, "falhou player_image");
    game->ground_image =  mlx_xpm_file_to_image(game->mlx, "./images/Floor.xpm",
            &img_width, &img_height);
    if(!game->ground_image)
        close_game(game, "falhou ground image");
    game->collect_image = mlx_xpm_file_to_image(game->mlx, "./images/Collectible.xpm",
            &img_width, &img_height);
    if(!game->collect_image)
        close_game(game, "falhou collect image");
    game->exit_close_image = mlx_xpm_file_to_image(game->mlx, "./images/Closed_exit.xpm",
            &img_width, &img_height);
    if(!game->exit_close_image)
        close_game(game, "falhou exit close");
    game->exit_open_image = mlx_xpm_file_to_image(game->mlx, "./images/Open_exit.xpm",
            &img_width, &img_height);
    if(!game->exit_open_image)
        close_game(game, "falhou exit open");
    /*if(!game->wall_image || !game->player_image || !game->ground_image || !game->collect_image
        || !game->exit_close_image || game->exit_open_image )
        close_game(game, "Error, Failed to load Images"); */
}

void start_window(t_game *game)
{
        game->win = mlx_new_window(game->mlx, game->map_witdh *  TILE_SIZE,
                game->map_height * TILE_SIZE, "so_long");
        if(!game->win)
                close_game(game, "Error: Failed to launch window");
}