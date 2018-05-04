/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_killer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:54:59 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/03 18:56:40 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_killer(t_links *head, t_rotation *rot, t_env *all)
{
	t_links *links;

	links = head;
	all->rot->radian_x = all->rot->degree_x * (PI / 180);
	all->rot->radian_y = all->rot->degree_y * (PI / 180);
	all->rot->radian_z = all->rot->degree_z * (PI / 180);
	while (links)
	{
		rot->x0 = (double)links->x;
		rot->y0 = ((links->y) * cos(rot->radian_x)) + (TRANS_Y);
		rot->z0 = (links->altitude * cos(rot->radian_x)) - (TRANS_Z);
		rot->x1 = (rot->x0 * cos(rot->radian_y)) - (rot->z0 * SIN_Y);
		rot->y1 = rot->y0;
		rot->z1 = (rot->z0 * cos(rot->radian_y)) + (rot->x0 * SIN_Y);
		rot->x2 = (rot->x1 * cos(rot->radian_z)) + (rot->y1 * SIN_Z);
		rot->y2 = (rot->y1 * cos(rot->radian_z)) - (rot->x1 * SIN_Z);
		rot->x2 *= (WIDTH - 320) / all->x_max;
		rot->y2 *= (HEIGHT - 300) / all->y_max;
		rot->x2 += 150;
		rot->y2 += 150;
		links->tru_y = rot->y2;
		links->tru_x = rot->x2;
		links = links->next;
	}
}
