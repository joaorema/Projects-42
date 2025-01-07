#include "../include/so_long.h"
#include "../mlx_linux/mlx.h"
#include "../Mylib/libft.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)  // printa um pixel na tela
{
    char    *dest;

    dest = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dest = color;
}
