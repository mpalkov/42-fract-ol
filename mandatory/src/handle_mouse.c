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

void	mouse_handler(int evnt, int x, int y, void *params)
{
	t_env	*env;
	
	env = params;
	env->mouse_x = x;
	env->mouse_y = y;
	ft_printf("mouse x: %d\nmouse y: %d\nevent: %d\n", x, y, evnt);
	return ;
}

void	kb_handler(int keycode, void *params)
{
	t_env	*env;

	env = params;
	ft_printf("key pressed: %d\n", keycode);
	return ;
}
