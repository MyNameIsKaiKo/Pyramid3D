#COMPILE_________________________________

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -MMD -MP -g
MAKEFLAGS	+= --no-print-directory

NAME		= pyramid

#INCLUDES_AND_DIR________________________

#DIR
SRC_DIR		= src/
BUILD_DIR	= obj/
INC_DIR		= includes/

LINKER		= -L$(INC_DIR)minilibx -lmlx -L/usr/lib -lXext -lX11 -lm -lz
INCLUDES	= -I$(INC_DIR) -I$(INC_DIR)libft/ -I$(INC_DIR)gnl/ -I$(INC_DIR)minilibx
CFLAGS		+= $(INCLUDES)

#LIBFT
LIBFT		= $(INC_DIR)libft/libft.a

#SRC_____________________________________

SRC_FILES	= ../includes/gnl/get_next_line.c \
			../includes/gnl/get_next_line_utils.c \
			maintest.c \
			./pyramidmlx/falsemap.c \
			./pyramidmlx/free.c \
			./pyramidmlx/mlx_tools.c \
			./pyramidmlx/pyramid_draw.c \
			./pyramidmlx/pyramid_draw_tools.c \
			./pyramidmlx/pyramid_init.c \
			./pyramidmlx/pyramid_khook.c \
			./pyramidmlx/pyramid_bhook.c \
			./pyramid_math/matrix.c \
			./player_handler/player.c

SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES))

#OBJ_AND_DEPS____________________________

OBJS		= $(SRC_FILES:%.c=$(BUILD_DIR)%.o)
DEPS		= $(OBJS:.o=.d)
OBJ_DIR		= $(sort $(dir $(OBJS)))

#________________________________________

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $^ $(LINKER) -o $@
	@echo "Compiles PYRAMID successfully"

$(BUILD_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@echo "Compile: $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(INC_DIR)libft

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@make -C $(INC_DIR)libft/ clean
	@rm -rf $(INC_DIR)gnl/*.d $(INC_DIR)gnl/*.o $(BUILD_DIR)
	@echo "clean gnl (.o/.d)\nclean obj/"

fclean: clean
	rm -rf $(NAME)
	@rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
