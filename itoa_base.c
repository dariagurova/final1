/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 20:19:59 by dgurova           #+#    #+#             */
/*   Updated: 2018/02/08 20:20:01 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

char		*itoa_base(uintmax_t val, int base, int opt)
{
	static char	buff[32] = "0";
	char		set[32] = SET;
	int			i;
	int 		o;

	i = 30;
	o = 0;
	if (opt != 0)
		o = 16;
	if (val == 0)
		return (ft_strcpy(buff, "0\0"));
	while (val > 0 && i > 0)
	{
		buff[i] = set[(val % base) + o];
		val = val / base;
		--i;
	}
	return (buff + i + 1);
}
