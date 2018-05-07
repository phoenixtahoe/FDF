/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_links.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:31:57 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/07 11:35:01 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_add_link(t_links *new, t_tools *tools)
{
	while (new->next != NULL)
		new = new->next;
	if (!(new->next = ft_create_link(tools)))
		return (-1);
	return (1);
}
