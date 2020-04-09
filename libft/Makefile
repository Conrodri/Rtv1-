# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: conrodri <conrodri@student.le-101.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/09 15:24:03 by conrodri          #+#    #+#              #
#    Updated: 2020/02/20 18:58:12 by conrodri         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRC_PATH = sources
SRC_NAME = 	put/ft_putchar.c\
			str/ft_strlen.c\
			put/ft_putstr.c\
			put/ft_putnbr.c\
			str/ft_strcpy.c\
			str/ft_strncpy.c\
			str/ft_strdup.c\
			mem/ft_memset.c\
			mem/ft_memcpy.c\
			ft_bzero.c\
			mem/ft_memccpy.c\
			mem/ft_memcmp.c\
			str/ft_strcat.c\
			str/ft_strncat.c\
			str/ft_strlcat.c\
			ft_toupper.c\
			ft_atoi.c\
			str/ft_strstr.c\
			str/ft_strnstr.c\
			mem/ft_memmove.c\
			str/ft_strcmp.c\
			str/ft_strncmp.c\
			mem/ft_memchr.c\
			mem/ft_memalloc.c\
			mem/ft_memdel.c\
			str/ft_strnew.c\
			str/ft_strdel.c\
			str/ft_strclr.c\
			str/ft_striter.c\
			str/ft_striteri.c\
			str/ft_strmap.c\
			str/ft_strmapi.c\
			str/ft_strequ.c\
			str/ft_strnequ.c\
			str/ft_strsub.c\
			str/ft_strjoin.c\
			str/ft_strtrim.c\
			ft_itoa.c\
			str/ft_strsplit.c\
			is/ft_isalnum.c\
			is/ft_isalpha.c\
			is/ft_isascii.c\
			is/ft_isdigit.c\
			is/ft_isprint.c\
			ft_tolower.c\
			str/ft_strchr.c\
			str/ft_strrchr.c\
			put/ft_putendl.c\
			put/ft_putchar_fd.c\
			put/ft_putnbr_fd.c\
			put/ft_putstr_fd.c\
			put/ft_putendl_fd.c\
			ft_countword.c\
			ft_countletters.c\
			lst/ft_lstadd.c\
			lst/ft_lstdel.c\
			lst/ft_lstdelone.c\
			lst/ft_lstiter.c\
			lst/ft_lstmap.c\
			lst/ft_lstnew.c\
			str/ft_strcapitalize.c\
			ft_error.c\
			mlx/ft_create_img.c\
			mlx/ft_get_pixel.c\
			mlx/ft_img_dark.c\
			mlx/ft_pixel_put.c\
			ft_sqrt.c\
			real/op_real.c\
			real/real_norm.c\
			real/real_scale_product.c\
			real/real_turn.c\
			ft_deg_to_rad.c\
			create_2d_line_points.c\

SRC_SUP = {is,lst,mem,mlx,put,str,real}
OBJ_PATH = objects
INC_PATH = includes
CPPFLAGS = -I $(INC_PATH)
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

ERASE = \033[2K\r
BLUE = \033[36m
WHITE = \033[37m
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
END = \033[0m

.PHONY: all, clean, fclean, re

all: mlx $(NAME)

$(NAME): $(OBJ)
	@ar -rc $@ $^
	@ranlib $@
	@printf "$(BLUE)\nLibft Ready !$(END)\n"

mlx:
	@make -C ../minilibx_macos

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c ../minilibx_macos/libmlx.a
	@mkdir -p $(OBJ_PATH) $(OBJ_PATH)/$(SRC_SUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@printf "$(ERASE)$(RED)> Compilation libft <"

clean:
	@rm -rf $(OBJ_PATH)
	
fclean: clean
	@rm -rf $(NAME)
	@make -C ../minilibx_macos clean

re: fclean all

norme:
	@norminette $(SRC) $(INC_PATH)
