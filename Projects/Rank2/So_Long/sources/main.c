#include "../include/so_long.h"
#include "../mlx_linux/mlx.h"
#include "../Mylib/libft.h"

int main(int ac, char *av[])
{
    t_game  game;
    if(ac == 2)
    {
      load_map(&game, av[1]);
      check_map(&game);
      flood_fill_check(&game);  
    }
}

/*
int main()
{
    t_setup vars;
    t_data  img;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1000, 560, "Teste!");
    img.img = mlx_new_image(vars.mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
    my_mlx_pixel_put(&img, 150, 150, 0x00FF0000);
    mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);  
    mlx_key_hook(vars.win, handle_keyboard, &vars);
    mlx_hook(vars.win, 4, 1L<<2, handle_mouse, &vars); 
    mlx_loop(vars.mlx); 
    ft_printf("teste");
	
}
*/


