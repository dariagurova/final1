/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 19:39:42 by dgurova           #+#    #+#             */
/*   Updated: 2018/02/08 19:39:44 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

static void	print_chr(t_meta *specs, char c, int times)
{
	while (times > 0)
	{
		ft_putchar_fd(c, *specs->fd);
		*specs->ret = *specs->ret + 1;
		times--;
	}
}

static void	init(t_meta *specs, t_print *out)
{
	out->result = itoa_base(specs->data_type.umax, 8, 0);
	out->length = ft_strlen(out->result);
	out->zeropad = 0;
	if (specs->lead0x == true && out->result[0] != '0')
		out->zeropad++;
	if (specs->left_algn == true)
	{
		if (specs->precis > out->length + out->zeropad)
			out->zeropad = specs->precis - out->length;
		out->spacepad = specs->width - (out->zeropad + out->length);
	}
	else
	{
		if (specs->precis > out->length + out->zeropad)
			out->zeropad = specs->precis - out->length;
		if (specs->add_zero == true)
			out->zeropad += specs->width - (out->zeropad + out->length);
		else
			out->spacepad = specs->width - (out->zeropad + out->length);
	}
}

void		ft_octal(t_meta *specs, t_parse *in)
{
	t_print out;

	cast_unsigned(specs, in);
	init(specs, &out);
	if (specs->left_algn == true)
	{
		print_chr(specs, '0', out.zeropad);
		ft_putstr_fd(out.result, *specs->fd);
		print_chr(specs, ' ', out.spacepad);
		*specs->ret = *specs->ret + out.length;
	}
	else
	{
		print_chr(specs, ' ', out.spacepad);
		print_chr(specs, '0', out.zeropad);
		ft_putstr_fd(out.result, *specs->fd);
		*specs->ret = *specs->ret + out.length;
	}
}
