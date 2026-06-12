NAME = ps

CC = cc

FLAGS = -Wall -Werror -Wextra

SRCS = push_swap.c push_swap_init.c push.c swap.c rotate.c reverse_rotate.c compute_disorder.c greedy_algo.c greedy_insert.c greedy_sort.c

OBJS = $(SRCS:.c=.o)

libft:
	$(MAKE) -C libft/
	$(MAKE) clean -C libft/

all: libft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -L libft/ -lft -I libft/ 

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft/

re: fclean all

.PHONY: all bonus clean fclean re libft