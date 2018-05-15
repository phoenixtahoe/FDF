/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:30:25 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/14 15:02:59 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_check_line(t_tools *tools)
{
	int		i;

	i = tools->i;
	while (tools->line[i])
	{
		if (ft_isdigit(tools->line[i]) || tools->line[i] == '-')
			return (1);
		i++;
	}
	return (-1);
}

int			ft_create_list(t_links *start, t_tools *tools)
{
	t_links		*new;

	new = start;
	if (!ft_add_link(new, tools))
		return (-1);
	return (ft_check_line(tools) ? 1 : -1);
}

t_links		*ft_parse(t_env *all, t_tools *tools, t_links *links)
{
	tools->x++;
	all->x_max = (double)tools->x;
	while (tools->line[tools->i] == ' ')
	{
		tools->i++;
		if (tools->line[tools->i] && (!ft_isdigit(tools->line[tools->i])
			&& tools->line[tools->i] != '-' && tools->line[tools->i] != ' '))
			tools->shitmap = true;
	}
	if (tools->line[tools->i] == '\0' || ft_create_list(links, tools) == -1)
		return (links);
	else
		while (tools->line[tools->i] &&
			(ft_isdigit(tools->line[tools->i]) || tools->line[tools->i] == '-'))
			tools->i++;
	return (ft_parse(all, tools, links));
}

int			ft_map(t_env *all, t_tools *tools, t_links *links, int fd)
{
	tools->y++;
	if (get_next_line(fd, &tools->line) > 0)
	{
		tools->x = 0;
		tools->i = 0;
		ft_parse(all, tools, links);
		free(tools->line);
		if (tools->shitmap == false)
			ft_map(all, tools, links, fd);
		else
		{
			ft_putstr("ERROR: shit map\n");
			return (0);
		}
	}
	all->y_max = (double)tools->y;
	return (1);
}

int			main(int argc, char **argv)
{
	t_env		*all;
	int			fd;

	all = ft_init();
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!ft_map(all, all->tools, all->links, fd))
			return (0);
		close(fd);
		free(all->links);
		all->links = all->links->next;
		ft_killer(all->links, all->rot, all);
		ft_mlx_looper(all);
	}
	else
	{
		ft_putstr("ERROR: Usage: ./fdf [file]\n");
		return (0);
	}
}
