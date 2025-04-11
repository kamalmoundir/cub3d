# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/31 11:43:06 by kmoundir          #+#    #+#              #
#    Updated: 2025/04/01 14:15:04 by kmoundir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
SRCDIR = ./src
OBJDIR = ./obj
LIBDIR_LIBFT = ./library/libft
LIBMLX = ./library/MLX42
INCLUDES = -I./include  -I./library/libft -I./library/MLX42/include
MLX42_FLAGS = $(LIBMLX)/build/libmlx42.a -Iinclude $(pkg-config --libs glfw3)

SRCS = src/get_next_line/get_next_line.c \
		src/get_next_line/get_next_line_utils.c \
		 src/main.c src/parser/map_parser.c

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: libmlx $(NAME)

libmlx:
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJS) libft ./include/cub3d.h
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(MLX42_FLAGS)  -L$(LIBDIR_LIBFT)  $(shell pkg-config --libs glfw3) -lft -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

-include $(OBJDIR)/*.d

libft:
	@make -C $(LIBDIR_LIBFT)

clean:
	rm -rf $(OBJDIR)
	@make -C $(LIBDIR_LIBFT) clean
	rm -rf $(LIBMLX)/build

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBDIR_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re libft