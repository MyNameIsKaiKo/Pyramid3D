CC=cc
CFLAGS=-I$(INCLUDE) -Wall -Wextra -Werror

NAME=libft.a

BUILD_DIR=obj/
INCLUDE=include/
SRC_DIR=src/

SRC= function_fd.c \
	function_mem.c \
	what_is.c \
	ft_strlen.c \
	ft_bzero.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_atol.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_strndup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strjoin_and_free.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	create_node_bonus.c \
	utils_bonus.c \
	utils2_bonus.c \
	free_matrix.c

OBJ= $(SRC:%.c=$(BUILD_DIR)%.o)
OBJ_DIR= $(sort $(shell dirname $(OBJ)))

SRC_BONUS= create_node_bonus.c \
	utils_node_bonus.c

OBJ_BONUS= $(SRC_BONUS:%.c=$(BUILD_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "Compiles LIBF successfully"

$(BUILD_DIR)%.o:$(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME) $(OBJ_BONUS)
	@ar rcs $(NAME) $(OBJ_BONUS)
	@echo "Compiles LIBFT bonus successfully"
	touch bonus

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(BUILD_DIR) bonus
	@echo "clean libft"

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re