# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonggkim <yonggkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 17:36:50 by yonggkim          #+#    #+#              #
#    Updated: 2022/08/06 16:10:47 by yonggkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -c

NAME					= libft.a

SRCS					= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
								ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
								ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
								ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
								ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
								ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
								ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_striteri.c \

BNS_SRCS				= ft_lstsize.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
									ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c \

LIBC_OBJS					= $(SRCS:.c=.o)

BNS_OBJS				= $(BNS_SRCS:.c=.o)

ifdef WITH_BONUS
    OBJS = $(LIBC_OBJS) $(BNS_OBJS)
else
    OBJS = $(LIBC_OBJS)
endif

all :	$(NAME)

bonus :
	make WITH_BONUS=42 all

$(NAME) :	$(OBJS)
	ar rc $@ $(OBJS)
%o : %c
	$(CC) $(CFLAGS) $< -o $@ -I./

clean :
	rm -f $(OBJS) $(BNS_OBJS)

fclean :	clean
	rm -f $(NAME)

re :	fclean all

.PHONY :	all bonus clean fclean re
