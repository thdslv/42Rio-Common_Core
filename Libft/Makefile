# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thda-sil <thda-sil@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 21:46:22 by thda-sil          #+#    #+#              #
#    Updated: 2024/02/29 18:56:22 by thda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
MAKEFLAGS += --silent

NAME = libft.a

SRC = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \

OBJ = $(SRC:.c=.o)

BONUS = ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \

BONUS_OBJ = $(BONUS:.c=.o)

FLAGS = -Wall -Wextra -Werror

.c.o:
	cc $(FLAGS) -I . -c $< -o $@
	printf "compiling $<     \r"

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	printf "\ncompile success!\n"

all: $(NAME)

clean: 
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJ) $(BONUS_OBJ)
	ar rc $(NAME) $(OBJ) $(BONUS_OBJ)

.PHONY: all clean fclean re bonus
