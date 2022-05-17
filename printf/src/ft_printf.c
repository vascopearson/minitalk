/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 09:48:09 by vserrao-          #+#    #+#             */
/*   Updated: 2022/02/01 15:17:49 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		counter;
	int		i;
	va_list	args;
	char	*first;

	counter = 0;
	i = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (*(++str))
				counter += ft_eval((char *)str, args);
			while (*str && !ft_strchr(SPECIFIERS, *str))
				str++;
		}
		else
			counter += write(1, str, 1);
		if (*str)
			str++;
	}
	va_end(args);
	return (counter);
}

int	ft_print_specific(t_format new, va_list args)
{
	int	counter;

	counter = 0;
	if (new.specifier == 'c' || new.specifier == '%')
		counter = ft_print_char(new, args);
	if (new.specifier == 'd' || new.specifier == 'u' || new.specifier == 'i')
		counter = ft_print_int(new, args);
	if (new.specifier == 's')
		counter = ft_print_str(new, args);
	if (new.specifier == 'x' || new.specifier == 'X')
		counter = ft_print_hexa_int(new, args);
	if (new.specifier == 'p')
		counter = ft_print_hexa_ptr(new, args);
	return (counter);
}
