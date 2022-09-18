# Makefile

CC = gcc -fsanitize=address
CPPFLAGS = -MMD
CFLAGS = -Wall -Wextra -std=c99 -O0 -g
LDFLAGS =
LDLIBS =

OBJ = grid_operation.o is_alive.o
DEP = ${OBJ:.o=.d}

all: main

main: ${OBJ}

clean:
	${RM} ${OBJ} 
	${RM} ${DEP} 
	${RM} *.d 
	${RM} main

-include ${DEP}

# END
