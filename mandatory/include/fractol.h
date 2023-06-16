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

// GENERAL VALUES DEFINITIONS
	// mlx window width
# define WIN_W 800
	// mlx window height
# define WIN_H 800
	// mlx window title
# define DEFMAXITER 25
	// max iterations default value;
# define DEFCOLOR 0x00F000
# define WIN_NAME "fractol_42"
# define BANNER "\
 ______              _   _       _ \n\
|  ____|            | | ( )     | |\n\
| |__ _ __ __ _  ___| |_|/  ___ | |\n\
|  __| '__/ _` |/ __| __|  / _ \\| |\n\
| |  | | | (_| | (__| |_  | (_) | |\n\
|_|  |_|  \\__,_|\\___|\\__|  \\___/|_|\n\
                      [By: mpalkov]\n\n"
# define NOARGSMSG "\
 ____________________________________________________ \n\
|     This program requires an argument on input.    |\n\
|         Write one of the following options:        |\n\
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
	char	*addr;
	int		bits_per_pixel;
	int		line_length; //in bytes (int = 4 bytes)
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
}				t_env;

void	ft_exit(int err, t_env *env);
void	mouse_handler(int evnt, int x, int y, void *params);
void	kb_handler(int keycode, void *params);

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
	write(1, "|___________   _Write one of the options:__ _________|\n", 55);
	          |____________________________________________________|\n"
	write(1, "|                  1   or   Mandelbrot               |\n", 55);
	write(1, "|                  2   or   Julia                    |\n", 55);
	write(1, "|                  3   or   BurningShip              |\n", 55);
	write(1, "|____________________________________________________|\n", 55);
*/	

/*
KB_TAB 48
KB_ESC 53
KB_W 13
KB_A 0
KB_S 1
KB_D 2
KB_UP 126
KB_DN 125
KB_RIGHT 124
KB_LEFT 123
KB_SPACE 49
KB_MINUS 78
KB_PLUS 69
KB_R 15
KB_G 5
KB_B 11
KB_Z 6
KB_X 7

M_WHEELUP 5
M_WHEELDN 4
M_LCLICK 1
M_RCLICK 2

*/
                                    