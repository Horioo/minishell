# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajorge-p <ajorge-p@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 12:32:15 by luiberna          #+#    #+#              #
#    Updated: 2024/07/04 17:23:05 by ajorge-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

#Atualizado as SRCS - Artur
SRCS = env.c exec.c free.c init.c minishell.c parsing.c pipes.c redirect.c builtins.c builtins/cd.c builtins/echo.c builtins/env.c builtins/exit.c builtins/export.c builtins/pwd.c builtins/unset.c
 
CC = cc

OBJS = $(SRCS:.c=.o)

INCLUDE = ./Includes/

CFLAGS = -I$(INCLUDE) -g #-Wall -Wextra -Werror 

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./Libft
	$(CC) $(CFLAGS) $(OBJS) ./Libft/libft.a -o $(NAME) -lreadline

clean:
	make clean -C ./Libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./Libft
	rm -f $(NAME)

re: fclean $(NAME)

r: 
	make re && ./fdf 

.PHONY: all clean fclean re


