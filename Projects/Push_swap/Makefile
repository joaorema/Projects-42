SRCS = \
    ft_error.c \
    push_swap_init.c \
    split.c \
    stack_extras.c \
    stack_init.c \
    swap_rotate.c \
    sort.c \
    swap_moves.c \
    

OBJS = $(SRCS:.c=.o)

NAME = push_swap.a

CC = cc

CC_FLAGS = -Wall -Wextra -Werror

all: $(NAME)
	@echo "\033[0;32mCompilation Successful!\033[0m"

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	@echo "\033[0;31mObjects removed\033[0m"
fclean: clean
	rm -f $(NAME)
	@echo "\033[0;31mLibftprintf.a removed\033[0m"

re: fclean all

notes:
