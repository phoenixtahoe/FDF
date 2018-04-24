#ifndef FDF_H
# define FDF_H

# define WIDTH 800
# define HEIGHT 800

# include "minilibx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"


typedef struct		s_tools
{
	char			*line;
	int				i;
	bool			BADMAP;
	int				fd;
	int				y;
	int				x;
	int			prev_x;
	int			prev_y;
	char			*altitude;
}                 t_tools;

typedef struct		s_env
{
	t_tools			t_tools;
	t_links			*links;
	t_rotation		*rot;
}