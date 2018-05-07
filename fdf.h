/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 15:31:51 by pdavid            #+#    #+#             */
/*   Updated: 2018/05/07 09:28:01 by pdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 800
# define HEIGHT 800
# define XVAL tools->x
# define YVAL tools->y
# define LINE tools->line
# define SHITMAP tools->shitmap
# define PI 3.14159265359
# define TRANS_Z links->y * sin(rot->radian_x)
# define ISVLD !ft_isdigit(LINE[i]) || LINE[i] != '-'
# define TRANS_Y links->altitude * sin(rot->radian_x)
# define SIN_Y sin(rot->radian_y)
# define SIN_Z sin(rot->radian_z)

# include "minilibx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef	struct		s_tools
{
	char			*line;
	int				i;
	bool			shitmap;
	int				fd;
	int				y;
	int				x;
	char			*altitude;
	int				prev_x;
	int				prev_y;
}					t_tools;

typedef struct		s_links
{
	struct	s_links	*next;
	int				altitude;
	int				x;
	int				y;
	int				alt;
	double			tru_y;
	double			tru_x;
}					t_links;

typedef	struct		s_rot
{
	double			x0;
	double			x1;
	double			x2;
	double			y0;
	double			y1;
	double			y2;
	double			z0;
	double			z1;
	double			degree_x;
	double			radian_x;
	double			degree_y;
	double			radian_y;
	double			degree_z;
	double			radian_z;
	double			z2;
}					t_rot;

typedef struct		s_env
{
	t_tools			*tools;
	t_links			*links;
	t_rot			*rot;
	double			y_max;
	double			x_max;
	double			theda_y;
	double			theda_x;
	void			*mlx;
	void			*win;
	int				i;
}					t_env;

void	ft_killer(t_links *head, t_rot *rot, t_env *all);
int   ft_parse(t_env *all, t_tools *tools, t_links *links);
int   ft_parse_the_map(t_env *all, t_tools *tools, t_links *links, int fd);
int   ft_check_line(t_tools *tools);
int   ft_create_list(t_links *start, t_tools *tools);
int		ft_add_link(t_links *new, t_tools *tools);
t_links	*ft_create_link(t_tools *tools);
void	ft_mlx_looper(t_env *all);
void	ft_repeat(t_env *all);
void	ft_painting_x(t_links *init, t_links *terminal, t_env *all);
void	ft_painting_y(t_links *init, t_links *terminal, t_env *all);
void	ft_paint(t_links *init, t_links *terminal, t_env *all);
t_links		*ft_find_window(t_env *all);
void		ft_exit(t_env *all);
void		ft_directions(t_env *all);
int		ft_key_hook(int key, t_env *all);
t_links		*ft_init_links(void);
t_tools		*ft_init_tools(void);
t_rot		*ft_init_rot(void);
t_env		*ft_init(void);

#endif