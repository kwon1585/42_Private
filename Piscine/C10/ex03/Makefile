CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = hexdump.c \
	   print.c \
	   print2.c \
	   buff.c
SRC_DIR = ./srcs
OBJS = $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o))
TARGET = ft_hexdump

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
