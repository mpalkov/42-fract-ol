/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_mandelbrot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:21:42 by mpalkov           #+#    #+#             */
/*   Updated: 2023/07/05 14:21:46 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mandelbrot_itercalc(t_env *env)
{
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;
	int		i;

	i = 0;
	z_re = env->rn;
	z_im = env->in;
	while (i < MAXITER)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if (z_re2 + z_im2 > 4)
			return (i);
		z_im = 2 * z_re * z_im + env->in;
		z_re = z_re2 - z_im2 + env->rn;
		++i;
	}
	return (0);
}

// calculate the real and imaginary nbrs:
// c_re = MinRe + x*(MaxRe-MinRe)/(ImageWidth-1);
// c_im = MaxIm - y*(MaxIm-MinIm)/(ImageHeight-1);
// 	pre-calculate the constants to use less CPU to calculate every loop.
// 	Re_factor = (MaxRe-MinRe)/(ImageWidth-1);
//  	Im_factor = (MaxIm-MinIm)/(ImageHeight-1);
// so the lines will be this:
// c_re = MinRe + x*Re_factor;
// c_im = MaxIm - y*Im_factor;

// Calculating if something is or is not part of the fractal:
// The absolute value of a complex number is defined as its distance
// from the origin, that is, sqrt(Zr2+Zi2).
// Note: The if-statement above would have the following form:
//             if(sqrt(Z_re*Z_re + Z_im*Z_im) > 2)
// However, from mathematics we know that we can simplify that to:
//             if(Z_re*Z_re + Z_im*Z_im > 4)

void	ft_mandelbrot(t_env *env)
{
	int		x;
	int		y;
	int		itr;

	itr = 0;
	y = 0;
	env->rn_factor = (env->rn_max - env->rn_min) / WIN_W;
	env->in_factor = (env->in_max - env->in_min) / WIN_H;
	while (y < WIN_H)
	{
		x = 0;
		env->in = env->in_min + y * env->in_factor;
		while (x < WIN_W)
		{
			env->rn = env->rn_min + x * env->rn_factor;
			itr = ft_mandelbrot_itercalc(env);
			ft_mlx_frpix(x, y, itr, env);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
	return ;
}
