#COMPILE_______________________
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP
MAKEFLAGS += --no-print-directory

NAME = pyramid

#INCLUDES______________________
INCLUDE = includes/

#LIBFT
INCLUDE_LIBFT = includes/libft/
LIBFT_A = includes/libft/libft.a

CFLAGS += -I$(INCLUDE) -I $(INCLUDE_LIBFT)

BUILD_DIR = obj/
SRC_DIR = src/

#SRC___________________________

SRC=main.c \
	parse_arg.c \
	utils.c

#OBJ___________________________

OBJ = $(SRC:%.c=$(BUILD_DIR)%.o)
DEPS = $(SRC:%.c=$(BUILD_DIR)%.d)
OBJ_DIR = $(sort $(shell dirname $(OBJ)))

#_________________________________

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "link Pyramide3D"

$(LIBFT_A):
	@make -C includes/libft

$(BUILD_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDE)

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@make -C includes/libft/ clean
	@rm -rf $(BUILD_DIR)
	@echo "clean obj/"

fclean: clean
	rm -rf $(NAME)
	@rm -f $(LIBFT_A)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)