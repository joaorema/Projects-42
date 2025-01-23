SRCS = \
    main.c \
	utils.c 

OBJS = $(SRCS:.c=.o)

NAME = Pipex

LIBFT_DIR = ./Mylib
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc 
CC_FLAGS = -Wall -Wextra -Werror 
RM = rm -f 

all: $(LIBFT) $(NAME)
		@echo "\033[0;32mCompilation Successful!\033[0m"

$(LIBFT):
		@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
		@$(CC) $(CC_FLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: sources/%.c
		@$(CC) $(CC_FLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
