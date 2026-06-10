NAME = ps

CC = cc

FLAGS = -Wall -Werror -Wextra

SRCS = push_swap.c push_swap_init.c push.c swap.c rotate.c reverse_rotate.c compute_disorder.c

OBJS = $(SRCS:.c=.o)

libft:
	$(MAKE) -C libft/
	$(MAKE) clean -C libft/

printf:
	$(MAKE) -C printf/
	$(MAKE) clean -C printf/

all: libft printf $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -L libft/ -lft -I libft/ -L printf/ -lftprintf

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft/
	$(MAKE) fclean -C printf/

re: fclean all

.PHONY: all bonus clean fclean re libft printf