/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:32:36 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/01 12:38:31 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_looper(t_env *all)
{
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, WIDTH, HEIGHT, "FDF");
	ft_directions(all);
	mlx_hook(all->win, 2, 0, ft_key_hook, all);
	mlx_loop(all->mlx);
}

void	ft_repeat(t_env *all)
{
	ft_killer(all->links, all->rot, all);
	mlx_clear_window(all->mlx, all->win);
	ft_directions(all;)
}