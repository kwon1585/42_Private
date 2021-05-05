CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = do_op.c \
	   operate.c \
	   ft_atoi.c
SRC_DIR = ./srcs
OBJS = $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o))

TARGET = do-op

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
