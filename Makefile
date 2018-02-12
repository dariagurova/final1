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
OBJ =	${SRCS:.c=.o}
RM = @rm -f

EXE = test

all: $(NAME)

$(NAME): $(OBJ)
	@gcc -Wall -Wextra -Werror -c $(SRCS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	//@gcc $(CFLAGS) -o $(EXE) main.c libftprintf.a
%.o: %.c
	gcc -g -Wall -Wextra -Werror -Ift_printf -c $<	


clean:
	$(RM) *.o


fclean: clean
	$(RM) $(NAME)


re: fclean all
