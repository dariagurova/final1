/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 21:04:44 by dgurova           #+#    #+#             */
/*   Updated: 2018/02/07 21:04:50 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**%[%][flags][width][(dot)precision][length]specifier
**
**Specifiers:
**	c	int converted to char
**	C	int converted to wide char
**	s	string
**	S	wide char string
**	p	pointer
**	di	int, D = ld
**	u	unsigned, U = lu
**	o	unsigned in octal, O = lo
**	x	unsigned in hexadecimal
**	X	unsigned in hexadecimal uppercase
**  b	binary
**
**Flags:
**	#		(o,O) prepend '0', x prepend "0x", X prepend "0X"
**	0		Prepend pad with '0' to width (if specified) for numeric types
**	-		Left align within width (if specified)
**	+		Prepend '+' for positive numeric types
**	(space)	Prepend pad positive numbers with a space
**
**Width:
**	<n>	Minimum of n characters are printed
**
**Precision:
**	(dot)<n>	(idD, uU, oO, xX) Pad with leading zeros if less than n
**
**Length (Aka cast as this):
**	hh	(idD) char,			(uU, oO, xX) unsigned char
**	h	(idD) short,		(uU, oO, xX) unsigned short
**	l	(idD) long,			(uU, oO, xX) unsigned long
**	ll	(idD) long long,	(uU, oO, xX) unsigned long long
**	j	(idD) intmax_t,		(uU, oO, xX) uintmax_t
**	z	(idD) size_t,		(uU, oO, xX) size_t
**
**Return Value:
**	Length of printed string
**.
*/
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdbool.h>
# include <stdio.h>
# include <stdarg.h>
# include <wchar.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define RESET		"\x1b[0m"

# define SET 		"0123456789abcdef0123456789ABCDEF"

typedef struct		s_vargs
{
	char			ch;
	char			*str;
	intmax_t		max;
	uintmax_t		umax;
	void			*ptr;
}					t_vargs;

typedef struct		s_meta
{
	bool			lead0x;
	bool			left_algn;
	bool			add_zero;
	bool			add_space;
	bool			add_sign;
	char			dtype;
	char			length[3];
	int				precis;
	int				len;
	int				width;
	int				*ret;
	int				*fd;
	t_vargs			data_type;
	va_list			*argp;
}					t_meta;

typedef struct		s_print
{
	char			*result;
	char			sign;
	int				zeropad;
	int				spacepad;
	int				length;
}					t_print;

typedef struct		s_parse
{
	int				ret;
	int				fd;
	char			*format;
	va_list			arg;
}					t_parse;

int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strcpy(char *dest, const char *src);
size_t				ft_strlen(const char *str);
int					ft_spaces(char c);
void				ft_bzero(void *s, size_t n);

int					ft_printf(const char *format, ...);
char				*itoa_base(uintmax_t val, int base, int offset);
void				parser(t_parse *in);

int					is_flag(char flag);
int					is_spec(t_meta *specs, char c);
void				parser(t_parse *in);
int					get_flags(t_meta *specs, char *format, int *i);
void				cast_signed(t_meta *specs, t_parse *in);
void				cast_unsigned(t_meta *specs, t_parse *in);

void				ft_string(t_meta *specs, t_parse *in);
void				ft_char(t_meta *specs, t_parse *in);
void				ft_percent(t_meta *specs);
void				ft_decimal(t_meta *specs, t_parse *in);
void				ft_pointer(t_parse *in, t_meta *specs);
void				ft_octal(t_meta *specs, t_parse *in);
void				ft_udecimal(t_meta *specs, t_parse *in);
void				ft_hex(t_parse *in, t_meta *specs);
//void				ft_binary(t_meta *specs, t_parse *in);

#endif
