NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -I includes -I libft -I ft_printf -I libft/get_next_line -I minilibx-linux

RM = rm -rf

SRC =	src/main.c \
		src/initialize_map.c \
		src/print_error.c \
		src/check_map.c \
		src/utils.c \
		src/window_mlx.c \
		src/render_map.c

OBJS = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L $(MLX_DIR) -lmlx -lXext -lX11 -lm
 
all: $(LIBFT) $(PRINTF) $(MLX) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(MLX):
	make -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	make -C $(MLX_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

.SILENT: