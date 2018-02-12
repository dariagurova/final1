/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 21:10:33 by dgurova           #+#    #+#             */
/*   Updated: 2018/02/08 21:10:35 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

int 	is_flag(char flag)
{
	if (flag == '#' || flag == '-' || flag == '+' ||
	 flag == '0' || flag == ' ')
		return (1);
	return (0);
}

int	is_spec(t_meta *specs, char c)
{
	if ((c == 's' || c == 'd' || c == 'i' || c == 'c' || c == '%' || c == 'u'
		|| c == 'n' || c == 'o' || c == 'e' || c == 'e' || c == 'x' || c == 'X'
		|| c == 'p' || c == 'G' || c == 'g' || c == 'S' || c == 'D' || c == 'C'
		|| c == 'O' || c == 'U' || c == 'b') && (specs->dtype = c))
		return (1);
	return (0);
}

void	space(t_meta *specs, t_print *out)
{
	if (specs->add_space == true && out->sign == 0)
		ft_putchar_fd(' ', *specs->fd);
}