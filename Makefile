# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 21:40:56 by lykalon           #+#    #+#              #
#    Updated: 2022/06/22 21:40:56 by lykalon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
#
SRCS =	events.c ft_itoa.c ft_memset.c \
		ft_strdup.c ft_strjoin.c get_next_line.c \
		get_next_line_utils.c in_game_score.c init_game.c \
		init_map.c map_builder.c map_checker.c \
		map_checker_extension.c moving_player.c so_long.c \
		window_render.c
#
HEADER = so_long.h
OBJ = $(patsubst %.c, %.o, $(SRCS))
#
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(HEADER)
MLXFLAG = -lmlx -framework OpenGL -framework AppKit
#
.PHONY : all clean fclean re bonus
#
all : $(NAME)
#
$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(MLXFLAG) $(OBJ) -o $@
#
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
#
clean :
	rm -f $(OBJ) $(OBJ_B)
#
fclean : clean
	$(RM) $(NAME) $(NAME_B)
#
re : fclean all