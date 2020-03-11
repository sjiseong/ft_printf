# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjiseong <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/18 21:18:59 by sjiseong          #+#    #+#              #
#    Updated: 2020/02/23 21:46:42 by sjiseong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -c *.c
		ar rc $(NAME) *.o
		ranlib $(NAME)

clean:
		rm -f *.o
fclean: clean
		rm -f $(NAME)
re:	fclean all
