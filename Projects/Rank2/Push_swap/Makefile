SRCS = \
    sources/ft_error.c \
    sources/push_command.c \
    sources/push_swap_command.c \
    sources/push_swap_init.c \
    sources/sort.c \
    sources/split.c \
    sources/stack_extras.c \
    sources/stack_init.c \
    sources/swap_moves.c \
    sources/swap_rotate.c \
    sources/swap_r_rotate.c \
    sources/main.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

CC = cc

CC_FLAGS = -Wall -Wextra -Werror

all: $(NAME) 
	@echo "\033[0;32mCompilation Successful!\033[0m"

$(NAME): $(OBJS)
	$(CC) $(CC_FLAGS) -o $(NAME) $(OBJS)

$(ARCHIVE): $(OBJS)
	ar rcs $(ARCHIVE) $(OBJS)

clean:
	rm -f $(OBJS) 
	@echo "\033[0;31mObjects removed\033[0m"

fclean: clean
	rm -f $(NAME) $(ARCHIVE)
	@echo "\033[0;31mExecutable and archive removed\033[0m"

re: fclean all

notes:
