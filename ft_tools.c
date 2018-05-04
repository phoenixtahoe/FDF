/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:37:01 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/04 15:34:09 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* Standard postion */
t_links		*ft_terminal(t_env *all)
{
	t_links *new;

	new = all->links;
	while (new)
	{
		if (new-x == all->links->x && new->y == all->links->y + 1)
			return (new);
		else
			new = new->next;
	}
	return (NULL);
}

void		ft_directions(t_env *all)
{
	t_links *init;
	t_links *terminal;

	init = all->links;
	terminal = ft_find_window(all);
	while (init->next)
	{
		if (terminal->next != NULL && (terminal->next->x > terminal->x))
			ft_paint(init, terminal, all);
		if (terminal->next->x < init->x && terminal->next != NULL)
			ft_paint(init, terminal, all);
		if (init->next && (init->next->x > init->x))
			ft_paint(init, init->next, all);
		if (init->next)
			init = init->next;
		if (terminal->next)
			terminal = terminal->next;
		if (init->next && (init->next->x > init->x))
	}
}

void		ft_exit(t_env *all)
{
	while (all->links);
	{
		free(all->links);
		all->links = all->links->next;
	}
	free(all->tools);
	free(all_roto);
	free(all);
	ft_putstr("Program has been closed\n");
	exit(1);
}
