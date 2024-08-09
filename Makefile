# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 21:25:26 by hskrzypi          #+#    #+#              #
#    Updated: 2024/08/09 21:25:01 by hskrzypi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

LIBFTDIR	= ~/complete_Libft

LIBFT	= ${LIBFTDIR}/libft.a

INCLUDES	= -I ${LIBFTDIR}

SRCS	= input_checks.c list_utils.c sort_utils.c stack_a_utils.c stack_b_utils.c init_sorting.c swap.c rotate.c rev_rotate.c push.c main2.c

HEAD	= push_swap.h

OBJS	= ${SRCS:.c=.o}

CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

all:	${NAME}

.c.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

${NAME}: ${OBJS} ${LIBFT}
	@cc ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}

${LIBFT}:
	${MAKE} -C ${LIBFTDIR}
clean:
	${RM} ${OBJS}
	@${MAKE} -C ${LIBFTDIR} clean

fclean: clean
	${RM} ${NAME}
	@${MAKE} -C ${LIBFTDIR} fclean

re:	fclean all

.PHONY:	all clean fclean re
