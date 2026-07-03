NAME = push_swap

CC = cc

FLAGS = -Wall -Werror -Wextra

SRCS = push_swap.c \
		push_swap_init.c \
		push.c \
		swap.c \
		rotate.c \
	 	reverse_rotate.c \
		compute_disorder.c \
		check_error.c \
		bench_gestion.c \
		algo_complexe/greedy_algo.c \
		algo_complexe/greedy_insert.c \
		algo_complexe/greedy_sort.c \
		algo_complexe/linked_list_minmax.c \
		algo_adaptive/algo_adaptive.c \
		algo_simple/Simple_algorithm.c \

OBJS = $(SRCS:.c=.o)

all: libft printf $(NAME)

libft:
	$(MAKE) -C libft/
	$(MAKE) clean -C libft/

printf:
	$(MAKE) -C printf/
	$(MAKE) clean -C printf/

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