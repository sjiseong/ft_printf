# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/04 15:13:52 by sjiseong          #+#    #+#              #
#    Updated: 2020/03/11 00:11:56 by sjiseong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

SRC = ft_printf.c format.c get_option.c printf_integer.c printf_double.c util.c

SRC_PATH = src/

SRC_POS = $(addprefix $(SRC_PATH), $(SRC))

OBJ = $(SRC:.c=.o)

INC = includes/

CC = gcc

FLAG = -Wall -Wextra -Werror

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAG) -o $(NAME) $(OBJ) $(LIBFT)

try: $(LIBFT)
	$(CC) -I $(INC) -o $(NAME) $(SRC_POS) $(LIBFT)

$(OBJ): $(LIBFT)
	$(CC) $(FLAG) -I $(INC) -c $(SRC_POS)

$(LIBFT):
	make -C libft/ fclean && make -C libft/

clean:
	rm -f *.o
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
