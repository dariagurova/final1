/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 20:19:16 by dgurova           #+#    #+#             */
/*   Updated: 2018/02/08 20:19:18 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

#include "./printf.h"

static void	print_width(t_meta *specs)
{
	int print;

	if (specs->precis >= 0 && specs->precis < specs->len)
		print = specs->width - specs->precis;
	else
		print = specs->width - specs->len;
	while (print > 0)
	{
		ft_putchar_fd(' ', *specs->fd);
		print--;
		*specs->ret = *specs->ret + 1;
	}
}

static void	print_precis(t_meta *specs)
{
	int print;

	if (specs->precis != -1 && specs->precis < specs->len)
		print = specs->precis;
	else
		print = specs->len;
	write(*specs->fd, specs->data_type.str, print);
	*specs->ret = *specs->ret + print;
}

void		ft_string(t_meta *specs, t_parse *in)
{
	specs->data_type.str = va_arg(in->arg, char*);
	if (specs->data_type.str == NULL)
	{
		specs->data_type.str = "(null)";
	}
	specs->len = ft_strlen(specs->data_type.str);
	if (specs->left_algn == true)
	{
		print_precis(specs);
		print_width(specs);
	}
	else
	{
		print_width(specs);
		print_precis(specs);
	}
}
