NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
ALL_FILE = ft_print_hexa_low.c \
ft_print_hexa_up.c \
ft_print_putnbr.c \
ft_printf_putchar_unsigned.c \
ft_print_void.c \
ft_printf_findtype.c \
ft_printf_putchar.c \
ft_printf_strwrt.c \
ft_printf.c

OBJ = $(ALL_FILE:.c=.o) 

all : $(NAME)

$(NAME) : $(OBJ) $(NAME)
	ar rcs $(NAME) $(OBJ)
%.o: %.c
	cc $(CFLAGS) -c $< -o $@
clean:
	rm -rf *.o
fclean:
	rm -rf *.o && rm -rf $(NAME)
re: fclean all