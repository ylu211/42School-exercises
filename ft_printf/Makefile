# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylam <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/28 15:26:04 by ylam              #+#    #+#              #
#    Updated: 2022/02/05 16:25:26 by ylam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/

SRCS =  ft_printf.c \
				ifchar.c \
				ifstr.c \
				ifpointer.c \
				ifdcm.c \
				ifunsigned.c \
				ifpointer.c \
				ifhex.c \
				ifpercent.c \

OBJS = $(SRCS:.c=.o)

CC = gcc

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
