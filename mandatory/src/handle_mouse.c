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

int	mouse_handler(int evnt, int x, int y, void *params)
{
	t_env	*env;
	double	rn = 0;
	double	in = 0;

	env = params;
	env->mouse_x = x;
	env->mouse_y = y;
	rn = 2 / ((WIN_W / 2) / ((double)x - WIN_W / 2));
	in = -2 / ((WIN_H / 2) / ((double)y - WIN_H / 2));
	printf("mouse x: %d\nmouse y: %d\nevent: %d\nRN = %f\n\nIN = %f\n\n", x, y, evnt, rn, in);
	return (0);
}

int	kb_handler(int keycode, void *params)
{
	t_env	*env;

	env = params;
	if (keycode == KB_ESC)
		ft_x_close(params);
	ft_printf("key pressed: %d\n", keycode);
	return (0);
}
