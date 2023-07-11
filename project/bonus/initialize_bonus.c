/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:22:31 by mpalkov           #+#    #+#             */
/*   Updated: 2023/07/05 14:22:34 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_bonus.h"

int	ft_set_f_type(char *str, t_env *env)
{
	int	i;

	i = 0;
	if (ft_strcmp(str, "mandelbrot") == 0 || ft_strcmp(str, "1") == 0)
		env->fr_type = MANDELBROT;
	else if (ft_strcmp(str, "julia") == 0 || ft_strcmp(str, "2") == 0)
		env->fr_type = JULIA;
	else if (ft_strcmp(str, "burningship") == 0 || ft_strcmp(str, "3") == 0)
		env->fr_type = BURNINGSHIP;
	else
		return (0);
	return (1);
}

void	ft_envzero(t_env *env)
{
	env->errno = 0;
	env->mlx = NULL;
	env->win = NULL;
	env->img->img = NULL;
	env->img->address = NULL;
	env->fr_type = 0;
	env->param = 0;
	env->zoom = 0;
	env->maxiter = 0;
	env->color = 0;
	env->rn_factor = 0;
	env->in_factor = 0;
	return ;
}

void	ft_argscheck(int ac, char **av, t_env *env)
{
	if (ac != 2 || ft_set_f_type(av[1], env) == 0)
		ft_exit(NOARGS, env);
	return ;
}

// MLX LEAKS - mlx_init(); causes this leak:
// 		1 (48 bytes) ROOT LEAK: <CFString 0x7f8c61725fb0> [48]  length: 26
//		"Copyright Apple Inc., 2019"
void	ft_envinit(t_env *env, t_img *im, int argc, char **argv)
{
	if (!env || !im)
		ft_exit(INITERR, env);
	env->img = im;
	ft_envzero(env);
	ft_argscheck(argc, argv, env);
	env->maxiter = MAXITER;
	env->color = DEFCOLOR;
	env->rn_min = MIN_RN;
	env->rn_max = MAX_RN;
	env->in_min = MIN_IN;
	env->in_max = env->in_min + (env->rn_max - env->rn_min) * (WIN_H / WIN_W);
	env->julia_rn_c = JULIA_RN;
	env->julia_in_c = JULIA_IN;
	env->mlx = mlx_init();
	env->iterstep = 255 / MAXITER;
	if (env->mlx == NULL)
		ft_exit(MLXERR, env);
	env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, WIN_NAME);
	im->img = mlx_new_image(env->mlx, WIN_W, WIN_H);
	if (env->win == NULL || env->img == NULL)
		ft_exit(MLXERR, env);
	im->address = mlx_get_data_addr(im->img, &im->bits_per_pixel, \
		&im->line_bytes, &im->endian);
	return ;
}
