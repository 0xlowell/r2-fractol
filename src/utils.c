#include "../includes/fractol.h"

int	error_argc(int ac, int check)
{
	if (ac != 2)
	{
		ft_putstr_fd("Ac_error\nUsage: ./fractol <set>\nSuch as:"
					 "\nmandelbrot\njulia\n", 1);
		exit(1);
	}
	if(check == 0)
	{
		ft_putstr_fd("Launcher_error\nUsage: ./fractol <set>\nSuch as:"
					 "\nmandelbrot\njulia\n", 1);
		exit(1);
	}
	return(0);
}

int	model_selected(char *str, t_env	*e)
{
	if(ft_strncmp(str, "mandelbrot", 11) == 0)
		return(MANDELBROT);
	else if (ft_strncmp(str, "julia", 6) == 0)
		return (JULIA);
	else
	{
		free_alloc(e);
		exit(0);
	}
}

int ft_exit(t_env *env)
{
	mlx_destroy_image(env->mlx->mlx, env->mlx->img);
	mlx_destroy_window(env->mlx->mlx, env->mlx->mlx_win);
	free_alloc(env);
	exit(0);
}