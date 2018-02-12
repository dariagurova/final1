/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 20:19:36 by dgurova           #+#    #+#             */
/*   Updated: 2018/02/08 20:19:38 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

int			ft_printf(const char *format, ...)
{
	t_parse in;

	in.ret = 0;
	in.fd = 1;
	in.format = (char*)format;
	va_start(in.arg, format);
	parser(&in);
	va_end(in.arg);
	return (in.ret);
}
