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

/*
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
*/

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
	env->maxiter = 0;
	env->color = 0;
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
	ft_argscheck(argc, argv, env);
	env->maxiter = DEFMAXITER;
	env->color = DEFCOLOR;
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
/*
int	ft_itrcalc()
{
	double	rn;
	double	in;

	// calculate fractal axis based on img's pixel position
	rn = 2 / ((WIN_W / 2) / ((double)x - WIN_W / 2));
	in = -2 / ((WIN_H / 2) / ((double)y - WIN_H / 2));


	return ();
}

void	ft_fractal(t_env *env)
{
	int		x;
	int		y;
	// double	rn;
	// double	in;
	int		itr;

	itr = 0;
	y = 0;
	while (y <= WIN_H)
	{
		x = 0;
		while (x <= WIN_W)
		{
			// rn = 2 / ((WIN_W / 2) / ((double)x - WIN_W / 2));
			// in = -2 / ((WIN_H / 2) / ((double)y - WIN_H / 2));
			itr = ft_itrcalc()
			++x;
		}
		++y;
	}

	return ;
}
*/
int	main(int argc, char **argv)
{
	t_env	env;
	t_img	img;

	if (ft_putstr(BANNER) == -1)
		ft_exit(WRITEERR, &env);	
	
	ft_envinit(&env, &img, argc, argv);
	
	// ft_fractalinit(&env);

	mlx_hook(env.win, BTN_X, 0, ft_x_close, &env);
	mlx_key_hook(env.win, kb_handler, &env);
	mlx_mouse_hook(env.win, mouse_handler, &env);
	mlx_loop(env.mlx);
//	ft_exit(OK, &env);
	return (0);
}
