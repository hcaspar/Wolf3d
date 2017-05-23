# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/23 11:31:01 by hcaspar           #+#    #+#              #
#    Updated: 2017/05/23 12:56:16 by hcaspar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			wolf3d
CC =			gcc

SDL_DIR =		SDL2
SDL_SRC_DIR =	SDL2-2.0.5
SDL_INC =		$(SDL_DIR)/include/SDL2
SDL_FLAG =		`$(LIBS_DIR)/SDL2/sdl2-config --cflags --static-libs`

INC_DIR =		include $(SDL_INC)
SRC_DIR =		src
OBJ_DIR =		obj

SRC_NAME =		main.c

OBJ_NAME =		$(SRC_NAME:.c=.o)

SRC =			$(addprefix $(SRC_DIR)/,$(SRC_NAME))
OBJ =			$(addprefix $(OBJ_DIR)/,$(OBJ_NAME))
INC =			$(addprefix -I ,$(INC_DIR))

CFLAGS =		-Wall -Werror -Wextra $(INC)

.PHONY: all clean fclean re norme

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

config:
	mkdir -p $(SDL_DIR)
	cd $(SDL_DIR) && ../$(SDL_SRC_DIR)/configure --prefix=$(PWD)/$(SDL_DIR)
	make -j6 -C $(SDL_DIR)
	make -C $(SDL_DIR) install

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -rf $(SDL_DIR)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_DIR)
