# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdavid <pdavid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/03 19:49:36 by pdavid            #+#    #+#              #
#    Updated: 2018/05/08 14:34:21 by pdavid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libx_flags = -L minilibx -lmlx -framework OpenGL -framework AppKit

cflags = -Wall -Wextra -Werror

make_lib = @make -C ./libft/

header = fdf.h

includes = ./libft/libft.a ./minilibx/libmlx.a

SRC = main.c init.c rot.c mlx.c tools.c links.c paint.c

OBJ = *.o

cc = @gcc -g

name = fdf

$(name) :
		@make -C libft/
		$(cc) $(cflags) $(libx_flags) $(SRC) $(includes) -o $(name)
clean:
		@make -C libft/ clean
		@/bin/rm -rf $(name)
fclean: clean
		@make -C libft/ fclean
re: fclean all
