/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:31:57 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/14 15:03:34 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_add_link(t_links *new, t_tools *tools)
{
	while (new->next != NULL)
		new = new->next;
	if (!(new->next = ft_create_link(tools)))
		return (-1);
	return (1);
}

t_links		*ft_create_link(t_tools *tools)
{
	t_links	*new;

	if (!(new = (t_links *)malloc(sizeof(t_links))))
		return (NULL);
	new->x = tools->x;
	new->y = tools->y;
	new->altitude = ft_atoi(&(tools->line[tools->i]));
	new->next = NULL;
	return (new);
}
