
#include "mlx.h"

typedef struct  s_data
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}

void    my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
    char    *dst;

    dst = 
    return ;
}

void    ft_square(int width, int height, int color, t_img *img)
{
	while ( x < 110)
	{
		while (y < 110)
			my_mlx_pixel_put(img, x, y++, 0x00FFFFFF);
		y = 10;
		++x;
	}

    return ;
}