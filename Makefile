# -----------------------------VARS------------------------------
NAME	= libftprintf.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

LIBA	= ar rcs

#---------------------------SOURCE FILES--------------------------

SRCS		= ft_printf.c \
				ft_printf_util.c \
				ft_putaddress.c \
				ft_putnbr_base.c \

OBJS		= $(addprefix srcs/, ${SRCS:.c=.o})

#---------------------------RULES--------------------------------

.c.o:
			${CC} ${CFLAGS} -c -I./includes $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${LIBA} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBJS2}
fclean:		clean
			${RM} ${NAME}

re:			fclean all

#----------------------------PHONY---------------------------------

.PHONY:		all clean fclean re