/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:30:25 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/03 19:19:17 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int   ft_parse(t_env *all, t_tools *tools, t_links *links)
{
  XVal++;
  all->x_max = XVAL;
  while (Line[tools->i] == ' ')
  {
    tools->i++;
    if (Line[tools->i] && (!ft_isdigit(Line[tools->i])
     && Line[tools->i] != '-' && Line[tools->i] != " "))
      shitmap = true;
  }
  if (Line[tools->i] == '\0' || ft_create_list(links, tools) == -1)
      return (links);
  else
      while (Line[tools->i] && (ft_isdigit(Line[tools->i])
          || Line[tools->i] == '-'))
        tools->i++;
  return (ft_parse(all, tools, links));
}

int   ft_parse_the_map(t_env *all, t_tools *tools, t_links *links, int fd)
{
  YVal++;
  if (get_next_line(fd, &Line, ) > 0)
    XVal = 0;
    tools->i = 0;
    ft_parse(all, tools, links);
    if (shitmap == false)
      ft_parse_the_map(all, tools, links, fd);
    else
    {
      ft_putstr("ERROR: BADMAP\n");
      return (0);
    }
    all->max = YVal;
    return (0);
}

int		main(int argc, char **argv)
{
	t_env	*all;
	int		fd;

	all = ft_init();
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!ft_parse_the_map(all, all->tools, all->links, fd))
			return (0);
		close(fd);
		free(all->links);
		all->links = all->links->next;
		ft_killer(all->links, all->rot, all);
		ft_mlx_looper(all);
	}
}
