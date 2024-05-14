# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfaria-p <mfaria-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 19:27:32 by mfaria-p          #+#    #+#              #
#    Updated: 2024/05/14 12:08:14 by mfaria-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c \
       srcs/utils.c \
       srcs/init_all.c \
       srcs/monitor_routine.c \
       srcs/philo_routine.c \
       srcs/threads.c \
       srcs/time.c \

OBJS = $(SRCS:.c=.o)

NAME = philosophers
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJS)
	$(CC) $(CFLAGS)  $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all