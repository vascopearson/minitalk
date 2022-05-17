/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 09:39:42 by vserrao-          #+#    #+#             */
/*   Updated: 2022/02/01 15:26:22 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static t_format	ft_width(char *c, va_list args, t_format new)
{
	int	width;

	width = 0;
	while (*c != '.' && !ft_strchr(SPECIFIERS, *c))
	{
		if (*c == '-')
			new.minus = 1;
		if (*c == '0' && !ft_isdigit(*(c - 1)))
			new.zero = 1;
		else if (((*c > '0' && *c <= '9') || *c == '*') && !width)
		{
			if (*c == '*')
				new.width = va_arg(args, int);
			else
				new.width = ft_atoi(c);
			width = 1;
		}
		c++;
	}	
	return (new);
}

static t_format	ft_bonus(char *c, t_format new)
{
	while (*c != '.' && !ft_strchr(SPECIFIERS, *c))
	{
		if (*c == '+')
			new.plus = 1;
		if (*c == ' ')
			new.space = 1;
		if (*c == '#')
			new.hash = 1;
		c++;
	}
	return (new);
}

static t_format	ft_precision(char *c, va_list args, t_format new)
{
	int	precision;

	precision = 0;
	while (!ft_strchr(SPECIFIERS, *c))
	{
		if ((ft_isdigit(*c) || *c == '*') && !precision)
		{
			if (*c == '*')
				new.precision = va_arg(args, int);
			else
				new.precision = ft_atoi(c);
			precision = 1;
		}
		c++;
	}
	return (new);
}

int	ft_eval(char *str, va_list args)
{
	t_format	new;

	new = ft_init_format();
	new = ft_width(str, args, new);
	new = ft_bonus(str, new);
	while (!ft_strchr(SPECIFIERS, *str) && *str != '.')
		str++;
	if (*str == '.')
	{
		new.dot = 1;
		new = ft_precision(str++, args, new);
		while (!ft_strchr(SPECIFIERS, *str))
			str++;
	}
	if (new.width < 0)
	{
		new.minus = 1;
		new.width *= -1;
	}
	new.specifier = *str;
	new.neg_prec = new.precision < 0;
	return (ft_print_specific(new, args));
}
