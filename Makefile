###	Variables
NAME					=	cub3d
TEST_EXEC				=	test_runner
LIBFT 					=	lib/libft
MINILIBX				=	lib/minilibx-linux
INCLUDES				=	./include
MAKEFLAGS				+=	--no-print-directory

###	Source files specs
#	dirs
SRC_DIR					=	src

#	files
SRC						=	$(SRC_DIR)/app/main_update.c							\
							$(SRC_DIR)/app/clean_central.c							\
							$(SRC_DIR)/app/init_game.c								\
							$(SRC_DIR)/app/input.c									\
							$(SRC_DIR)/app/init_struct_data_extract.c				\
							$(SRC_DIR)/app/init_structs_default_val.c				\
							$(SRC_DIR)/init/game_init.c								\
							$(SRC_DIR)/debug/game_debug.c								\
							$(SRC_DIR)/player/init_player.c							\
							$(SRC_DIR)/player/player_update.c						\
							$(SRC_DIR)/player/player_movement.c						\
							$(SRC_DIR)/player/player_collision.c					\
							$(SRC_DIR)/raycasting_engine/ray_setup.c				\
							$(SRC_DIR)/raycasting_engine/raycasting_dda.c			\
							$(SRC_DIR)/raycasting_engine/raycasting_utils.c			\
							$(SRC_DIR)/render/render_buffer.c						\
							$(SRC_DIR)/render/render_core.c							\
							$(SRC_DIR)/render/render_walls.c						\
							$(SRC_DIR)/render/render_utils.c						\
							$(SRC_DIR)/render/load_images.c							\
							$(SRC_DIR)/utils/memory_utils.c							\
							$(SRC_DIR)/utils/misc_utils.c							\
							$(SRC_DIR)/utils/debug_utils.c							\
							$(SRC_DIR)/utils/error_utils.c							\
							$(SRC_DIR)/get_next_line/get_next_line.c				\
							$(SRC_DIR)/get_next_line/get_next_line_utils.c			\
							$(SRC_DIR)/get_next_line/data_to_array.c				\
							$(SRC_DIR)/parser/file_parser.c							\
							$(SRC_DIR)/parser/parse_extract_map_grid/extract_grid.c	\
							$(SRC_DIR)/parser/parse_extract_map_grid/map_parser.c	\
							$(SRC_DIR)/parser/parse_extract_map_grid/validate_map.c \
							$(SRC_DIR)/parser/parse_extract_map_grid/functions_map_helper.c \
							$(SRC_DIR)/parser/parse_extract_config/texture_parser.c	\
							$(SRC_DIR)/parser/parse_extract_config/textures_utils.c	\
							$(SRC_DIR)/parser/parse_extract_config/extract_config.c	\
							$(SRC_DIR)/util/validate_utils.c						\
							$(SRC_DIR)/util/free_struct.c							\
							$(SRC_DIR)/util/validate_input.c


TOTAL_SRC_FILES			:=	$(words $(SRC))

### Object files specs
#	dirs
OBJ_DIR					=	obj

#	files
OBJ						=	$(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRC:.c=.o))

###	Compilation/ Linking configs
CC						=	cc
CFLAGS					=	-Werror -Wextra -Wall # -fsanitize=address
LDFLAGS					=	-lreadline -L$(LIBFT) -L$(MINILIBX) -L/usr/lib -lft -lmlx_Linux -lXext -lX11 -lm -lz
RM						=	rm -rf
COUNT					:=	0

###	</Testing set-up
TEST_DIR				=	tests
TEST_SRC_DIR			=	$(TEST_DIR)/src
TEST_OBJ_DIR			=	$(TEST_DIR)/obj
TEST_SRC				= 	$(TEST_SRC_DIR)/test_parser.c
TEST_OBJ				=	$(filter-out $(OBJ_DIR)/app/%, $(OBJ))							\
							$(patsubst $(TEST_SRC_DIR)/%, $(TEST_OBJ_DIR)/%, $(TEST_SRC:.c=.o))
CFLAGS_TEST				=	$(CFLAGS) -DCRITERION_LOGGING_LEVEL=CR_LOG_INFO
LDFLAGS_TEST			=	$(LDFLAGS) -lcriterion 
###	Testing set-up />

###	Color Schemes
DEF_COLOR		=	\033[0;37m # Light gray
BOLD_GREEN		=	\033[1;32m
ORANGE			=	\033[0;33m
VIVID_BLUE		=	\033[1;34m
PURPLE			=	\033[0;35m
MAGENTA			=	\033[1;35m

###	Target rules
#	Default Target
all						:	$(NAME)

#	prod
$(NAME)					:	$(OBJ) 
							@printf "\n"
							@printf "\n$(DEF_COLOR)🔄 Compiling dependencies...$(DEF_COLOR)\n"
							@make -C $(LIBFT)
							@printf "\n"
							@make -C $(MINILIBX)
							@printf "\n$(DEF_COLOR)✅ Dependencies fulfilled.$(DEF_COLOR)\n"
							@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)
							@printf "\n$(BOLD_GREEN)[$(NAME)]:\t✅ $(NAME) compiled successfully!$(DEF_COLOR)\n"
#	test
$(TEST_EXEC)			:	$(TEST_OBJ)
							@make -C $(LIBFT) 
							@echo "$(ORANGE)[$(NAME)]:\t🔧 Testing mode activated.$(DEF_COLOR)"
							@$(CC) $(CFLAGS) -o $(TEST_EXEC) $(TEST_OBJ) $(LDFLAGS_TEST)

$(OBJ)					:	$(OBJ_DIR)
$(TEST_OBJ)				:	$(TEST_OBJ_DIR)

#	Create the object directory if it doesn't exist
$(OBJ_DIR)				:	
							@mkdir -p $(OBJ_DIR)
							@mkdir -p $(OBJ_DIR)/app
							@mkdir -p $(OBJ_DIR)/init
							@mkdir -p $(OBJ_DIR)/debug
							@mkdir -p $(OBJ_DIR)/error_handler
							@mkdir -p $(OBJ_DIR)/get_next_line
							@mkdir -p $(OBJ_DIR)/parse
							@mkdir -p $(OBJ_DIR)/parser
							@mkdir -p $(OBJ_DIR)/parser/parse_extract_config
							@mkdir -p $(OBJ_DIR)/parser/parse_extract_map_grid
							@mkdir -p $(OBJ_DIR)/player
							@mkdir -p $(OBJ_DIR)/raycasting_engine
							@mkdir -p $(OBJ_DIR)/render
							@mkdir -p $(OBJ_DIR)/util
							@mkdir -p $(OBJ_DIR)/utils

#	test
$(TEST_OBJ_DIR)			:
							@mkdir -p $(TEST_OBJ_DIR)

###	Rules for creating compiling .c files into obj
##	prod
$(OBJ_DIR)/%.o			:	$(SRC_DIR)/%.c | $(OBJ_DIR)
							$(PROGRESS_BAR)
							@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

##	test
$(TEST_OBJ_DIR)/%.o		:	$(TEST_SRC_DIR)/%.c | $(TEST_OBJ_DIR)
							@$(CC) $(CFLAGS_TEST) -I$(INCLUDES) -c $< -o $@

libft					:	@make -C $(LIBFT)

test					:	$(TEST_EXEC)
							@env CRITERION_LOG_LEVEL=INFO CRITERION_JOBS=1 ./$(TEST_EXEC) --verbose

clean					:
							@$(RM) $(OBJ_DIR) $(TEST_OBJ_DIR)
							@make clean -C $(LIBFT)
							@echo "$(VIVID_BLUE)[$(NAME)]:\t🔥 Object files cleaned.$(DEF_COLOR)"

fclean					:	clean
							@$(RM) $(NAME) $(TEST_EXEC)
							@$(RM) $(LIBFT)/libft.a
							@echo "$(MAGENTA)[$(NAME)]:\t🔥 All executable files cleaned.$(DEF_COLOR)"

re						:	fclean all
							@echo "$(BOLD_GREEN)[$(NAME)]:\t🚀 Cleaned and rebuilt all.$(DEF_COLOR)"

.PHONY					:	all clean fclean re test

###	Progress Bar
#	Macro to update progress bar
define PROGRESS_BAR
	@if [ $(COUNT) -eq 0 ]; then	\
		printf "\n";				\
	fi
	$(eval COUNT=$(shell echo $$(($(COUNT) + 1))))
	@printf "\r$(PURPLE)🔄 Compiling $(NAME)\t: [%-$(TOTAL_SRC_FILES)s] (%d/%d) $(DEF_COLOR)" \
	$$(printf '=%.0s' $$(seq 1 $(COUNT))) $(COUNT) $(TOTAL_SRC_FILES)
endef
