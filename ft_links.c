/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_links.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:31:57 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/07 09:14:01 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int   ft_check_line(t_tools *tools)
// {
//   int i;
// 
//   i = tools->i;
//   while (Line[i])
//   {
//     if (ft_isdigit(line[i]) || line[i] == '-')
//       return (1);
//     i++;
//   }
//   return (-1);
// }
// 
// int   ft_create_list(t_links *start, t_tools *tools)
// {
//   t_links *new;
// 
//   new = start;
//   while (new->next != '\0')
//     new = new->next;
//   if (!(new->next = ft_create_list(tools)))
//     return (-1);
//   return (ft_check_line(tools) ? 1 : -1);
// }

t_links	*ft_create_link(t_tools *tools)
{
	t_links *new;
	
	if (!(new = (t_links *)malloc(sizeof(t_links))))
		return (NULL);
	new->x = XVAl;
	new->y = YVAL;
	new->altitude = ft_atoi(&(LINE[tools->i]));
	new->next = NULL;
	return (new);
}

int		ft_add_link(t_links *new, t_tools *tools)
{
	while (new->next != NULL)
		new = new->next;
	if (!(new->next = ft_create_link(tools)))
		return (-1);
	return (1);
}
