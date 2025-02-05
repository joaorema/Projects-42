SRCS = \
    sources/main.c \
	sources/utils.c 

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = \
    bonus/pipex_bonus.c \
    bonus/utils_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

NAME = Pipex
BONUS_NAME = Pipex_bonus

LIBFT_DIR = ./Mylib
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc 
CC_FLAGS = -Wall -Wextra -Werror 
RM = rm -f 

all: $(LIBFT) $(NAME)
		@echo "\033[0;32mCompilation Successful!\033[0m"

bonus: $(LIBFT) $(BONUS_NAME)
		@echo "\033[0;32mCompilation Sucessfull!\0333[0m"

$(LIBFT):
		@$(MAKE) -C $(LIBFT_DIR)


$(NAME): $(OBJS) $(LIBFT)
		@$(CC) $(CC_FLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(BONUS_NAME):	$(BONUS_OBJS) $(LIBFT)
		@$(CC) $(CC_FLAGS) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft -o $(BONUS_NAME)

%.o: sources/%.c
		@$(CC) $(CC_FLAGS) -c $< -o $@

bonus/%.o: bonus/%.c
		@$(CC) $(CC_FLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

clean_bonus:
		$(RM) $(BONUS_OBJS)

fclean_bonus: clean_bonus
		$(RM) $(BONUS_NAME)
		

fclean: clean
		$(RM) $(NAME)


re: fclean all

.PHONY: all clean fclean re bonus clean_bonus
