/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:39:09 by mpalkov           #+#    #+#             */
/*   Updated: 2023/06/16 16:39:41 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_mandatory.h"

void	ft_zoom(int keycode, double x_part, double y_part, t_env *env)
{
	double	x_len;
	double	y_len;

	x_len = env->rn_max - env->rn_min;
	y_len = env->in_max - env->in_min;
	if (keycode == M_WHEELDN)
	{
		env->rn_min -= ((x_len / ZOOM_STEP) - x_len) * x_part;
		env->rn_max += ((x_len / ZOOM_STEP) - x_len) * (1 - x_part);
		env->in_min -= ((y_len / ZOOM_STEP) - y_len) * y_part;
		env->in_max += ((y_len / ZOOM_STEP) - y_len) * (1 - y_part);
	}
	else if (keycode == M_WHEELUP)
	{
		env->rn_min -= ((x_len * ZOOM_STEP) - x_len) * x_part;
		env->rn_max += ((x_len * ZOOM_STEP) - x_len) * (1 - x_part);
		env->in_min -= ((y_len * ZOOM_STEP) - y_len) * y_part;
		env->in_max += ((y_len * ZOOM_STEP) - y_len) * (1 - y_part);
	}
	return ;
}

// For julia: x = <-3, 3>; y = <-3, 3> -> len = 6
//		printf("rnc: %f\ninc: %f\n", env->julia_rn_c, env->julia_in_c);
int	mouse_handler(int keycode, int x, int y, void *params)
{
	t_env	*env;

	env = params;
	if (keycode == M_LCLICK && env->fr_type == JULIA)
	{
		env->julia_rn_c = -3 + 6 * (double)x / WIN_W;
		env->julia_in_c = -3 + 6 * (double)y / WIN_H;
	}
	else if (keycode == M_WHEELDN || keycode == M_WHEELUP)
		ft_zoom(keycode, (double)0.5, (double)0.5, env);
	ft_render(env);
	return (0);
}

//		ft_printf("key pressed: %d\n", keycode);
int	kb_handler(int keycode, void *params)
{
	t_env	*env;

	env = params;
	if (keycode == KB_ESC)
		ft_x_close(params);
	ft_render(env);
	return (0);
}
