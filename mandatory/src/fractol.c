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
	int	color = 0x00FF0000;
	
	if (itr == 0)
		color = 0x00000000;
	else
		color = DEFCOLOR & ((int)(env->iterstep * itr) << 16);
		//printf("iters: %d, color: %x\n", itr, 0x00FF0000 & ((itr / MAXITER * 255) << 2));
	ft_mlx_putpix(x, y, color, env);
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

// MLX LEAKS - mlx_init(); causes this leak:
// 		1 (48 bytes) ROOT LEAK: <CFString 0x7f8c61725fb0> [48]  length: 26  "Copyright Apple Inc., 2019"
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
	env->in_max = MAX_IN;
	env->mlx = mlx_init();
	env->iterstep = 256 / MAXITER;
	if (env->mlx == NULL)
		ft_exit(MLXERR, env);
	env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, WIN_NAME);
	im->img = mlx_new_image(env->mlx, WIN_W, WIN_H);
	if (env->win == NULL || env->img == NULL)
		ft_exit(MLXERR, env);
	im->address = mlx_get_data_addr(im->img, &im->bits_per_pixel, &im->line_bytes, &im->endian);

	return ;
}

// int	ft_itercalc(int x, int y, t_env *env)
int	ft_itercalc(t_env *env)
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

void	ft_fractal(t_env *env)
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
			itr = ft_itercalc(env);
			ft_mlx_frpix(x, y, itr, env);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
	return ;
}

int	main(int argc, char **argv)
{
	t_env	env;
	t_img	img;

	if (ft_putstr(BANNER) == -1)
		ft_exit(WRITEERR, &env);	
	
	ft_envinit(&env, &img, argc, argv);
	
	// ft_fractalinit(&env);
	ft_fractal(&env);

	mlx_hook(env.win, BTN_X, 0, ft_x_close, &env);
	mlx_key_hook(env.win, kb_handler, &env);
	// mlx_hook(env.win, M_WHEELDN, 0, mouse_handler, &env); WORKS same way as
	// mlx_mouse_hook
	mlx_mouse_hook(env.win, mouse_handler, &env);
	mlx_loop(env.mlx);
	ft_exit(OK, &env);
	return (0);
}
