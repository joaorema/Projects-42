SRCS = \
    sources/philo.c \
	sources/utils.c


OBJS = $(SRCS:.c=.o)

NAME = philo

CC = cc

CC_FLAGS = -Wall -Wextra -Werror -pthread

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