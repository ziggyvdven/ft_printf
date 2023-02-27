# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 11:22:03 by zvandeven         #+#    #+#              #
#    Updated: 2023/02/27 16:58:27 by zvan-de-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libftprintf.a
OBJS 	= $(addprefix $(BINDIR), $(SRCS:.c=.o))
CC	 	= gcc
CFLAGS 	= -Wall -Wextra -Werror -g
RM		= rm -f
BINDIR	= bin/
SRCS	= ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c\
ft_strlen.c ft_putunsign.c ft_putnbr_base.c ft_printadr.c\


all: $(NAME)

$(BINDIR)%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(BINDIR) $(OBJS)
	ar rc $(NAME) $(OBJS)

$(BINDIR) :
	mkdir $(BINDIR)

main: $(NAME) main.c
	$(CC) $(CFLAGS) -lftprintf -L. -o $@ main.c

clean:
	$(RM) $(OBJS)
	$(RM) -r $(BINDIR)

fclean: clean
	$(RM) $(NAME) main

re: fclean all

.PHONY:		all bonus clean fclean re
