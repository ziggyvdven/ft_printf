# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zvandeven <zvandeven@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 11:22:03 by zvandeven         #+#    #+#              #
#    Updated: 2023/02/23 11:37:29 by zvandeven        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libftprintf.a
OBJS 	= $(SRCS:.c=.o)
CC	 	= gcc
CFLAGS 	= -Wall -Wextra -Werror -g
RM		= rm -f
SRCS	= ft_printf.c \


.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:		flcean all clean re
	
