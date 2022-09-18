NAME =		gameoflife

CC =		gcc

RM =		rm -f

SRCS =		$(addprefix src/,	grid_operation.c \
								display.c \
								is_alive.c \
								main.c)

OBJS =		${SRCS:.c=.o}

CFLAGS =	-Werror -Wextra -Wall -std=c99 -O0 -g

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -Iinclude/ -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} $$(sdl2-config --cflags --libs)

clean:
	${RM} ${OBJS} ${OBJSBONUS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

