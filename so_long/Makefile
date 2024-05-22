# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 15:06:50 by thda-sil          #+#    #+#              #
#    Updated: 2024/05/21 21:28:27 by thda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

NAME = so_long

NAME_BONUS = so_long_bonus

SRC_FOLDERS = $(shell find sources)

SRC = $(filter %.c, $(SRC_FOLDERS))

OBJ = $(SRC:.c=.o)

COMPILER = cc

FLAGS = -Wall -Wextra -Werror

BONUS_ENABLED = 0

.c.o:
	$(COMPILER) -D BONUS_ENABLED=$(BONUS_ENABLED) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME):	$(OBJ)
	make -C libraries/libft
	make -C libraries/minilibx-linux
	$(COMPILER) $(FLAGS) $(OBJ) libraries/libft/libft.a -o $(NAME) -Llibraries/minilibx-linux -lmlx -lX11 -lXext
	@ echo "Compile complete\n"

$(NAME_BONUS): $(OBJ)
	make -C libraries/libft
	make -C libraries/minilibx-linux
	$(COMPILER) $(FLAGS) $(OBJ) libraries/libft/libft.a -o $(NAME)_bonus -Llibraries/minilibx-linux -lmlx -lX11 -lXext
	@ echo "Compile complete\n"

bonus: override BONUS_ENABLED = 1
bonus : $(NAME_BONUS)

clean:
	rm -f $(OBJ)
	make clean -C libraries/libft
	make clean -C libraries/minilibx-linux

fclean:	clean
	rm -f $(NAME)
	rm -f $(NAME)_bonus
	make fclean -C libraries/libft

re:	fclean all

.PHONY: all clean fclean re bonus
