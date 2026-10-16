NAME=libftprintf.a

CC=cc

CFLAGS=-Wall -Wextra -Werror -g

SRCS= ./ft_printf.c ./print_char.c ./print_hexa_upper.c ./print_hexa.c ./print_number.c ./print_pointer.c ./print_string.c ./print_unsigned.c ./ft_putstr_fd.c ./ft_putchar_fd.c ./ft_putnbr_fd.c ./ft_strchr.c ./ft_strdup.c ./ft_strjoin.c ./ft_substr.c

OBJS= ${SRCS:.c=.o}

INCLUDE= .

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
