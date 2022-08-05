# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamchur <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 17:33:54 by hamchur           #+#    #+#              #
#    Updated: 2022/01/25 17:34:05 by hamchur          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT = libft
MLX = minilibx_macos

HEADER = includes/fdf.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
	  sources/draw.c \
	  sources/threed.c \
	  sources/map_fill.c \
	  sources/map_init.c \
	  sources/mlx_global_init.c

OBJ = $(SRC:.c=.o)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I/usr/include -I$(MLX) -O3 -c $< -o $@

all: lib $(NAME)

lib:
	make -C $(LIBFT)
	make -C $(MLX)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a minilibx_macos/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)

clean:
	make clean -C $(LIBFT)
	make clean -C $(MLX)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(LIBFT)
	make fclean -C $(MLX)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
