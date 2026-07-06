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

INCLUDES	= -I$(INC_DIR) -I$(INC_DIR)libft/ -I$(INC_DIR)gnl/
CFLAGS		+= $(INCLUDES)

#LIBFT
LIBFT		= $(INC_DIR)libft/libft.a

#SRC_____________________________________

SRC_FILES	= ../includes/gnl/get_next_line.c \
			../includes/gnl/get_next_line_utils.c \
			main.c \
			utils.c \
			parsing.c \
			parse_textures.c \
			parse_color.c \
			parse_map.c \
			valid_map.c


SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES))

#OBJ_AND_DEPS____________________________

OBJS		= $(SRC_FILES:%.c=$(BUILD_DIR)%.o)
DEPS		= $(OBJS:.o=.d)
OBJ_DIR		= $(sort $(dir $(OBJS)))

#________________________________________

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $^ -o $@
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