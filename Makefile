YELLOW	:= $(shell tput -Txterm setaf 3)
GREEN	:= $(shell tput -Txterm setaf 2)
RED		:= $(shell tput -Txterm setaf 1)
RESET	:= $(shell tput -Txterm sgr0)

NAME	= philo

OBJS	= ${SRCS:.c=.o}
SRC		= act.c check_arg.c init.c main.c philo_utils.c start.c
SRCS	= ${addprefix src/, ${SRC}}

CFLAGS	= -pthread -Wall -Wextra -Werror
CC		= gcc


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "${YELLOW}Compiling [%s]...%-42s${RESET}\r" $<

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "\n${GREEN}Finished : $(NAME)${RESET}"

all:	${NAME}

clean:
		@rm -rf ${OBJS}
		@echo "${RED}Removing objects...${RESET}"

fclean:	clean
		@rm -rf ${NAME}
		@echo "${RED}Removing ${NAME}...${RESET}"

re:		fclean all

.PHONY : all clean fclean re