/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:32:36 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/07 12:55:15 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_repeat(t_env *all)
{
	ft_killer(all->links, all->rot, all);
	mlx_clear_window(all->mlx, all->win);
	ft_directions(all);
}


int		ft_key_hook(int key, t_env *all)
{
	if (key == 53)
		ft_exit(all);
	else if (key == 126)
		all->rot->degree_x += 1;
	else if (key == 124)
		all->rot->degree_y += 1;
	else if (key == 125)
		all->rot->degree_x -= 1;
	else if (key == 123)
		all->rot->degree_y -= 1;
	else if (key == 13)
		all->rot->degree_x += 1;
	else if (key == 1)
		all->rot->degree_x -= 1;
	else if (key == 2)
		all->rot->degree_y += 1;
	else if (key == 0)
		all->rot->degree_y -= 1;
	ft_repeat(all);
	return (0);
}

void	ft_mlx_looper(t_env *all)
{
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, WIDTH, HEIGHT, "FDF");
	ft_directions(all);
	mlx_hook(all->win, 2, 0, ft_key_hook, all);
	mlx_loop(all->mlx);
}