CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit
NAME = so_long

SRCS =	./src/test.c \
		includes/get_next_line_so/get_next_line_utils.c includes/get_next_line_so/get_next_line.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = includes/libft
LIBFT_TARGET = $(LIBFT_DIR)/libft.a

PRINTF_DIR = includes/ft_printf
PRINTF_TARGET = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_TARGET) $(PRINTF_TARGET)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

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
