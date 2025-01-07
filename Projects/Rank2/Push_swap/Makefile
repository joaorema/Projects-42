SRCS = \
    ft_error.c \
    push_command.c \
    push_swap_command.c \
    push_swap_init.c \
    sort.c \
    split.c \
    stack_extras.c \
    stack_init.c \
    swap_moves.c \
    swap_rotate.c \
    swap_r_rotate.c \
    main.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap
ARCHIVE = push_swap.a

CC = cc

CC_FLAGS = -Wall -Wextra -Werror

all: $(NAME) $(ARCHIVE)
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
