# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akanbari <akanbari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 18:29:36 by akanbari          #+#    #+#              #
#    Updated: 2023/12/28 23:16:30 by akanbari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =  src/easy_sort.c \
		src/index.c \
		src/lists.c \
		src/push_swap.c \
		src/radix.c \
		src/utilities.c \
		src/ft_atol_p.c \
		src/checkers.c \
		src/clear.c \
		src/push.c \
		src/rotate.c \
		src/swap.c \
		src/reverse_rotate.c \

OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@${MAKE} -C ./ft_libft
	@${CC} ${CFLAGS} ${OBJS} ./ft_libft/libft.a -o ${NAME}

clean: 
	@${MAKE} -C ./ft_libft fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re