/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <lzima@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:31:41 by lzima             #+#    #+#             */
/*   Updated: 2022/01/11 16:21:47 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/* ---lib--- */
# include <unistd.h>
# include <stdlib.h>
# include "../lib/mlx/mlx.h"
# include <math.h>
# include "../includes/keys.h"
# include <stdbool.h>
# include <stdio.h>

/* --- data --- */
# define WIDTH 				720
# define HEIGHT				720
# define ITERATION 			50

/* --- glossary --- */
# define MANDELBROT 		1
# define JULIA 				2

typedef struct s_mlx
{
	int		model;
	int		iter;
	void	*mlx;
	void	*mlx_win;
	char	*img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		height;
	int		width;
}	t_mlx;

typedef struct s_complex
{
	double	z_re;
	double	z_im;
	double	c_re;
	double	c_im;
	double	zoom;
}	t_complex;

typedef struct s_colors
{
	unsigned char	r;
	unsigned char	b;
	unsigned char	g;
}	t_colors;

typedef struct s_env
{
	t_mlx		*mlx;
	t_colors	*colors;
	t_complex	*complex;
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double		movex;
	double		movey;
	bool		is_pressed;
}	t_env;

/* --- main --- */
int		main(int ac, char**av);

/* --- memory ---*/
t_env	*mem_alloc(void);
void	free_alloc(t_env *e);

/* --- utils ---*/
int		model_selected(char *str, t_env *e);
int		error_argc(int argc, int check);
int		ft_exit(t_env *env);

/* --- init.c --- */
int		init_window(t_env *env);
void	init_data(t_env *e);
int		launcher(t_env *e);
int		close_window(t_env *e);

/* --- hook --- */
void	start_hooks(t_env *e);
int		on_mousemove(int x, int y, t_env *e);
int		key_hook(int keycode, t_env *e);
int		mouse_hook(int code, int x, int y, t_env *e);
int		mouse_move(int x, int y, t_env *e);

/* --- mandelbrot --- */
void	mandelbrot_set(t_env *e);
int		mandelbrot_draw(int iter, double x0, double y0, t_env *e);

/* --- draw_n_paint --- */
int		draw_image(t_env *env);
int		pick_color(int iteration);
int		rgb_to_int(int iteration, t_env *e);

/* --- julia --- */
void	julia_set(t_env *env);
int		julia_draw(int i, double zx, double zy, t_env *e);

/* --- libft --- */
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif //FRACTOL_H
