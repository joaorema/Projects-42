SRCS = \
    sources/main.c \
    sources/keys.c \
    sources/image.c \
    sources/parsing.c \
    sources/path.c \
    sources/utils.c \
    sources/map.c \
    sources/size.c
    
OBJS = $(SRCS:.c=.o)

NAME = so_long

LIBFT_DIR = ./Mylib
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = ./mlx_linux
MLX = $(MLX_DIR)/libmlx.a

CC = cc
CC_FLAGS = -Wall -Wextra -Werror -g -Imlx_linux
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
	@$(CC) $(CC_FLAGS) $(OBJS) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)
    
%.o: sources/%.c
	@$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) clean -C $(MLX_DIR)
	
    
re: fclean all

.PHONY: all clean fclean re
