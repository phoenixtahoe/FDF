/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 11:41:09 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/08 14:27:58 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_paint_x(t_links *init, t_links *terminal, t_env *all)
{
	double e;
	double x;
	double y;
	double slope;
	
	x = init->tru_x;
	y = init->tru_y;
	e = 2 * all->theda_y - all->theda_x;
	slope = y < terminal->tru_y ? 1 : -1;
	while (x < terminal->tru_x)
	{
		mlx_pixel_put(all->mlx, all->win, x, y, 0x0FFFFF);
		if (e > 0)
		{
			y += slope;
			e += 2 * (all->theda_y - all->theda_x);
		}
		else
			e += 2 * all->theda_y;
		x++;
	}
}

void	ft_paint_y(t_links *init, t_links *terminal, t_env *all)
{
	double e;
	double x;
	double y;
	double slope;
	
	x = init->tru_x;
	y = init->tru_y;
	e = 2 * all->theda_x - all->theda_y;
	slope = x < terminal->tru_x ? 1 : -1;
	while (y < terminal->tru_y)
	{
		mlx_pixel_put(all->mlx, all->win, x, y, 0x0FF0000);
		if (e > 0)
		{
			e += 2 * (all->theda_x - all->theda_y);
			x += slope;
		}
		else
			e += 2 * all->theda_x;
		y++;
	}
}

void	ft_paint(t_links *init, t_links *terminal, t_env *all)
{
	int		da;
	
	all->theda_x = fabs(terminal->tru_x - init->tru_x);
	all->theda_y = fabs(terminal->tru_y - init->tru_y);
	da = all->theda_x >= all->theda_y ? 1 : 0;
	if (da > 0)
	 	init->tru_x <= terminal->tru_x ?
		ft_paint_x(init, terminal, all) :
		ft_paint_x(terminal, init, all);
	else if (da == 0)
		init->tru_y <= terminal->tru_y ?
		ft_paint_y(init, terminal, all) :
		ft_paint_y(terminal, init, all);
}
