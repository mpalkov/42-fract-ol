
#include "fractol.h"

void	ft_printerr(errno)
{
	char	*msg;

	msg = NULL;
	if (errno == OK)
		return ;
	else if (errno == NOARGS || errno == INPUTERR)
		msg = NOARGSMSG;
	else if (errno == WRITEERR)
		msg = WRITEMSG;
	else if (MALLOCERR)
		msg = MALLOCMSG;
	else if (MLXERR)
		msg = MLXMSG;
	ft_putstr_fd(msg, STDERR_FILENO);
	write(STDERR_FILENO, "\n", 1);
	return ;
}

void	ft_freeall(t_env *env)
{
	if (env->img->img)
		mlx_destroy_image(env->mlx, env->img->img);
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
	return ;
}

int	ft_x_close(t_env *env)
{
	ft_exit(OK, env);
	return (0);
}

void	ft_exit(int err, t_env *env)
{
	env->errno = err;
	ft_freeall(env);
	ft_printerr(err);
	if (err == OK)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
	return ;
}
