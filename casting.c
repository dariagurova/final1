/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 21:05:03 by dgurova           #+#    #+#             */
/*   Updated: 2018/02/07 21:05:05 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./printf.h"

void	cast_unsigned(t_meta *specs, t_parse *in)
{
	if (specs->length[0] == 'l' || specs->dtype == 'O' || specs->dtype == 'U')
		specs->data_type.umax = va_arg(in->arg, unsigned long int);
	else if (specs->length[0] == '\0')
		specs->data_type.umax = va_arg(in->arg, unsigned int);
	else if (specs->length[0] == 'h' && specs->length[1] == 'h')
		specs->data_type.umax = (unsigned char)va_arg(in->arg, unsigned int);
	else if (specs->length[0] == 'h')
		specs->data_type.umax = (unsigned short)va_arg(in->arg, unsigned int);
	else if (specs->length[0] == 'l' && specs->length[1] == 'l')
		specs->data_type.umax = va_arg(in->arg, unsigned long long int);
	else if (specs->length[0] == 'j')
		specs->data_type.umax = va_arg(in->arg, uintmax_t);
	else if (specs->length[0] == 'z')
		specs->data_type.umax = va_arg(in->arg, size_t);
}

void	cast_signed(t_meta *specs, t_parse *in)
{
	if (specs->length[0] == 'l' || specs->dtype == 'D')
		specs->data_type.max = va_arg(in->arg, long int);
	else if (specs->length[0] == '\0')
		specs->data_type.max = va_arg(in->arg, int);
	else if (specs->length[0] == 'h' && specs->length[1] == 'h')
		specs->data_type.max = (char)va_arg(in->arg, int);
	else if (specs->length[0] == 'h')
		specs->data_type.max = (short int)va_arg(in->arg, int);
	else if (specs->length[0] == 'l' && specs->length[1] == 'l')
		specs->data_type.max = va_arg(in->arg, long long int);
	else if (specs->length[0] == 'j')
		specs->data_type.max = va_arg(in->arg, intmax_t);
	else if (specs->length[0] == 'z')
		specs->data_type.max = va_arg(in->arg, size_t);
}
