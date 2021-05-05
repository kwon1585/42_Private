CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = crv
SRCS_DIR = ./srcs
SRCS = ft_putchar.c	\
	   ft_swap.c \
	   ft_putstr.c \
	   ft_strlen.c \
	   ft_strcmp.c
OBJS = $(addprefix $(SRCS_DIR)/, $(SRCS:.c=.o))
HEAD_DIR = ./includes
HEAD = ft.h
TARGET = libft.a

all : $(TARGET)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all

$(TARGET) : $(addprefix $(HEAD_DIR)/, $(HEAD)) $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

.c.o : 
	$(CC) $(CFLAGS) -I$(HEAD_DIR) -c $< -o $(<:.c=.o)
