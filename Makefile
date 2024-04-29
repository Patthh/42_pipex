# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/06 12:44:17 by pracksaw          #+#    #+#              #
#    Updated: 2024/04/29 16:54:26 by pracksaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRCS = error.c  exec.c  main.c \
 pipe.c  utils.c  utils2.c  utils3.c
OBJS  = $(SRCS:.c=.o)

CC = cc
CFLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAG) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER_FILE)
		$(CC) -c $(CFLAG) $^ -o $@

clean:
	rm -f $(OBJS)

fclean:clean
	rm -f $(NAME)

norm :
	norminette

valgrind : $(NAME)
	valgrind --track-fds=yes --tool=memcheck --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME)
re: fclean all

.PHONY: all clean fclean re