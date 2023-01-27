NAME = philo

CFLAGS			= -Wall -Wextra -Werror
LIBS			= -pthread
SRCS = ph1.c \
		init.c \
		exit_n_error.c \
		eat.c \
		utils.c \
		check.c
OBJS = $(SRCS:.c=.o)
all: $(NAME)

$(NAME):		$(OBJS)
				gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all