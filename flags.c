/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 21:00:44 by dgurova           #+#    #+#             */
/*   Updated: 2018/02/08 21:00:47 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

static int		precision(t_meta *specs, char *format)
{
	int j;

	j = 0;
	if (ft_isdigit(format[j]))
	{
		specs->precis = ft_atoi(format);
		while (ft_isdigit(format[++j]))
			;
	}
	else
		specs->precis = 0;
	return (j);
}

static int		width(t_meta *specs, char *format)
{
	int j;

	j = 0;
	specs->width = ft_atoi(format);
	while (ft_isdigit(format[++j]))
		;
	return (j - 1);
}

static int		flags(t_meta *specs, char *format)
{
	int j;

	j = 0;
	while (is_flag(format[j]))
	{
		if (format[j] == '#')
			specs->lead0x = true;
		else if (format[j] == ' ')
			specs->add_space = true;
		else if (format[j] == '0')
			specs->add_zero = true;
		else if (format[j] == '+')
			specs->add_sign = true;
		else if (format[j] == '-')
			specs->left_algn = true;
		j++;
	}
	return (j - 1);
}

static int		length(t_meta *specs, char *format)
{
	int c;

	c = 0;
	if (format[c] == 'h' && format[c + 1] == 'h' && (c += 2))
		ft_strcpy(specs->length, "hh\0");
	else if (format[c] == 'h' && (c += 1))
		ft_strcpy(specs->length, "h\0");
	else if (format[c] == 'l' && format[c + 1] == 'l' && (c += 2))
		ft_strcpy(specs->length, "ll\0");
	else if (format[c] == 'l' && (c += 1))
		ft_strcpy(specs->length, "l\0");
	else if (format[c] == 'z' && (c += 1))
		ft_strcpy(specs->length, "z\0");
	else if (format[c] == 'j' && (c += 1))
		ft_strcpy(specs->length, "j\0");
	return (c - 1);
}

int				get_flags(t_meta *specs, char *format, int *i)
{
	while (format[++*i] && !(is_spec(specs, format[*i])))
	{
		if (is_flag(format[*i]))
			*i = *i + flags(specs, format + *i);
		else if (format[*i] == '.')
			*i = *i + precision(specs, format + *i + 1);
		else if (ft_isdigit(format[*i]))
			*i = *i + width(specs, format + *i);
		else if (ft_isalpha(format[*i]))
			*i += length(specs, format + *i);
	}
	return (0);
}

