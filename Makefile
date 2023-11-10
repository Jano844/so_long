CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw
NAME = so_long

SRCS =	./src/so_long.c ./src/get_map.c ./src/move.c ./src/error.c ./src/init.c ./src/check_map.c\
		./includes/get_next_line_so/get_next_line_utils.c ./includes/get_next_line_so/get_next_line.c


OBJS = $(SRCS:.c=.o)

LIBFT_DIR = includes/libft
LIBFT_TARGET = $(LIBFT_DIR)/libft.a

PRINTF_DIR = includes/ft_printf
PRINTF_TARGET = $(PRINTF_DIR)/libftprintf.a

MLX_DIR = includes/MLX42/build
MLX_LIB = -L$(MLX_DIR) -lmlx42

all: $(NAME)

clone:
	@if [ ! -d "includes/MLX42" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git includes/MLX42; \
	else \
		echo "Directory includes/MLX42 already exists."; \
	fi
	@cd includes/MLX42 && cmake -B build && cmake --build build -j4

$(NAME): $(OBJS) $(LIBFT_TARGET) $(PRINTF_TARGET)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf $(MLXFLAGS) $(MLX_LIB)

$(LIBFT_TARGET):
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_TARGET):
	@$(MAKE) -C $(PRINTF_DIR)

$(OBJS): $(LIBFT_TARGET) $(PRINTF_TARGET)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
