#include "../includes/fractol.h"

int julia_draw(int i, double zx, double zy, t_env *e)
{
	double	new_x;
	int j;

	j= 0;
	while (i > j)
	{
		new_x = zx * zx - zy * zy;
		zy = (zx + zx) * zy + e->complex->c_im;
		zx = new_x + e->complex->c_re;
		if ((zx * zx + zy * zy) > 4)
			break;
		j++;
	}
	return (rgb_to_int(j, e));
}

void	julia_set(t_env *e)
{
	e->xmin = -2;
	e->xmax = 2;
	e->ymin = -2;
	e->ymax = 2;
	e->complex->z_re = (e->xmax - e->xmin) / WIDTH;
	e->complex->z_im = (e->ymax - e->ymin) / HEIGHT;
	e->complex->c_re = -0.79;
	e->complex->c_im = 0.11015;
	draw_image(e);

}
