
SRCS = \
    sources/ft_printc.c \
    sources/ft_printd.c \
    sources/ft_printf.c \
    sources/ft_printp.c \
    sources/ft_prints.c \
    sources/ft_printu.c \
    sources/ft_printx.c
    
    
OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

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
