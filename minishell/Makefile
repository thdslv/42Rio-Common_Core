# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 17:47:09 by thda-sil          #+#    #+#              #
#    Updated: 2024/08/08 18:30:33 by thda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

COMPILER = cc

FLAGS = -Wall -Wextra -Werror

SRC = 

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): 

clean:
	@ make clean -C $()
	@ rm -f $(OBJ)
	@ echo "Cleaning objects"

fclean:
	@ make fclean -C $()
	@ rm -f $(NAME)
	@ echo "Cleaning executable"

re: fclean all

.PHONY: all clean fclean re
