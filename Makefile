# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: conrodri <conrodri@student.le-101.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/10 16:13:03 by conrodri          #+#    #+#              #
#    Updated: 2020/03/05 16:58:52 by conrodri         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRC_PATH = sources
SRC_NAME = 	main.c\
			algo.c\
			ft_vecs.c\
			matrixes_manipulating.c\
			intersections.c\
			aff.c\

SRC_SUP = 
OBJ_PATH = .objects
INC_PATH = includes
CPPFLAGS = -I $(INC_PATH)
LDFLAGS = -L libft
LDLIBS = libft/libft.a 
MINILIBX = -I minilibx_macos -L minilibx_macos -lmlx -framework OpenGL 	\
		-framework AppKit 
OPTI_FLAGS = -O3 -march=native -flto -ffast-math
NAME = rtv1
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

ERASE = \033[2K\r
BLUE = \033[36m
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
END = \033[0m

.PHONY: all, clean, fclean, re

all: lib $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(LDFLAGS) $(MINILIBX) $(OPTI_FLAGS) $(LDLIBS) $^ -o $@
	@printf "$(YELLOW)Executable Ready !$(END)\n"

lib:
	@make -C libft

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c libft/libft.a includes/rtv1.h includes/keys.h
	@mkdir -p $(OBJ_PATH) $(OBJ_PATH)/$(SRC_SUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@make -C libft clean
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)

re: fclean all

norme:
	@norminette $(SRC) $(INC_PATH)

