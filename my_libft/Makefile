# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 21:46:22 by thda-sil          #+#    #+#              #
#    Updated: 2024/03/13 17:01:51 by thda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

NAME = libft.a

SRC = is/ft_isalnum.c \
	is/ft_isalpha.c \
	is/ft_isascii.c \
	is/ft_isdigit.c \
	is/ft_islower.c \
	is/ft_isprint.c \
	is/ft_isspace.c \
	is/ft_isupper.c \
	list/ft_lstadd_back.c \
	list/ft_lstadd_front.c \
	list/ft_lstclear.c \
	list/ft_lstdelone.c \
	list/ft_lstiter.c \
	list/ft_lstlast.c \
	list/ft_lstmap.c \
	list/ft_lstnew.c \
	list/ft_lstsize.c \
	matrix/ft_free_matrix.c \
	matrix/ft_matrix_len.c \
	mem/ft_bzero.c \
	mem/ft_calloc.c \
	mem/ft_memchr.c \
	mem/ft_memcmp.c \
	mem/ft_memcpy.c \
	mem/ft_memmove.c \
	mem/ft_memset.c \
	num/ft_atoi.c \
	print/ft_printf.c \
	print/ft_putchar.c \
	print/ft_putchar_fd.c \
	print/ft_putendl.c \
	print/ft_putendl_fd.c \
	print/ft_putnbr.c \
	print/ft_putnbr_base.c \
	print/ft_putnbr_fd.c \
	print/ft_putptr.c \
	print/ft_putstr.c \
	print/ft_putstr_fd.c \
	str/ft_itoa.c \
	str/ft_split.c \
	str/ft_strchr.c \
	str/ft_strdup.c \
	str/ft_striteri.c \
	str/ft_strjoin.c \
	str/ft_strjoin_free.c \
	str/ft_strjoin_gnl.c \
	str/ft_strlcat.c \
	str/ft_strlcpy.c \
	str/ft_strlen.c \
	str/ft_strmapi.c \
	str/ft_strncmp.c \
	str/ft_strnstr.c \
	str/ft_strrchr.c \
	str/ft_strtrim.c \
	str/ft_substr.c \
	str/get_next_line.c \
	to/ft_tolower.c \
	to/ft_toupper.c \

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

.c.o:
	cc $(FLAGS) -I includes -c $< -o $@
	printf "compiling $<     \r"

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	printf "\ncompile success!\n"

all: $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
