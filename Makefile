# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 11:22:03 by zvandeven         #+#    #+#              #
#    Updated: 2023/02/24 17:19:47 by zvan-de-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libftprintf.a
OBJS 	= $(SRCS:.c=.o)
CC	 	= gcc
CFLAGS 	= -Wall -Wextra -Werror -g
RM		= rm -f
SRCS	= ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c\
ft_strlen.c ft_putunsign.c ft_putnbr_base.c\


all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

main: $(NAME) main.c
	$(CC) $(CFLAGS) -lftprintf -L. -o $@ main.c

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:		all bonus clean fclean re
