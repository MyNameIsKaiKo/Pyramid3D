#COMPILE_________________________________

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -MMD -MP -g
MAKEFLAGS	+= --no-print-directory

NAME		= cub3D

#INCLUDES_AND_DIR________________________

#DIR
SRC_DIR		= src/
BUILD_DIR	= obj/
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
			player_handler/player_movement.c \


SRC_BONUS_FILES = bonus/enemie.c \
				bonus/parse_color_bonus.c

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

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
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
	@rm -rf $(INC_DIR)gnl/*.d $(INC_DIR)gnl/*.o $(BUILD_DIR)
	@echo "clean gnl (.o/.d)\nclean obj/"

fclean: clean
	rm -rf $(NAME)
	@rm -f $(LIBFT)

re: fclean all

bonus:
	@$(MAKE) WITH_BONUS=1 all

reb: fclean bonus

.PHONY: all clean fclean re

-include $(DEPS)
