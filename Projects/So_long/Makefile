SRCS = \
    main.c \
    keys.c \
    image.c

OBJS = $(SRCS:.c=.o)

NAME = so_long

LIBFT_DIR = ./Mylib
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = ./mlx_linux
MLX = $(MLX_DIR)/libmlx.a

CC = cc
CC_FLAGS = -Wall -Wextra -Werror -g 
RM = rm -f

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(MLX) $(LIBFT) $(NAME) 
	@echo "\033[0;32mCompilation Successful!\033[0m"

$(MLX):
	@if [ ! -d "$(MLX_DIR)" ]; then \
	echo "Cloning MiniLibX..."; \
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	@$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(MLX) $(OBJS) $(LIBFT)
	$(CC) $(CC_FLAGS) $(OBJS) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)
    
%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) clean -C $(MLX_DIR)
	@if [ -d "$(MLX_DIR)" ]; then \
	echo "Removing MiniLibX..."; \
	rm -rf $(MLX_DIR); \
	fi
    
re: fclean all

.PHONY: all clean fclean re
