NAME	= philo

OBJ		= ${SRCS:.c=.o}
SRCS	= $(wildcard src/*.c)\


$(NAME): $(OBJ)
		gcc $(OBJ) -Wall -Werror -Wextra -o $(NAME)

all: $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all