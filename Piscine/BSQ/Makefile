# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 15:57:39 by dogpark           #+#    #+#              #
#    Updated: 2022/10/20 11:21:27 by dogpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = srcs
INCDIR = includes
NAME = bsq
SRCS = $(SRCDIR)/allocation.c $(SRCDIR)/compare.c $(SRCDIR)/main.c $(SRCDIR)/parsing.c $(SRCDIR)/print.c $(SRCDIR)/square.c $(SRCDIR)/string.c $(SRCDIR)/validate.c $(SRCDIR)/standard_input.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
