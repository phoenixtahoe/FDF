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
