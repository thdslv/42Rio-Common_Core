# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 12:05:32 by thda-sil          #+#    #+#              #
#    Updated: 2023/11/23 23:30:48 by thda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_functions.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

.c.o:
	cc $(FLAGS) -I . -c $< -o $@

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

exec: re 
	cc $(NAME) && make fclean
	clear
	./a.out 

re: fclean all

.PHONY: all clean fclean re
