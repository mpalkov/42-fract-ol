/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpalkov <mpalkov@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:03:25 by mpalkov           #+#    #+#             */
/*   Updated: 2023/05/29 20:03:29 by mpalkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "./libft/libft.h"

// GENERAL VALUES DEFINITIONS
	// mlx window width
# define WIN_W 800
	// mlx window height
# define WIN_H 800
	// mlx window title
# define WIN_NAME "fractol_42"
# define NOARGSMSG "This program requires arguments on input.\n\n \
execution: ./fractol <fractalname> <otherargs>\n\n \
<fractalname>:\n \
mandelbrot\n \
julia\n"
# define WRITEMSG "writing error."
# define MALLOCMSG "malloc error."
# define MLXMSG "mlx error."
# define INITMSG "initialization error."

enum errs
{
	OK,
	NOARGS,
	INPUTERR,
	WRITEERR,
	MALLOCERR,
	MLXERR,
	INITERR
}

enum fractls
{
	MANDELBROT,
	JULIA,
	BURNINGSHIP
}

typedef;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length; //in bytes (int = 4 bytes)
	int		endian;
}				t_img;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	t_img	*img;
	int		errno;
	int		fr_type;
	int		param;
	int		zoom;
	int		mouse_x;
	int		mouse_y;
}				t_env;

void	ft_exit(int err, t_enviro *env);

#endif
