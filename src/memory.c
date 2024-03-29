/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzima <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:54:42 by lzima             #+#    #+#             */
/*   Updated: 2022/05/12 16:54:44 by lzima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	free_alloc(t_env *e)
{
	free(e->mlx);
	free(e->complex);
	free(e->colors);
	free(e);
	exit(1);
}

t_env	*mem_alloc(void)
{
	t_env	*tmp;

	tmp = (t_env *) malloc(sizeof(t_env));
	if (tmp == NULL)
		return (NULL);
	tmp->is_pressed = false;
	tmp->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	tmp->complex = (t_complex *)malloc(sizeof(t_complex));
	tmp->colors = (t_colors *)malloc(sizeof(t_colors));
	if (!tmp->mlx || !tmp->complex || !tmp->colors)
		return (NULL);
	return (tmp);
}
