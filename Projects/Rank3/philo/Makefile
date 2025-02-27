SRCS = \
	philo.c \
	utils.c \
	get.c \
	init.c \
	parse.c \
	safe.c \
	write.c \
	simulation.c \
	extra_utils.c


OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


NAME = philo

CC = cc

CFLAGS = -Wall -Werror -Wextra -g 


all: $(NAME) 
	@echo "\033[0;32mCompilation Successful!\033[0m"

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

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
