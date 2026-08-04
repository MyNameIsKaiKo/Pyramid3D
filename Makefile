#COMPILE_________________________________

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -MMD -MP
MAKEFLAGS	+= --no-print-directory

NAME_BONUS	= cub3D_bonus
NAME		= cub3D

ifdef WITH_BONUS
	TARGET	= $(NAME_BONUS)
else
	TARGET	= $(NAME)
endif

#INCLUDES_AND_DIR________________________

#DIR
SRC_DIR		= src/
ifdef WITH_BONUS
	BUILD_DIR	= obj_bonus/
else
	BUILD_DIR	= obj/
endif
INC_DIR		= includes/

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
			free.c \
			free_scd.c \
			free_map.c \
			parsing/parsing.c \
			parsing/parse_textures.c \
			parsing/parse_color.c \
			parsing/parse_char.c \
			parsing/parse_map.c \
			parsing/valid_map.c \
			parsing/copy_map.c \
			pyramidmlx/extract_texture.c \
			pyramidmlx/mlx_tools.c \
			pyramidmlx/pyramid_draw.c \
			pyramidmlx/pyramid_draw_tools.c \
			pyramidmlx/pyramid_init.c \
			pyramidmlx/pyramid_khook.c \
			pyramidmlx/pyramid_bhook.c \
			pyramidmlx/texture.c \
			pyramidmlx/texture_scd.c \
			pyramidmlx/pyramid_mouse.c \
			pyramidmlx/cross_air.c \
			pyramid_math/matrix.c \
			player_handler/player.c \
			player_handler/player_movement.c \
			player_handler/player_tools.c \


SRC_BONUS_FILES = bonus/display_minimap_bonus.c \
				bonus/minimap_bonus.c \
				bonus/parse_map_bonus.c \
				bonus/parse_tex_bonus.c \
				bonus/parsing_bonus.c \
				bonus/pyramid_draw_bonus.c \
				bonus/pyramid_draw_tools_bonus.c \
				bonus/texture_data_bonus.c \
				bonus/utils_bonus.c \
				bonus/recover_tex_sprite_bonus.c \
				bonus/sprites/sprites_calc.c \
				bonus/sprites/sprites_handler.c \
				bonus/sprites/sprites_tools.c \
				bonus/player_handler/gun_handler.c \
				bonus/player_handler/player_handler_bonus.c \
				bonus/player_handler/door.c \
				bonus/free_bonus.c \
				bonus/bonus.c \
				bonus/recover_sprites_bonus.c

ifdef WITH_BONUS
	SRC_FILES += $(SRC_BONUS_FILES)
	CFLAGS += -DBONUS=1
endif

SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES))

#OBJ_AND_DEPS____________________________

OBJS		= $(SRC_FILES:%.c=$(BUILD_DIR)%.o)
DEPS		= $(OBJS:.o=.d)
OBJ_DIR		= $(sort $(dir $(OBJS)))

#________________________________________

all: $(TARGET)

$(TARGET): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $^ $(MFLAGS) -o $@
	@echo "Compiles PYRAMID successfully"

$(BUILD_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@echo "Compile: $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(INC_DIR)libft

$(MLX):
	@make -C $(INC_DIR)minilibx

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@make -C $(INC_DIR)libft/ clean
	@make -C $(INC_DIR)minilibx/ clean
	@rm -rf obj obj_bonus
	@rm -f $(INC_DIR)gnl/*.d $(INC_DIR)gnl/*.o
	@echo "clean gnl (.o/.d)\nclean obj/"

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)
	@rm -f $(LIBFT)

re: fclean all

bonus:
	@$(MAKE) WITH_BONUS=1 all

reb: fclean bonus

.PHONY: all clean fclean re

-include $(DEPS)
