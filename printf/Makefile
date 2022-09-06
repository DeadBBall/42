# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonggkim <yonggkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 21:11:46 by yonggkim          #+#    #+#              #
#    Updated: 2022/09/05 18:54:21 by yonggkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -c

NAME					= libftprintf.a

SRCS					= ft_printf.c print_csdi.c ft_itoa.c ft_uitoa.c print_pux.c

LIBC_OBJS					= $(SRCS:.c=.o)

OBJS = $(LIBC_OBJS)

all :	$(NAME)

$(NAME) :	$(OBJS)
	ar rc $@ $(OBJS)
%o : %c
	$(CC) $(CFLAGS) $< -o $@ -I./

clean :
	rm -f $(OBJS)

fclean :	clean
	rm -f $(NAME)

re :	fclean all

.PHONY :	all clean fclean re
