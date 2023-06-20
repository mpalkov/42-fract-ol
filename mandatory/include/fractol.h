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
# include "../libft/libft.h"
# include <stdio.h> // PRINTF

// GENERAL VALUES DEFINITIONS
	// mlx window width
# define WIN_W 800
	// mlx window height
# define WIN_H 800
	// mlx window title
# define WIN_NAME "fractol_42"
	// min/max fractal axis values
# define MIN_RN (double)-0.3
# define MAX_RN (double)0.5
# define MIN_IN (double)0
# define MAX_IN (double)(MIN_IN + (MAX_RN - MIN_RN) * WIN_H / WIN_W)
	// max iterations default value;
# define MAXITER 50
	//iterstep == 256 / maxiter, aprox. has to be integer and less so it will not overflow.
	
# define DEFCOLOR 0x00FF0000

# define BANNER "\
 ______              _    _      _ \n\
|  ____|            | |  ( )    | |\n\
| |__ _ __ __ _  ___| |_ |/ ___ | |\n\
|  __| '__/ _` |/ __| __|  / _ \\| |\n\
| |  | | | (_| | (__| |_  | (_) | |\n\
|_|  |_|  \\__,_|\\___|\\__|  \\___/|_|\n\
                      [By: mpalkov]\n\n"
# define NOARGSMSG "\
 ____________________________________________________ \n\
|     This program requires an argument on input.    |\n\
|    Write one of these options as prog. argument:   |\n\
|____________________________________________________|\n\
|                  1   or   Mandelbrot               |\n\
|                  2   or   Julia                    |\n\
|                  3   or   BurningShip              |\n\
|____________________________________________________|\n\n"
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
};

enum fractls
{
	MANDELBROT = 1,
	JULIA,
	BURNINGSHIP
};

typedef struct	s_img
{
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_bytes; //in bytes (int = 4 bytes)
	int		endian;
}				t_img;

typedef struct	s_cnum
{
	double	re;
	double	im;
}				t_cnum;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	t_img	*img;
	int		errno;
	int		fr_type;
	int		param;
	double	zoom;
	int		mouse_x;
	int		mouse_y;
	int		maxiter;
	int		color;
	double	rn_factor;
	double	in_factor;
	double	rn;
	double	in;
	double	iterstep;
}				t_env;

# define KB_TAB 48
# define KB_ESC 53
# define KB_W 13
# define KB_A 0
# define KB_S 1
# define KB_D 2
# define KB_UP 126
# define KB_DN 125
# define KB_RIGHT 124
# define KB_LEFT 123
# define KB_SPACE 49
# define KB_MINUS 78
# define KB_PLUS 69
# define KB_R 15
# define KB_G 5
# define KB_B 11
# define KB_Z 6
# define KB_X 7

# define BTN_X 17

# define M_WHEELUP 5
# define M_WHEELDN 4
# define M_LCLICK 1
# define M_RCLICK 2

void	ft_exit(int err, t_env *env);
int		ft_x_close(t_env *env);
int		mouse_handler(int evnt, int x, int y, void *params);
int		kb_handler(int keycode, void *params);

#endif

/*
 ______              _   _       _ 
|  ____|            | | ( )     | |
| |__ _ __ __ _  ___| |_|/  ___ | |
|  __| '__/ _` |/ __| __|  / _ \| |
| |  | | | (_| | (__| |_  | (_) | |
|_|  |_|  \__,_|\___|\__|  \___/|_|
By: mpalkov@student.42barcelona.com


	write(1, " ____________________________________________________ \n", 55);
	write(1, "|     This program requires an argument on input.    |\n", 55);
	write(1, "|    Write one of these options as prog. argument:   |\n", 55);
	          |____________________________________________________|\n"
	write(1, "|                  1   or   Mandelbrot               |\n", 55);
	write(1, "|                  2   or   Julia                    |\n", 55);
	write(1, "|                  3   or   BurningShip              |\n", 55);
	write(1, "|____________________________________________________|\n", 55);
*/	

# define KB_TAB 48
# define KB_ESC 53
# define KB_W 13
# define KB_A 0
# define KB_S 1
# define KB_D 2
# define KB_UP 126
# define KB_DN 125
# define KB_RIGHT 124
# define KB_LEFT 123
# define KB_SPACE 49
# define KB_MINUS 78
# define KB_PLUS 69
# define KB_R 15
# define KB_G 5
# define KB_B 11
# define KB_Z 6
# define KB_X 7

# define M_WHEELUP 5
# define M_WHEELDN 4
# define M_LCLICK 1
# define M_RCLICK 2
                                    
