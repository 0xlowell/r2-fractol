/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:55:24 by lzima             #+#    #+#             */
/*   Updated: 2022/05/12 16:55:25 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot_draw(int iter, double x0, double y0, t_env *e)
{
	double	new_x;
	double	new_y;
	double	x2;
	double	y2;

	x2 = x0;
	y2 = y0;
	while (iter > 0)
	{
		new_x = x0 * x0 - y0 * y0;
		new_y = 2 * x0 * y0;
		x0 = new_x + x2;
		y0 = new_y + y2;
		if ((x0 * x0 + y0 * y0) >= 16)
			break ;
		iter--;
	}
	return (rgb_to_int(iter, e));
}

void	mandelbrot_set(t_env *e)
{
	e->xmin = -2.0;
	e->xmax = 0.47;
	e->ymin = -1.12;
	e->ymax = 1.12;
	e->complex->z_re = (e->xmax - e->xmin) / WIDTH;
	e->complex->z_im = (e->ymax - e->ymin) / HEIGHT;
	draw_image(e);
}
