# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 13:36:18 by lmaujean          #+#    #+#              #
#    Updated: 2021/04/14 11:28:50 by lmaujean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		= libftprintf.a

HEADER_FILE = header/ft_printf.h

FOLDER		= src/

SRCS		= ft_printf.c\
       ft_printf_util.c\
	   ft_printf_util2.c\

SRC			= $(addprefix ${FOLDER},${SRCS})

OBJS		= ${SRC:.c=.o}

LIBFT		= cd libft/ && make

CC			= gcc
CFLAGS  	= -Wall -Wextra -Werror
RM			= rm -f
AR			= ar -rcs

$(NAME):	libft ${OBJS}
			${AR} ${NAME} ${OBJS} 

all:		${NAME}

%.o: %.c	
			$(CC) -c $(CFLAGS) -I $(HEADER_FILE) -o $@ $<

clean:
			${RM} ${OBJS}
			${LIBFT} clean

fclean:		clean
			rm $(NAME)
			${LIBFT} fclean

re:			fclean all

libft:		
			${LIBFT}
			cp libft/libft.a $(NAME)

.PHONY:		all clean fclean re libft