# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 14:46:54 by thda-sil          #+#    #+#              #
#    Updated: 2024/05/21 21:28:40 by thda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

SRC = server.c client.c

OBJ = $(SRC:.c=.o)

BONUS_SRC = server_bonus.c client_bonus.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

.c.o:
	cc $(FLAGS) -I . -c $< -o $@

all: $(NAME)

libft/libft.a:
	make -C libft

server: server.o
	cc $(FLAGS) -o server server.o libft/libft.a

server_bonus: server_bonus.o
	cc $(FLAGS) -o server_bonus server_bonus.o libft/libft.a

client: client.o
	cc $(FLAGS) -o client client.o libft/libft.a

client_bonus: client_bonus.o
	cc $(FLAGS) -o client_bonus client_bonus.o libft/libft.a

$(NAME): $(OBJ) libft/libft.a server client

bonus: $(BONUS_OBJ) libft/libft.a server_bonus client_bonus

clean:
		make -C libft clean
		rm -rf $(OBJ)

fclean: clean
		make -C libft fclean
		rm -rf $(NAME) $(OBJ) $(BONUS_OBJ) server client server_bonus client_bonus

re: clean fclean

.PHONY: all clean fclean re bonus
