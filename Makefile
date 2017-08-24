#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/05 20:38:46 by hcaspar           #+#    #+#              #
#    Updated: 2017/01/14 15:06:17 by hcaspar          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d

SRCS = main.c get_next_line.c exit.c hooks.c draw.c color_block.c init_pos.c \
		raycasting.c move.c turn.c grid.c minimap.c image.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I includes/

FLAGS = $(CFLAGS) -L libft/ -lft \
		-L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

CC = gcc

all : lib $(NAME)

$(NAME) : $(OBJS)
	gcc $(CFLAGS) $(FLAGS) $(OBJS) -o $(NAME)

lib :
	make -C libft/

clean :
	make -C libft/ clean
	rm -f $(OBJS)

fclean : clean
	make -C libft/ fclean
	rm -f $(NAME)

re : fclean all