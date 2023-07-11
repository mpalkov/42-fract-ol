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
# include <stdio.h>
# include <math.h>

// GENERAL VALUES DEFINITIONS
	// mlx window width
# define WIN_W 800
	// mlx window height
# define WIN_H 800
	// mlx window title
# define WIN_NAME "fractol_42"
	// min/max fractal axis values
# define MIN_RN (double)-2
# define MAX_RN (double)1
# define MIN_IN (double)-1.2
// MAX_IN calculated in programm, because of norm conflict putting various
//		values in a single line of define.
// # define MAX_IN (MIN_IN + (MAX_RN - MIN_RN) * WIN_H / WIN_W)
	//set default starting point for Julia
# define JULIA_RN (double)-0.757500
# define JULIA_IN (double)-0.292500
	// max iterations default value;
# define MAXITER 45
	//iterstep = 256 / maxiter | Has to be 8bits (int 0-255) or less
	// so it will not overflow.
# define DEFCOLOR 0x00FF0000
# define ZOOM_STEP (double)1.1
# define COLOR_STEP 25

# define UCHR unsigned char

# define BANNER "\
 ______              _    _      _ \n\
|  ____|            | |  ( )    | |\n\
| |__ _ __ __ _  ___| |_ |/ ___ | |\n\
|  __| '__/ _` |/ __| __|  / _ \\| |\n\
| |  | | | (_| | (__| |_  | (_) | |\n\
|_|  |_|  \\__,_|\\___|\\__|  \\___/|_|\n\
                      [By: mpalkov]\n\n"
# define WRITEMSG "writing error."
# define MALLOCMSG "malloc error."
# define MLXMSG "mlx error."
# define INITMSG "initialization error."

enum e_errs
{
	OK,
	NOARGS,
	INPUTERR,
	WRITEERR,
	MALLOCERR,
	MLXERR,
	INITERR
};

//	line_bytes is in bytes (int = 4 bytes)
typedef struct s_img
{
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_bytes;
	int		endian;
}				t_img;

typedef struct s_cnum
{
	double	re;
	double	im;
}				t_cnum;

typedef struct s_env
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
	double	rn_min;
	double	rn_max;
	double	in_min;
	double	in_max;
	double	julia_rn_c;
	double	julia_in_c;
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
# define KB_NUM0 82
# define KB_NUM1 83
# define KB_NUM2 84
# define KB_NUM3 85
# define KB_NUM4 86
# define KB_NUM5 87
# define KB_NUM6 88
# define KB_NUM7 89
# define KB_NUM8 91
# define KB_NUM9 92

# define BTN_X 17

# define M_WHEELUP 5
# define M_WHEELDN 4
# define M_LCLICK 1
# define M_RCLICK 2

void	ft_render(t_env *env);
void	ft_mandelbrot(t_env *env);
void	ft_julia(t_env *env);

void	ft_exit(int err, t_env *env);
int		ft_x_close(t_env *env);
int		mouse_handler(int evnt, int x, int y, void *params);
int		kb_handler(int keycode, void *params);
int		ft_rgb2int(int r, int g, int b);
int		ft_set_f_type(char *str, t_env *env);
void	ft_envzero(t_env *env);
void	ft_envinit(t_env *env, t_img *im, int argc, char **argv);
void	ft_mlx_frpix(int x, int y, int itr, t_env *env);

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
	write(1, "|                 1   or   Mandelbrot                |\n", 55);
	write(1, "|                 2   or   Julia                     |\n", 55);
	write(1, "|                 3   or   BurningShip               |\n", 55);
	write(1, "|____________________________________________________|\n", 55);
*/	
