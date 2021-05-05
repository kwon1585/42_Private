CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = cat.c
SRC_DIR = ./srcs
OBJS = $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o))
TARGET = ft_cat

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all

$(SRC_DIR)/%.o : %.c
	$(CC) $(CFLAGS) -c $^
