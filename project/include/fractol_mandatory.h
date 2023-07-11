/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mandatory.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:03:25 by mpalkov           #+#    #+#             */
/*   Updated: 2023/05/29 20:03:29 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_MANDATORY_H
# define FRACTOL_MANDATORY_H

# define NOARGSMSG "\
 ____________________________________________________ \n\
|     This program requires an argument on input.    |\n\
|    Write one of these options as prog. argument:   |\n\
|____________________________________________________|\n\
|                1   or   mandelbrot                 |\n\
|                2   or   julia                      |\n\
|____________________________________________________|\n\n"

enum e_fractals
{
	MANDELBROT = 1,
	JULIA,
};

#endif
