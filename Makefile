# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rramirez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/28 01:09:45 by rramirez          #+#    #+#              #
#    Updated: 2017/06/01 22:50:21 by rramirez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

CC		=	gcc -Wall -Wextra -Werror

SRCS	= 	mlx_main.c\

OBJ 	=	${SRCS:.c=.o}

INCLUDE = -I fdf.h -I minilibx

LIBS = -L libft/ -lft -L minilibx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(OBJ):
	$(CC) $(INCLUDE) -c $(SRCS)

$(NAME): $(OBJ)
	@make all -C libft
	$(CC) $(OBJ) $(LIBS) -g -o $(NAME)

clean:
	@make clean -C libft
	@/bin/rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
