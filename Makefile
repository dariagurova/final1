NAME = libftprintf.a


SRCS = ft_printf.c \
		flags.c \
		parser.c \
		casting.c \
		ft_string.c \
		ft_char.c \
		ft_decimal.c \
		ft_udecimal.c \
		ft_percent.c \
		ft_pointer.c \
		ft_octal.c \
		ft_hex.c \
		ft_binary.c \
		helpers.c \
		itoa_base.c \
		libft1.c \
	    libft2.c \

CFLAGS = -Wall -Wextra -Werror -I./printf.h

RM = @rm -f

EXE = test

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRCS)
	@ar rc $(NAME) *.o
	@ranlib $(NAME)
	@gcc $(CFLAGS) -o $(EXE) main.c libftprintf.a


clean:
	$(RM) *.o


fclean: clean
	$(RM) $(NAME)


re: fclean all