/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgurova <dariagurova91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 23:16:16 by dgurova           #+#    #+#             */
/*   Updated: 2018/02/07 23:16:18 by dgurova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

int				ft_atoi(const char *str)
{
	int					sign;
	int					i;
	unsigned long long	check;

	sign = 1;
	i = 0;
	check = 0;
	while (ft_spaces(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		check = check * 10 + (str[i] - 48);
		i++;
	}
	if (check > 9223372036854775807)
		return (sign == 1 ? -1 : 0);
	return (int)(check * sign);
}

static int		ft_blank(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int				ft_spaces(char c)
{
	return (ft_blank(c) || c == '\f' || c == '\v' || c == '\r');
}

int				ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int				ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
