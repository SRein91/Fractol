# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 16:30:14 by sreinhol          #+#    #+#              #
#    Updated: 2022/01/17 16:52:56 by sreinhol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit -o

SRC = main.c atod.c fractols.c helpers.c hooks.c input.c

GREEN := \033[0;32m
YELLOW := \033[1;33m
RED := \033[1;31m
DEFAULT := \033[0m

all: objects

objects:
	@make -C ./mlx
	@$(CC) $(FLAGS) $(NAME) $(SRC)
	@echo "\n$(GREEN)$(NAME) created$(DEFAULT)"

clean:
	@rm -f *.o
	@echo "\n$(YELLOW)object files deleted!$(DEFAULT)"

fclean: clean
	@rm -f $(NAME)
	@echo "\n$(RED)all deleted!$(DEFAULT)"

re: fclean all

bonus: objects
