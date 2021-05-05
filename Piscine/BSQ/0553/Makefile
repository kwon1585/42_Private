# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dongkim <dongkim@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/17 12:18:54 by dongkim           #+#    #+#              #
#    Updated: 2021/03/18 06:14:49 by dokwon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = BSQ
SDIR = srcs
SRCS = $(addprefix srcs/, ft_lib.c ft_str.c main.c ft_map.c ft_map2.c ft_error.c)
OBJS = $(SRCS:.c=.o)
INCDIR = includes

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) -I $(INCDIR) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
