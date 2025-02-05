SRCS = \
    sources/get_next_line.c \
    sources/get_next_line_utils.c 
    
    
OBJS = $(SRCS:.c=.o)

NAME = get_next_line

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
