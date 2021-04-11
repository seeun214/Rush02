# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/11 13:46:29 by keokim            #+#    #+#              #
#    Updated: 2021/04/11 22:01:34 by keokim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = rush-02
SRCS = convert.c ft_open_read.c ft_str.c main.c rush.c unique_num.c valid.c ft_write.c
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

fclean : clean
		rm -f $(TARGET)

re : fclean all
