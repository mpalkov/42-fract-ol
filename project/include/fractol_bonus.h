/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:03:25 by mpalkov           #+#    #+#             */
/*   Updated: 2023/05/29 20:03:29 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# define MOVE_STEP (double)80

# define NOARGSMSG "\
 ____________________________________________________ \n\
|     This program requires an argument on input.    |\n\
|    Write one of these options as prog. argument:   |\n\
|____________________________________________________|\n\
|                1   or   mandelbrot                 |\n\
|                2   or   julia                      |\n\
|                3   or   burningship                |\n\
|____________________________________________________|\n\n"

enum e_fractls
{
	MANDELBROT = 1,
	JULIA,
	BURNINGSHIP
};

void	ft_burningship(t_env *env);

#endif
