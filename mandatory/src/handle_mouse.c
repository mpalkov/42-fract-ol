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

/*For julia: x = <-3, 3>; y = <-3, 3> -> len = 6 */
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
		ft_zoom(keycode, (double)x / WIN_W, (double)y / WIN_H, env);
	ft_render(env);
	return (0);
}

void	ft_move(int keycode, t_env *env)
{
	if (keycode == KB_RIGHT || keycode == KB_D)
	{
		env->rn_min += MOVE_STEP * env->rn_factor;
		env->rn_max += MOVE_STEP * env->rn_factor;
	}
	else if (keycode == KB_LEFT || keycode == KB_A)
	{
		env->rn_min -= MOVE_STEP * env->rn_factor;
		env->rn_max -= MOVE_STEP * env->rn_factor;
		
	}
	else if (keycode == KB_UP || keycode == KB_W)
	{
		env->in_min -= MOVE_STEP * env->in_factor;
		env->in_max -= MOVE_STEP * env->in_factor;
	}
	else if (keycode == KB_DN || keycode == KB_S)
	{
		env->in_min += MOVE_STEP * env->in_factor;
		env->in_max += MOVE_STEP * env->in_factor;
	}
	ft_render(env);
	return ;
}

int	ft_rgb2int(int r, int g, int b)
{
	if (r > 255)
		r = 255;
	else if (r < 0)
		r = 0;
	if (g > 255)
		g = 255;
	else if (g < 0)
		g = 0;
	if (b > 255)
		b = 255;
	else if (b < 0)
		b = 0;
	return (r << 16 | g << 8 | b);
}

void	ft_colorshift(int keycode, t_env *env)
{
	int color = env->color;
	
	int	r = (UCHR)(color >> 16);
	int	g = (UCHR)(color >> 8);
	int	b = (UCHR)color;

	if (keycode == KB_NUM9) // rgB+
		env->color = ft_rgb2int(r, g, b + COLOR_STEP);
	else if (keycode == KB_NUM6) // rgB-
		env->color = ft_rgb2int(r, g, b - COLOR_STEP);
	else if (keycode == KB_NUM8) // rGb+
		env->color = ft_rgb2int(r, g + COLOR_STEP, b);
	else if (keycode == KB_NUM5) // rGb-
		env->color = ft_rgb2int(r, g - COLOR_STEP, b);
	else if (keycode == KB_NUM7) // Rgb+
		env->color = ft_rgb2int(r + COLOR_STEP, g, b);
	else if (keycode == KB_NUM4) // Rgb-
		env->color = ft_rgb2int(r - COLOR_STEP, g, b);
	
	ft_printf("env->color: %x\n", env->color);
	return ;
}

int	kb_handler(int keycode, void *params)
{
	t_env	*env;

	env = params;
	if (keycode == KB_ESC)
		ft_x_close(params);
	else if (keycode == KB_UP || keycode == KB_W || keycode == KB_DN \
		|| keycode == KB_S || keycode == KB_LEFT || keycode == KB_A \
		|| keycode == KB_RIGHT || keycode == KB_D)
		ft_move(keycode, env);
	else if (keycode >= KB_NUM0 && keycode <= KB_NUM9)
		ft_colorshift(keycode, env);
	ft_render(env);
	ft_printf("key pressed: %d\n", keycode);
	return (0);
}
