/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:01:56 by mpalkov           #+#    #+#             */
/*   Updated: 2023/05/29 20:03:06 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mlx_pixput(t_env *env)
{
	int	pixel;

	pixel = 0;
	if (env->img->bits_per_pixel != 32)
		color = mlx_get_color_value(env->mlx, color);

	if (env->img->endian == 1)
	{
		
	}
	return (1);
}

void	ft_envzero(t_env *env)
{
	env->errno = 0;
	env->mlx = NULL;
	env->win = NULL;
	env->img->img = NULL;
	env->img->addr = NULL;
	env->fr_type = 0;
	env->param = 0;
	env->zoom = 0;
	return ;
}

int	ft_set_f_type(char *str, t_env *env)
{
	int	i;

	i = 0;
	if (ft_strcmp(str, "mandelbrot") == 0 || ft_strcmp(str, "1") == 0)
		env->fr_type = MANDELBROT;
	else if (ft_strcmp(str, "julia") == 0 || ft_strcmp(str, "2") == 0)
		env->fr_type = JULIA;
	else
		return (0);
	return (1);
}

void	ft_argscheck(int ac, char **av, t_env *env)
{
	if (ac != 2 || ft_set_f_type(av[1], env) == 0)
		ft_exit(NOARGS, env);
	
	return ;
}

void	ft_envinit(t_env *env, t_img *im, int argc, char **argv)
{
	if (!env || !im)
		ft_exit(INITERR, env);
	
	env->img = im;
	ft_envzero(env);
	env->mlx = mlx_init();
	if (env->mlx == NULL)
		ft_exit(MLXERR, env);
	env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, WIN_NAME);
	im->img = mlx_new_image(env->mlx, WIN_W, WIN_H);
	if (env->win == NULL || env->img == NULL)
		ft_exit(MLXERR, env);
	im->addr = mlx_get_data_addr(im->img, &im->bits_per_pixel, &im->line_length, &im->endian);

	return ;
}

void	

int	main(int argc, char **argv)
{
	t_env	env;
	t_img	image;

	ft_envinit(&env, &image, argc, argv);


	return (0);
}
