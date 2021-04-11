# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/11 13:46:29 by keokim            #+#    #+#              #
#    Updated: 2021/04/11 13:58:23 by keokim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = rush-02
SRCS = *.c
OBJS = $(SRCS:.c=.o)
INCS = rush.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(TARGET)

.c.o :
		$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS)

$(TARGET) : $(OBJS)
		$(CC) $(CFLAGS) -o $@ $^

clean :
		rm -f $(OBJS)

fclean :
		rm -f $(TARGET)

re : fclean all
