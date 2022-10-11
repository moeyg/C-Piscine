# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 08:53:58 by dogpark           #+#    #+#              #
#    Updated: 2022/10/18 12:36:17 by dogpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
INC = ./includes/
DIR = ./srcs/
HEADER  = $(INC)ft.h
SRCS = $(DIR)ft_putchar.c $(DIR)ft_swap.c $(DIR)ft_putstr.c $(DIR)ft_strlen.c $(DIR)ft_strcmp.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

.c.o :
	$(CC) $(CFLAG) -c $< -I $(INC) -o $@

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(NAME)

re :	fclean all
