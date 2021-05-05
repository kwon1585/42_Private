CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = display_file.c
SRC_DIR = ./srcs
OBJS = $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o))
TARGET = ft_display_file

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
