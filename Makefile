FILES = compute_dict.c parse_dict.c str_manipulation.c str_comparison.c printing.c translate_number.c check_arg.c initialize_num_conf.c

OBJS = ${FILES:.c=.o}

HEADERS = check_arg.h compute_dict.h parse_dict.h printing.h str_comparison.h str_manipulation.h translate_number.h initialize_num_conf.h

NAME = rush-02

CC = gcc
RM = rm -f
LIB = ar rc

CFLAGS = -Werror -Wall -Wextra

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${LIB} libstr.a ${OBJS} ${HEADERS}
	${CC} -g -o ${NAME} ${CFLAGS} main.c -L. -lstr

all :
	${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re



