# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 12:07:11 by thda-sil          #+#    #+#              #
#    Updated: 2024/05/04 16:47:47 by thda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

# Colors and text formating
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
YELLOW = \033[93m
WHITE = \033[0m

NAME = push_swap

ARCHIVE = push_swap.a

SRC = sources/main.c \
	sources/stack/push_commands.c \
	sources/stack/push_swap.c \
	sources/stack/push_swap_init.c \
	sources/stack/reverse_rotate.c \
	sources/stack/rotate_commands.c \
	sources/stack/sorts.c \
	sources/stack/stack_init.c \
	sources/stack/stack_utils.c \
	sources/stack/swap_commands.c \
	sources/utils/error_free.c \
	sources/utils/ft_split_ps.c

OBJ = $(SRC:.c=.o)

COMPILER = cc

FLAGS = -Wall -Wextra -Werror

.c.o:
	@ echo "$(BLUE)Compiling $<...$(WHITE)"
	@ $(COMPILER) $(FLAGS) -Iincludes -c $< -o $@

all: $(NAME)

$(NAME): $(ARCHIVE)
	$(COMPILER) $< -o $@

$(ARCHIVE): $(OBJ)
	@ echo "$(YELLOW)Linking...$(WHITE)"
	@ ar -rcs $(ARCHIVE) $^
	@ echo "$(GREEN)Compile complete!\n$(WHITE)"

bonus:
	@ echo "$(YELLOW)Initializing checker...$(WHITE)"
	@ cd ../checker && make

clean:
	@ echo "$(RED)Cleaning objects...$(WHITE)"
	@ rm -f $(OBJ) $(ARCHIVE)

fclean: clean
	@ echo "$(RED)Cleaning $(NAME)...$(WHITE)"
	@ rm -f $(NAME)
	#@ cd ../checker && make fclean

re: fclean all

.PHONY: all clean fclean re bonus
