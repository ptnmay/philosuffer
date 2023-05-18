# # **************************************************************************** #
# #                                                                              #
# #                                                         :::      ::::::::    #
# #    Makefile                                           :+:      :+:    :+:    #
# #                                                     +:+ +:+         +:+      #
# #    By: psaeyang <marvin@42.fr>                    +#+  +:+       +#+         #
# #                                                 +#+#+#+#+#+   +#+            #
# #    Created: 2023/05/04 02:05:56 by psaeyang          #+#    #+#              #
# #    Updated: 2023/05/17 18:33:01 by psaeyang         ###   ########.fr        #
# #                                                                              #
# # **************************************************************************** #

NAME	= philo

CC		= gcc
RM		= rm -f
C_FLAGS	= -Wall -Wextra -Werror -pthread -O3 -g #-fsanitize=address

SRCS	= philo.c verify_error.c utils.c set_up.c time.c routine.c

OBJS	= $(SRCS:.c=.o)

%.o:%.c
	$(CC) $(C_FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(C_FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

# NAME = philo

# SRC = philo.c verify_error.c utils.c set_up.c time.c routine.c

# OBJ = $(SRC:.c=.o)

# CC = cc

# CFLAGS = -Wall -Werror -Wextra -pthread -O3 # -g -fsanitize=address

# all: $(NAME)

# $(NAME): $(OBJ)
# 	$(CC) $(CFLAGS) $^ -o $@

# clean:
# 	rm -f $(OBJ)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re