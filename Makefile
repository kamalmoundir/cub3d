# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/31 11:43:06 by kmoundir          #+#    #+#              #
#    Updated: 2025/05/01 18:16:15 by kmoundir         ###   ########.fr        #
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
		src/get_next_line/data_to_array.c\
		src/parser/parse_extract_map_grid/map_parser.c\
		src/parser/parse_extract_map_grid/validate_map.c \
		src/parser/parse_extract_config/texture_parser.c\
		src/parser/parse_extract_config/textures_utils.c\
		src/parser/parse_extract_config/extract_config.c\
		src/util/validate_utils.c\
		src/util/memory_utils.c\
		src/parser/parse_extract_map_grid/extract_grid.c\
		src/util/free_struct.c \
		src/util/validate_input.c\
		src/app/init_structs_default_val.c\
		src/main.c 


OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: libmlx $(NAME)

libmlx:
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJS) libft 
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