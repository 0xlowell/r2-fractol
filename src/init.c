/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:57:01 by lzima             #+#    #+#             */
/*   Updated: 2022/05/12 16:57:03 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close_window(t_env *e)
{
	ft_exit(e);
	return (0);
}

int	launcher(t_env *e)
{
	if (e->mlx->model == 1)
	{
		mandelbrot_set(e);
		start_hooks(e);
		return (1);
	}
	if (e->mlx->model == 2)
	{
		julia_set(e);
		start_hooks(e);
		return (1);
	}
	return (0);
}

void	init_data(t_env *e)
{
	e->colors->r = 0;
	e->colors->b = 0;
	e->colors->g = 0;
	e->complex->zoom = 0.9329202112746;
}

int	init_window(t_env *env)
{
	if (!env)
		return (0);
	env->mlx->mlx = mlx_init();
	env->mlx->mlx_win = mlx_new_window(env->mlx->mlx, WIDTH, HEIGHT, "fract-ol");
	if (!env->mlx->mlx_win)
		return (0);
	env->mlx->img = mlx_new_image(env->mlx->mlx, HEIGHT, WIDTH);
	env->mlx->addr = (int *)mlx_get_data_addr(env->mlx->img,
		&env->mlx->bpp, &env->mlx->line_len, &env->mlx->endian);
	env->mlx->line_len /= 8;
	return (1);
}
