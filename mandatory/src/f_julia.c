/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_julia.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:21:24 by mpalkov           #+#    #+#             */
/*   Updated: 2023/07/05 14:21:28 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// for julia, I use env->rn_factor and in_factor as the constant parts.
int	ft_julia_itercalc(t_env *env)
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
		z_im = 2 * z_re * z_im + env->julia_in_c;
		z_re = z_re2 - z_im2 + env->julia_rn_c;
		++i;
	}
	return (0);
}

void	ft_julia(t_env *env)
{
	int		x;
	int		y;
	double	rn_constant;
	double	in_constant;
	int		itr;

	env->rn_factor = (env->rn_max - env->rn_min) / WIN_W;
	env->in_factor = (env->in_max - env->in_min) / WIN_H;
	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			env->rn = env->rn_min + (double)x * env->rn_factor;
			env->in = env->in_min + (double)y * env->in_factor;
			itr = ft_julia_itercalc(env);
			ft_mlx_frpix(x, y, itr, env);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
	return ;
}
