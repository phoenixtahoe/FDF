/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 11:41:09 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/01 12:27:29 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_painting_x(t_links *init, t_links *terminal, t_env *all)
{
	double e;
	double x;
	double y;
	double slope;
	
	x = init->x;
	y = init->y;
	e = 2 * all->y = all->x;
	slope = y < terminal->y ? 1 : -1;
	while (x < terminal->x)
	{
		mlx_pixel_put(all->mlx, all->win, x, y, 0xFFFFFF);
		if (e > 0)
		{
			y += slope;
			e += 2 * (all->y - all->x);
		}
		else
			e += 2 * all->y;
		x++;
	}
}

void	ft_painting_y(t_links *init, t_links *terminal, t_env *all)
{
	double e;
	double x;
	double y;
	double slope;
	
	x = init->x;
	y = init->y;
	e = 2 * all->x = all->y;
	slope = x < terminal->x ? 1 : -1;
	while (y < terminal->y)
	{
		mlx_pixel_put(all->mlx, all->win, x, y, 0xFFFFFF);
		if (e > 0)
		{
			x += slope;
			e += 2 * (all->y - all->x);
		}
		else
			e += 2 * all->x;
		y++;
	}
}

void	ft_paint(t_links *init, t_links *terminal, t_env *all)
{
	int		DrivingAxis;
	
	all->x = fabs(terminal->x - init->x);
	all->y = fabs(terminal->y - init->y);
	DrivingAxis = all->da_x >= all->theda_y ? 1 : 0;
	if (DrivingAxis > 0)
	 	init->x <= terminal->x ?
		ft_painting_x(init, terminal, all) :
		ft_painting_x(termina, init, all);
	else if (DrivingAxis == 0)
		init->y <= terminal->y ?
		ft_painting_y(init, terminal, all) :
		ft_painting_y(terminal, init, all);
}
