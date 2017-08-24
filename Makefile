# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/05 20:38:46 by hcaspar           #+#    #+#              #
#    Updated: 2017/08/24 14:23:28 by hcaspar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRCS = main.c get_next_line.c exit.c hooks.c draw.c color_block.c init_pos.c \
		raycasting.c move.c turn.c grid.c minimap.c image.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I includes/

FLAGS = $(CFLAGS) -L libft/ -lft \
		-L mlx/ -lmlx -framework OpenGL -framework AppKit

CC = gcc

all : lib $(NAME)

$(NAME) : $(OBJS)
	gcc $(CFLAGS) $(FLAGS) $(OBJS) -o $(NAME)

lib :
	make -C mlx/
	make -C libft/

clean :
	make -C libft/ clean
	rm -f $(OBJS)

fclean : clean
	make -C mlx/ clean
	make -C libft/ fclean
	rm -f $(NAME)

re : fclean all
