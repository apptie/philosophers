# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jimikim <jimikim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 19:42:02 by jimikim           #+#    #+#              #
#    Updated: 2021/07/15 11:50:44 by jimikim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = ./header
SRCS = ./libft/ft_atoi.c \
       ./libft/ft_isdigit.c \
       ./libft/ft_strcpy.c \
       ./libft/ft_strlen.c \
       ./libft/ft_strncmp.c \
	   ./libft/ft_putstr_fd.c \
       ./utils/ft_utils_etc.c \
       ./utils/ft_utils_free.c \
       ./utils/ft_utils_init.c \
       ./utils/ft_utils_philo.c \
       ./utils/ft_utils_process.c \
       ./utils/ft_utils_sem.c \
       ./utils/ft_utils_set.c \
       ./utils/ft_utils_thread.c \
       ./utils/ft_utils_valid.c \
       ./philo_bonus.c
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lpthread

%.o : %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $^ -o $@

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(NAME)

re :
	make fclean
	make all

.PHONY :
	all
	clean
	fclean
	re
