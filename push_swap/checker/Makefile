# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 12:52:28 by thda-sil          #+#    #+#              #
#    Updated: 2024/05/03 22:32:04 by thda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

# Colors and text formating
GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
YELLOW=\033[93m
WHITE=\033[0m

NAME = checker

PUSH_SWAP_ARCHIVE = ../push_swap/push_swap.a

SRC = checker.c \
	get_next_line.c \
	get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

COMPILER = cc

FLAGS = -Wall -Wextra -Werror
 
.c.o:
	@ echo "$(BLUE)Compiling $<...$(WHITE)"
	@ $(COMPILER) $(FLAGS) -Iincludes -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(PUSH_SWAP_ARCHIVE)
	@ echo "$(YELLOW)Linking objects...$(WHITE)"
	@ $(COMPILER) $^ -o $(NAME)
	@ cp $(NAME) ../push_swap
	@ echo "$(GREEN)Compile complete\n$(WHITE)"

$(PUSH_SWAP_ARCHIVE):
	@ cd ../push_swap && make

clean:
	@ echo "$(RED)Cleaning objects...$(WHITE)"
	@ rm -f $(OBJ)

fclean: clean
	@ echo "$(RED)Cleaning $(NAME)$(WHITE)"
	@ rm -f $(NAME)
	@ cd ../push_swap && rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
