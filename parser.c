/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 21:02:12 by dgurova           #+#    #+#             */
/*   Updated: 2018/02/08 21:02:14 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"


static void init(t_parse *in, t_meta *specs)
{
	specs->left_algn = false;
	specs->add_sign = false;
	specs->add_space = false;
	specs->add_zero = false;
	specs->lead0x = false;
	specs->width = 0;
	specs->precis = -1;
	specs->length[0] = '\0';
	specs->length[1] = '\0';
	specs->length[2] = '\0';
	specs->dtype = 0;
	specs->len = 0;
	specs->argp = &in->arg;
	specs->fd = &in->fd;
	specs->ret = &in->ret;
}

static void	engine(t_parse *in, int *i)
{
	t_meta specs;

	init(in, &specs);
	get_flags(&specs, in->format, i);
	if (specs.dtype == 's' || specs.dtype == 'S')
		ft_string(&specs, in);
	else if (specs.dtype == 'c' || specs.dtype == 'C')
		ft_char(&specs, in);
	else if (specs.dtype == '%')
		ft_percent(&specs);
	else if (specs.dtype == 'p')
		ft_pointer(in, &specs);
	else if (specs.dtype == 'o' || specs.dtype == 'O')
		ft_octal(&specs, in);
	else if (specs.dtype == 'd' || specs.dtype == 'i' || specs.dtype == 'D')
		ft_decimal(&specs, in);
	else if (specs.dtype == 'u' || specs.dtype == 'U')
		ft_udecimal(&specs, in);
	else if (specs.dtype == 'x' || specs.dtype == 'X')
		ft_hex(in, &specs);
}

static void		buffprint(t_parse *in, int start, int i)
{
	write(in->fd, in->format + start, i - start);
	in->ret += i - start;
}

void			parser(t_parse *in)
{
	int i;
	int start;

	i = -1;
	start = 0;
	while (in->format[++i] != '\0')
	{
		if (in->format[i] == '%')
		{
			buffprint(in, start, i);
			engine(in, &i);
			start = i + 1;
		}
	}
	buffprint(in, start, i);
}
