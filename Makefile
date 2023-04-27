SRCS	= main.c

OBJS	= $(SRCS:.c=.o)

NAME	= philo

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -pthread

RM		= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re