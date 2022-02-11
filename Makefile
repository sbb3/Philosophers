# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adouib <adouib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 14:20:22 by adouib            #+#    #+#              #
#    Updated: 2022/02/11 17:31:23 by adouib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I./incl/
# -g3 -fsanitize=address
RM = rm -rf

SRCS = ./srcs/main.c \
		./srcs/parser.c \
		./srcs/alloc.c \
		./srcs/init.c \
		./srcs/philosopher.c \
		./srcs/time.c \
		./srcs/utils.c \
		./srcs/watcher.c

OBJS = $(SRCS:%.c=%.o)

NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -pthread -o $(NAME)

./srcs/%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
