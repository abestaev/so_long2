# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albestae <albestae@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 03:53:40 by albestae          #+#    #+#              #
#    Updated: 2024/01/21 16:58:47 by albestae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wextra -Wall -Werror
NAME = so_long 
SRC = src/utils.c src/key_hook.c src/move.c src/move_utils.c \
      	so_long.c src/draw_map.c src/check_map.c src/error.c src/init.c \
		src/exit.c src/flood_fill.c	
HEADER = -I include -I libft -I minilibX
LIBFT = -L libft -lft
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft/
		make -C minilibX/
		$(CC) $(CFLAGS) -o $(NAME) $(HEADER) $(SRC) -g -L minilibX/ $(LIBFT) -lmlx -lXext -lX11

%.o: %.c
	$(CC) $(CFLAGS) $(HEADER) -c -o $@ $<
	
clean:
		make clean -C libft
		make clean -C minilibX
		rm -rf $(OBJ)

fclean: clean
		make fclean -C libft
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
