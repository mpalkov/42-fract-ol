/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_burningship_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:20:59 by mpalkov           #+#    #+#             */
/*   Updated: 2023/07/05 14:21:10 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_bonus.h"

int	ft_burningship_itercalc(t_env *env)
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
		z_im = fabs(2 * z_re * z_im) + env->in;
		z_re = z_re2 - z_im2 + env->rn;
		++i;
	}
	return (0);
}

void	ft_burningship(t_env *env)
{
	int	x;
	int	y;
	int	itr;

	itr = 0;
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
			itr = ft_burningship_itercalc(env);
			ft_mlx_frpix(x, y, itr, env);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
	return ;
}
