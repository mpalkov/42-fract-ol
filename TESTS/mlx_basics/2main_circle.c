#include <stdio.h>
#include <math.h>
#include "mlx.h"

typedef struct  s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;	

void	ft_mlx_pxput(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (img->bits_per_pixel != 32)
		color = mlx_get_color_value(mlx, color);

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return ;
}

void    ft_draw_rectangle(t_img *img, int width, int height, int color)
{
	int	x;
	int	y;

	x = 0;
	y = 0;

	while (x < width)
	{
		while (y < height)
			ft_mlx_pxput(img, x++, y, color);
		}
	return ;
}


int main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "fract-ol");
	img.img = mlx_new_image(mlx, 100, 100);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);    

	
	return (0);
}

int main ()
{
    int i = 0;
    int j = 0;
    int r = 10;
    int x = 10;
    int y = 10;
    int d;
    int a;
    
    while (i < 24)
    {
        while ( j < 25)
        {
            a = ((i - x) * (i - x)) + ((j - y) * (j - y));
            d = sqrt(a);
            if (r > d)
                printf("*");
            else
                printf(" ");
            ++j;
        }
        printf("\n");
        j = 0;
        ++i;
    }
    return 0;
}

/*
int main ()
{
    int i = 0;
    int j = 0;
    int r = 10;
    int x = 10;
    int y = 10;
    int d;
    int a;
    
    while (i < 24)
    {
        while ( j < 25)
        {
            a = ((i - x) * (i - x)) + ((j - y) * (j - y));
            d = sqrt(a);
            if (r > d)
                printf("*");
            else
                printf(" ");
            ++j;
        }
        printf("\n");
        j = 0;
        ++i;
    }
    return 0;
}
*/