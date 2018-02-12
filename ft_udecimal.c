/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_udecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 19:39:57 by dgurova           #+#    #+#             */
/*   Updated: 2018/02/08 19:40:00 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

static void get_sign(t_meta *specs, t_print *out)
{
	if (specs->add_sign == true)
	{
		out->sign = '+';
		out->length++;
	}
}

static void	init(t_meta *specs, t_print *out)
{
	out->sign = 0;
	get_sign(specs, out);
	out->result = itoa_base(specs->data_type.umax, 10, 0);
	out->length = ft_strlen(out->result);
	out->zeropad = 0;
	out->spacepad = 0;
	if (specs->precis > out->length)
		out->zeropad += specs->precis - out->length;
	if (out->sign != 0)
		out->length++;
	if (specs->width > out->length + out->zeropad)
		out->spacepad += specs->width - (out->length + out->zeropad);
}

static void print_chr(t_meta *specs, char c, int times)
{
	while (times > 0)
	{
		ft_putchar_fd(c, *specs->fd);
		times--;
		*specs->ret = *specs->ret + 1;
	}
}

static void print_width(t_meta *specs, t_print *out)
{
	if (specs->add_zero == true)
	{
		if (out->sign != 0)
			ft_putchar_fd(out->sign, *specs->fd);
		print_chr(specs, '0', out->spacepad);
	}
	else
		print_chr(specs, ' ', out->spacepad);
}

void		ft_udecimal(t_meta *specs, t_parse *in)
{
	t_print out;

	cast_unsigned(specs, in);
	init(specs, &out);
	if (specs->left_algn == false)
	{
		print_width(specs, &out);
		if (out.sign != 0 && specs->add_zero == false)
			ft_putchar_fd(out.sign, *specs->fd);
		print_chr(specs, '0', out.zeropad);
		ft_putstr_fd(out.result, *specs->fd);
	}
	else
	{
		if (out.sign != 0)
			ft_putchar_fd(out.sign, *specs->fd);
		print_chr(specs, '0', out.zeropad);
		ft_putstr_fd(out.result, *specs->fd);
		print_chr(specs, ' ', out.spacepad);
	}
	*specs->ret = *specs->ret + out.length;
}
