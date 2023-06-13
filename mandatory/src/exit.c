
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

void	ft_exit(int err, t_enviro *env)
{
	env->errno = err;
	// CREATE THIS FN
	// ft_freeall();
	ft_printerr(err);
	if (err == OK)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
	return ;
}