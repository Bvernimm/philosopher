NAME	= philo

OBJ		= ${SRCS:.c=.o}
SRCS	= $(wildcard src/*.c)\

CFLAGS = -pthread -Wall -Wextra -Werror
CC = gcc

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all