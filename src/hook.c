/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:54:42 by lzima             #+#    #+#             */
/*   Updated: 2022/05/12 16:54:44 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	start_hooks(t_env *e)
{
	mlx_mouse_hook(e->mlx->mlx_win, &mouse_hook, e);
	mlx_key_hook(e->mlx->mlx_win, &key_hook, e);
	mlx_hook(e->mlx->mlx_win, 17, 0, ft_exit, e);
	mlx_hook(e->mlx->mlx_win, 6, 1L << 8, &on_mousemove, e);
	mlx_loop(e->mlx->mlx);
}

int	mouse_move(int x, int y, t_env *e)
{
	if (e->is_pressed == false)
		e->is_pressed = true;
	else
		e->is_pressed = false;
	on_mousemove(x, y, e);
	return (0);
}

int	mouse_hook(int code, int x, int y, t_env *e)
{
	double	new_xmin;
	double	new_ymin;

	new_xmin = e->complex->z_re * x + e->xmin;
	new_ymin = e->complex->z_im * y + e->ymin;
	if (code == 4)
	{
		e->complex->z_re *= e->complex->zoom;
		e->complex->z_im *= e->complex->zoom;
	}
	if (code == 5)
	{
		e->complex->z_re /= e->complex->zoom;
		e->complex->z_im /= e->complex->zoom;
	}
	if (code == 1)
		mouse_move(x, y, e);
	e->xmin = new_xmin - x * e->complex->z_re;
	e->xmax = new_xmin + (HEIGHT - x) * e->complex->z_re;
	e->ymin = new_ymin - y * e->complex->z_im;
	e->ymax = new_ymin + (WIDTH - y) * e->complex->z_im;
	draw_image(e);
	return (0);
}

int	key_hook(int keycode, t_env *e)
{
	if (keycode == K_ESC)
		ft_exit(e);
	if (keycode == K_R)
		e->colors->r += 2;
	if (keycode == K_L)
		e->colors->g += 2;
	if (keycode == K_O)
		e->colors->b += 2;
	if (keycode == K_S)
	{
		e->colors->r -= 6;
		e->colors->b -= 4;
		e->colors->g -= 2;
	}
	draw_image(e);
	return (0);
}

int	on_mousemove(int x, int y, t_env *e)
{
	if (e->is_pressed)
	{
		e->complex->c_re = (double)x / WIDTH * 2 - 1;
		e->complex->c_im = (double)y / HEIGHT * 2 - 1;
		draw_image(e);
	}
	return (0);
}
