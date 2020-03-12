# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/04 15:13:52 by sjiseong          #+#    #+#              #
#    Updated: 2020/03/11 16:04:57 by sjiseong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c format.c get_option.c printf_integer.c printf_double.c printf_pointer.c util.c

SRC_PATH = src/

SRC_POS = $(addprefix $(SRC_PATH), $(SRC))

OBJ = $(SRC:.c=.o)

INC = includes/

CC = gcc

FLAG = -Wall -Wextra -Werror

LIBFT = libft/libft.a

LIBFTO = libft/*.o

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	ar rc $(NAME) $(OBJ) $(LIBFTO)
	ranlib $(NAME)

try: $(LIBFT)
	$(CC) -I $(INC) -o test $(SRC_POS) $(LIBFT)

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
