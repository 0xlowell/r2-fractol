/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:50:25 by lzima             #+#    #+#             */
/*   Updated: 2022/04/27 10:51:37 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int ac, char *av[])
{
	t_env	*e;
	int		check;

	check = 1;
	error_argc(ac, check);
	e = mem_alloc();
	if (!e)
		free_alloc(e);
	e->mlx->model = model_selected(av[1], e);
	init_window(e);
	init_data(e);
	check = launcher(e);
	error_argc(ac, check);
	free_alloc(e);
	return (0);
}
