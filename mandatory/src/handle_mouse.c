/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:39:09 by mpalkov           #+#    #+#             */
/*   Updated: 2023/06/16 16:39:41 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_handler(int event, int x, int y, void *params)
{
	t_env	*env;

	env = params;
	env->mouse_x = x;
	env->mouse_y = y;

	double	rn = 0;
	double	in = 0;
	if (event == M_WHEELDN)
	{
		// ft_zoom()
		printf("rn_min: %f\nrn_max: %f\nin_min: %f\nin_max: %f\n---\n", env->rn_min, env->rn_max, env->in_min, env->in_max);
		env->rn_min += (((env->rn_max - env->rn_min) / ZOOM_STEP) - (env->rn_max - env->rn_min)) * ((double)x / WIN_W);
		env->rn_max -= (((env->rn_max - env->rn_min) / ZOOM_STEP) - (env->rn_max - env->rn_min)) * (1 - (double)x / WIN_W);
		env->in_min += (((env->in_max - env->in_min) / ZOOM_STEP) - (env->in_max - env->in_min)) * ((double)y / WIN_H);
		env->in_max -= (((env->in_max - env->in_min) / ZOOM_STEP) - (env->in_max - env->in_min)) * (1 - (double)x / WIN_H);
		printf("event: %d\nrn min = %f\nrn max = %f\nin min = %f\nin max = %f\n\n", env->rn_min, env->rn_max, env->in_min, env->in_max, event);
		printf("x = %d y = %d\nx/win_w = %f\n1-x/win_w = %f\n\n", x, y, (double)x/WIN_W, 1 - (double)x/WIN_W);
		// mlx_hook(env.win, M_WHEELDN, 0, mouse_handler, &env) - x / WIN_W);
		// printf("event: %d X: %d Y: %d\n\n", event, x, y);
		ft_fractal(env);
	
	}
	else if (event == M_WHEELUP)
	{
		// ft_zoom()
	//	printf("rn_min: %f\nrn_max: %f\nin_min: %f\nin_max: %f\n---\n", env->rn_min, env->rn_max, env->in_min, env->in_max);
		env->rn_min += (((env->rn_max - env->rn_min) * ZOOM_STEP) - (env->rn_max - env->rn_min)) * (1 - (double)x / WIN_W);
		env->rn_max -= (((env->rn_max - env->rn_min) * ZOOM_STEP) - (env->rn_max - env->rn_min)) * ((double)x / WIN_W);
		env->in_min += (((env->in_max - env->in_min) * ZOOM_STEP) - (env->in_max - env->in_min)) * (1 - (double)y / WIN_H);
		env->in_max -= (((env->in_max - env->in_min) * ZOOM_STEP) - (env->in_max - env->in_min)) * ((double)x / WIN_H);
		//printf("event: %d\nrn min = %f\nrn max = %f\nin min = %f\nin max = %f\n\n", env->rn_min, env->rn_max, env->in_min, env->in_max, event);
	//	printf("x = %d y = %d\nx/win_w = %f\n1-x/win_w = %f\n\n", x, y, (double)x/WIN_W, 1 - (double)x/WIN_W);
		// mlx_hook(env.win, M_WHEELDN, 0, mouse_handler, &env) - x / WIN_W);
		// printf("event: %d X: %d Y: %d\n\n", event, x, y);
		ft_fractal(env);
	
	}


	//rn = MIN_RN + y * env->rn_factor;
	//in = MIN_IN + y * env->in_factor;
	// printf("mouse x: %d\nmouse y: %d\nevent: %d\nRN = %f\n\nIN = %f\n\n", x, y, evnt, rn, in);
	// printf ("rn factor: %f\nin factor: %f\n\n", env->rn_factor, env->in_factor);
	return (0);
}

void	ft_move(int keycode, t_env *env)
{
	if (keycode == KB_RIGHT || keycode == KB_D)
	{
		env->rn_min -= MOVE_STEP * env->rn_factor;
		env->rn_max -= MOVE_STEP * env->rn_factor;
	}
	else if (keycode == KB_LEFT || keycode == KB_A)
	{
		env->rn_min += MOVE_STEP * env->rn_factor;
		env->rn_max += MOVE_STEP * env->rn_factor;
	}
	else if (keycode == KB_UP || keycode == KB_W)
	{
		env->in_min += MOVE_STEP * env->in_factor;
		env->in_max += MOVE_STEP * env->in_factor;
	}
	else if (keycode == KB_DN || keycode == KB_S)
	{
		env->in_min -= MOVE_STEP * env->in_factor;
		env->in_max -= MOVE_STEP * env->in_factor;
	}
	ft_fractal(env);
	return ;
}

int	kb_handler(int keycode, void *params)
{
	t_env	*env;

	env = params;
	if (keycode == KB_ESC)
		ft_x_close(params);
	else if (keycode == KB_UP || keycode == KB_W)
		ft_move(keycode, env);
	else if (keycode == KB_DN || keycode == KB_S)
		ft_move(keycode, env);
	else if (keycode == KB_LEFT || keycode == KB_A)
		ft_move(keycode, env);
	else if (keycode == KB_RIGHT || keycode == KB_D)
		ft_move(keycode, env);
	ft_printf("key pressed: %d\n", keycode);
	return (0);
}
