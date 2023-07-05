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

void	ft_render(t_env *env)
{
	if (env->fr_type == MANDELBROT)
		ft_mandelbrot(env);
	else if (env->fr_type == JULIA)
		ft_julia(env);
	else if (env->fr_type == BURNINGSHIP)
		ft_burningship(env);
	return ;
}

int	main(int argc, char **argv)
{
	t_env	env;
	t_img	img;

	if (ft_putstr(BANNER) == -1)
		ft_exit(WRITEERR, &env);
	ft_envinit(&env, &img, argc, argv);
	ft_render(&env);
	mlx_hook(env.win, BTN_X, 0, ft_x_close, &env);
	mlx_key_hook(env.win, kb_handler, &env);
	mlx_mouse_hook(env.win, mouse_handler, &env);
	mlx_loop(env.mlx);
	return (0);
}
