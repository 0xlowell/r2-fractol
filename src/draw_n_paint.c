/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_n_paint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:48:10 by lzima             #+#    #+#             */
/*   Updated: 2022/05/12 16:48:43 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	rgb_to_int(int it, t_env *e)
{
	(void)e;
	return (((it << e->colors->g) + (it << e->colors->b) + it * e->colors->r));
}

int	draw_image(t_env *e)
{
	int		x;
	int		y;
	int		pix;
	double	zx;
	double	zy;

	e->mlx->iter = ITERATION;
	y = -1;
	pix = 0;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			zx = e->xmin + (x * e->complex->z_re);
			zy = e->ymax - (y * e->complex->z_im);
			if (e->mlx->model == MANDELBROT)
				e->mlx->addr[pix++] = mandelbrot_draw(e->mlx->iter, zx, zy, e);
			else if (e->mlx->model == JULIA)
				e->mlx->addr[pix++] = julia_draw(e->mlx->iter, zx, zy, e);
		}
	}
	mlx_put_image_to_window(e->mlx->mlx, e->mlx->mlx_win,
		e->mlx->img, 0, 0);
	return (1);
}
