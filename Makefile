#COMPILE_________________________________

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -MMD -MP -g
MAKEFLAGS	+= --no-print-directory

NAME		= cub3D
NAME_BONUS	= cub3D_bonus

#INCLUDES_AND_DIR________________________

#DIR
SRC_DIR		= src/
BUILD_DIR	= obj/
INC_DIR		= includes/
SRC_DIR_BONUS	= src_bonus/
BUILD_DIR_BONUS	= obj_bonus/

INCLUDES	= -I$(INC_DIR) -I$(INC_DIR)libft/ -I$(INC_DIR)gnl/ -I$(INC_DIR)minilibx
CFLAGS		+= $(INCLUDES)

#LIBFT
LIBFT		= $(INC_DIR)libft/libft.a

#MLX
MLX			= $(INC_DIR)minilibx/libmlx.a
MFLAGS		= -L$(INC_DIR)minilibx -lmlx -L/usr/lib -lXext -lX11 -lm -lz

#SRC_____________________________________

SRC_FILES	= ../includes/gnl/get_next_line.c \
			../includes/gnl/get_next_line_utils.c \
			main.c \
			utils.c \
			parsing/parsing.c \
			parsing/parse_textures.c \
			parsing/parse_color.c \
			parsing/parse_map.c \
			parsing/valid_map.c \
			pyramidmlx/extract_texture.c \
			pyramidmlx/free.c \
			pyramidmlx/mlx_tools.c \
			pyramidmlx/pyramid_draw.c \
			pyramidmlx/pyramid_draw_tools.c \
			pyramidmlx/pyramid_init.c \
			pyramidmlx/pyramid_khook.c \
			pyramidmlx/pyramid_bhook.c \
			pyramidmlx/texture.c \
			pyramidmlx/texture_scd.c \
			pyramid_math/matrix.c \
			player_handler/player.c \
			player_handler/player_movement.c


SRC_FILES_BONUS	=../includes/gnl/get_next_line.c \
				../includes/gnl/get_next_line_utils.c \
				main_bonus.c \
				utils_bonus.c \
				parsing/parsing_bonus.c \
				parsing/parse_textures_bonus.c \
				parsing/parse_color_bonus.c \
				parsing/parse_map_bonus.c \
				parsing/valid_map_bonus.c \
				pyramidmlx/extract_texture_bonus.c \
				pyramidmlx/free_bonus.c \
				pyramidmlx/mlx_tools_bonus.c \
				pyramidmlx/pyramid_draw_bonus.c \
				pyramidmlx/pyramid_draw_tools_bonus.c \
				pyramidmlx/pyramid_init_bonus.c \
				pyramidmlx/pyramid_khook_bonus.c \
				pyramidmlx/pyramid_bhook_bonus.c \
				pyramidmlx/texture_bonus.c \
				pyramidmlx/texture_scd_bonus.c \
				pyramid_math/matrix_bonus.c \
				player_handler/player_bonus.c \
				player_handler/player_movement_bonus.c

SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES))
SRCS_BONUS	= $(addprefix $(SRC_DIR_BONUS), $(SRC_FILES_BONUS))

#OBJ_AND_DEPS____________________________

OBJS		= $(SRC_FILES:%.c=$(BUILD_DIR)%.o)
DEPS		= $(OBJS:.o=.d)
OBJ_DIR		= $(sort $(dir $(OBJS)))
OBJS_BONUS	= $(SRC_FILES_BONUS:%.c=$(BUILD_DIR_BONUS)%.o)
DEPS_BONUS	= $(OBJS_BONUS:.o=.d)
OBJ_DIR_BONUS	= $(sort $(dir $(OBJS_BONUS)))

#________________________________________

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $^ $(MFLAGS) -o $@
	@echo "Compiles PYRAMID successfully"

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $^ $(MFLAGS) -o $@
	@echo "Compiles BONUS PYRAMID successfully"

$(LIBFT):
	@make -C $(INC_DIR)libft

$(MLX):
	@make -C $(INC_DIR)minilibx

$(BUILD_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@echo "Compile: $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR_BONUS)%.o: $(SRC_DIR_BONUS)%.c | $(OBJ_DIR_BONUS)
	@echo "Compile: $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR_BONUS):
	@mkdir -p $@

clean:
	@make -C $(INC_DIR)libft/ clean
	@make -C $(INC_DIR)minilibx/ clean
	@rm -rf $(INC_DIR)gnl/*.d $(INC_DIR)gnl/*.o $(BUILD_DIR) $(BUILD_DIR_BONUS)
	@echo "clean gnl (.o/.d)\nclean obj/"

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)
	@rm -f $(LIBFT)

re: fclean all

.PHONY: all clean bonus fclean re

-include $(DEPS) $(DEPS_BONUS)
