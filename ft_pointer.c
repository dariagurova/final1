/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 20:18:57 by dgurova           #+#    #+#             */
/*   Updated: 2018/02/08 20:19:00 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

void		ft_pointer(t_parse *in, t_meta *specs)
{
	char *print;

	specs->data_type.umax = va_arg(in->arg, unsigned long int);
	print = itoa_base(specs->data_type.umax, 16, 0);
	ft_putstr_fd("0x", *specs->fd);
	*specs->ret = *specs->ret + 2;
	ft_putstr_fd(print, *specs->fd);
	*specs->ret = *specs->ret + ft_strlen(print);
}