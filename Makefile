NAME = philo

SRC = $(wildcard src/*.c)\

INCLUDES = includes

OBJ = $(SRC:.c=.o)

CFLAGS = -pthread -Wall -Wextra -Werror

CC = gcc

$(RM) = rm -rf

.c.o: $(SRC)
	$(CC) $(CFLAGS) -I $(INCLUDES) -c -o $@ $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: $(NAME) all clean fclean re