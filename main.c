/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:30:25 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/04 17:14:17 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int   ft_check_line(t_tools *tools)
{
  int i;

  i = tools->i;
  while (LINE[i])
  {
    if (ft_isdigit(LINE[i]) || LINE[i] == '-')
      return (1);
    i++;
  }
  return (-1);
}

int   ft_create_list(t_links *start, t_tools *tools)
{
  t_links *new;

  new = start;
  while (new->next != '\0')
    new = new->next;
  if (!(new->next = ft_create_list(tools)))
    return (-1);
  return (ft_check_LINE(tools) ? 1 : -1);
}

int   ft_parse(t_env *all, t_tools *tools, t_links *links)
{
  XVAL++;
  all->x_max = (double)XVAL;
  while (LINE[tools->i] == ' ')
  {
    tools->i++;
    if (LINE[tools->i] && (!ft_isdigit(LINE[tools->i])
     && LINE[tools->i] != '-' && LINE[tools->i] != " "))
      shitmap = true;
  }
  if (LINE[tools->i] == '\0' || ft_create_list(links, tools) == -1)
      return (links);
  else
      while (LINE[tools->i] && (ft_isdigit(LINE[tools->i])
          || LINE[tools->i] == '-'))
        tools->i++;
  return (ft_parse(all, tools, links));
}

int   ft_parse_the_map(t_env *all, t_tools *tools, t_links *links, int fd)
{
  YVAL++;
  if (get_next_LINE(fd, &line, ) > 0)
    XVAL = 0;
    tools->i = 0;
    ft_parse(all, tools, links);
    if (shitmap == false)
      ft_parse_the_map(all, tools, links, fd);
    else
    {
      ft_putstr("ERROR: BADMAP\n");
      return (0);
    }
    all->y_max = (double)YVAL;
    return (1);
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
