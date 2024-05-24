# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julessainthorant <marvin@42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 20:15:54 by julessainthor     #+#    #+#              #
#    Updated: 2024/05/23 17:35:57 by jsaintho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a
SRC = ft_printf.c utils.c
HEADER_DIR = ./

OBJ = ${SRC:.c=.o}

.c.o:
	gcc -Wall -Wall -Wextra -I $(HEADER_DIR) -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
	ar -rsc $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus
