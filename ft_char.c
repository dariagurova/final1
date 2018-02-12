/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 23:15:41 by dgurova           #+#    #+#             */
/*   Updated: 2018/02/07 23:15:43 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

static void	print_width(t_meta *specs)
{
	int print;

	print = specs->width - specs->len;
	while (print > 0)
	{
		ft_putchar_fd(' ', *specs->fd);
		print--;
		*specs->ret = *specs->ret + 1;
	}
}

static void	print_char(char output, int *ret, int fd)
{
	ft_putchar_fd(output, fd);
	*ret = *ret + 1;
}

void	ft_char(t_meta *specs, t_parse *in)
{ 
	specs->data_type.ch = va_arg(in->arg, int);
	specs->len = 1;
	if (specs->left_algn == true)
	{
		print_char(specs->data_type.ch, specs->ret, *specs->fd);
		print_width(specs);
	}
	else
	{
		print_width(specs);
		print_char(specs->data_type.ch, specs->ret, *specs->fd);
	}
}

