NAME	= philo

OBJS	= ${SRCS:.c=.o}
SRCS	= ${addprefix src/, ${SRC}}
SRC		= act.c check_arg.c init.c main.c philo_utils.c start.c

CFLAGS	= -pthread -Wall -Wextra -Werror
CC		= gcc


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

all:	${NAME}

clean:
		rm -rf ${OBJS}

fclean:	clean
		rm -rf ${NAME}

re:		fclean all

.PHONY : all clean fclean re
