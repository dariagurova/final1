/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 18:52:59 by dgurova           #+#    #+#             */
/*   Updated: 2018/02/11 19:02:08 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

static void	init(t_meta *specs, t_print *out)
{
	out->result = itoa_base(specs->data_type.umax, 2, 0);
	out->length = ft_strlen(out->result);
	out->zeropad = 0;
	out->spacepad = 0;
	if (specs->precis > out->length)
		out->zeropad += specs->precis - out->length;
	if (specs->lead0x == true)
		out->length += 2;
	if (specs->width > out->length + out->zeropad)
		out->spacepad = specs->width - (out->length + out->zeropad);
}

static void print_char(t_meta *specs, char c, int times)
{
	while (times > 0)
	{
		ft_putchar_fd(c, *specs->fd);
		times--;
		*specs->ret = *specs->ret + 1;
	}
}

void		ft_binary(t_meta *specs, t_parse *in)
{
	t_print out;

	specs->data_type.umax = va_arg(in->arg, unsigned int);
	init(specs, &out);
	if (specs->left_algn == false)
	{
		if (out.zeropad > 0)
			print_char(specs, '0', out.spacepad);
		else
			print_char(specs, ' ', out.spacepad);
		print_char(specs, '0', out.zeropad);
		ft_putstr_fd(out.result, *specs->fd);
	}
	else
	{
		print_char(specs, '0', out.zeropad);
		ft_putstr_fd(out.result, *specs->fd);
		if (out.spacepad > 0)
			print_char(specs, ' ', out.spacepad);
	}
	*specs->ret = *specs->ret + out.length;
}
