CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME =	so_long
SRCS =	src/so_long.c src/get_map.c \
		includes/get_next_line_so/get_next_line_utils.c includes/get_next_line_so/get_next_line.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = includes/libft
LIBFT_TARGET = $(LIBFT_DIR)/libft.a

# Path to MiniLibX directory
MLX_DIR = ./includes/mlx

# MiniLibX library and flags for macOS
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_TARGET)
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(MLX_DIR)/mlx -c $< -o $@

# Build the "libft" library using its Makefile
$(LIBFT_TARGET):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
