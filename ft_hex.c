/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 19:39:25 by dgurova           #+#    #+#             */
/*   Updated: 2018/02/08 19:39:27 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

static void	print_char(t_meta *specs, char print, int times)
{
	while (times > 0)
	{
		ft_putchar_fd(print, *specs->fd);
		*specs->ret = *specs->ret + 1;
		times--;
	}
}

static void	init(t_meta *specs, t_print *out)
{
	if (specs->dtype == 'x')
		out->result = itoa_base(specs->data_type.umax, 16, 0);
	else
		out->result = itoa_base(specs->data_type.umax, 16, 1);
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
static void		ft_check(t_meta *specs, t_print *out)
{
	if (specs->lead0x == true && out->result[0] != '0')
	{
		if (specs->dtype == 'X')
			ft_putstr_fd("0X", *specs->fd);
		else
			ft_putstr_fd("0x", *specs->fd);
	}
}

void		ft_hex(t_parse *in, t_meta *specs)
{
	t_print out;

	cast_unsigned(specs, in);
	init(specs, &out);
	if (specs->left_algn == false)
	{
		if (out.zeropad > 0)
			print_char(specs, '0', out.spacepad);
		else
			print_char(specs, ' ', out.spacepad);
		ft_check(specs, &out);
		print_char(specs, '0', out.zeropad);
		ft_putstr_fd(out.result, *specs->fd);
		*specs->ret = *specs->ret + out.length;
	}
	else
	{
		ft_check(specs, &out);
		print_char(specs, '0', out.zeropad);
		ft_putstr_fd(out.result, *specs->fd);
		if (out.spacepad > 0)
			print_char(specs, ' ', out.spacepad);
		*specs->ret = *specs->ret + out.length;
	}
}