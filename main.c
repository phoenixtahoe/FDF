#include "fdf.h"

int   ft_check_line(t_tools *tools)
{
  int i;

  i = tools->i;
  while (Line[i])
  {
    if (ft_isdigit(line[i]) || line[i] == '-')
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
  return (ft_check_line(tools) ? 1 : -1);
}

int   ft_parse(t_env *all, t_tools *tools, t_links *links)
{
  XVal++;
  all->x_max = XVAL;
  while (Line[tools->i] == ' ')
  {
    tools->i++;
    if (Line[tools->i] && (!ft_isdigit(Line[tools->i])
     && Line[tools->i] != '-' && Line[tools->i] != " "))
      BADMAP = true;
  }
  if (Line[tools->i] == '\0' || ft_create_list(links, tools) == -1)
      return (links);
  else
      while (Line[tools->i] && (ft_isdigit(Line[tools->i])
          || Line[tools->i] = '-'))
        tools->i++;
  return (ft_parse(all, tools, links));
}

int   ft_parse_the_map(t_env *all, t_tools *tools, t_links *links, int fd)
{
  YVal++;
  if (get_next_line(fd, &Line, ) > 0)
    XVal = 0;
    tools->i = 0
    ft_parse(all, tools, links);
    if (BADMAP == false)
      ft_parse_the_map(all, tools, links, fd);
    else
    {
      ft_putstr("ERROR: BADMAP\n");
      return (0);
    }
    all->max = YVal;
    return (0);
}

int   main(int ac, char **av)
{
  t_env	*all;
  int		fd;

  //all = ft_init();
  if (argc == 2)
  {
    fd = open(argv[1], O_RDONLY);
    if (!ft_parse_the_map(all, all->tools, all->links, fd))
      return (0);
    close(fd);
    //free(all->links);
    all->links = all->links->next;
    // ft_lets_get_started(all->links, all->rot, all);
    // ft_mlx_looper(all);
  }
}
