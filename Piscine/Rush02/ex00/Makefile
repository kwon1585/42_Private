CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = ./srcs
SRCS = main.c \
	   print.c \
	   get.c \
	   three.c \
	   check.c \
	   str.c
OBJS = $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o))

TARGET = rush-02

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

