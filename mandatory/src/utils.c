/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:22:46 by mpalkov           #+#    #+#             */
/*   Updated: 2023/07/05 14:22:53 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mlx_putpix(int x, int y, int color, t_env *env)
{
	int		pixel;
	char	*buffer;
	
	buffer = env->img->address;
	pixel = (y * env->img->line_bytes) + (x * 4);
	if (env->img->bits_per_pixel != 32)
		color = mlx_get_color_value(env->mlx, color);
	if (env->img->endian == 1)	// ARGB
	{
		buffer[pixel + 0] = color >> 24;
		buffer[pixel + 1] = color >> 16;
		buffer[pixel + 2] = color >> 8;
		buffer[pixel + 3] = color;
	}
	else if (env->img->endian == 0) // BGRA
	{
		buffer[pixel + 0] = color;
		buffer[pixel + 1] = (color >> 8) & 0xFF;
		buffer[pixel + 2] = (color >> 16) & 0xFF;
		buffer[pixel + 3] = (color >> 24) & 0xFF;
	}
	// printf("x: %d, y: %d, written pixel: %d of %d\n", x, y, pixel, WIN_W * WIN_H);
	return (1);
}

void	ft_mlx_frpix(int x, int y, int itr, t_env *env)
{
	int	color = env->color;
	int	step  = (int)(env->iterstep * (MAXITER - itr));
	int	r = (UCHR)(color >> 16);
	int	g = (UCHR)(color >> 8);
	int	b = (UCHR)color;
	
	if (itr == 0)
		color = 0x00000000;
	else
		// color = (color & step) | (color & step << 8) | (color & step << 16);
		color = ft_rgb2int((r - step), (g - step), (b - step));
		//printf("iters: %d, color: %x\n", itr, 0x00FF0000 & ((itr / MAXITER * 255) << 2));
		
	ft_mlx_putpix(x, y, color, env);
}

int	ft_rgb2int(int r, int g, int b)
{
	if (r > 255)
		r = 255;
	else if (r < 0)
		r = 0;
	if (g > 255)
		g = 255;
	else if (g < 0)
		g = 0;
	if (b > 255)
		b = 255;
	else if (b < 0)
		b = 0;
	return (r << 16 | g << 8 | b);
}
