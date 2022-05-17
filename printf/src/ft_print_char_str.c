/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 09:41:19 by vserrao-          #+#    #+#             */
/*   Updated: 2022/02/01 15:30:03 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_print_char(t_format new, va_list args)
{
	char	c;
	int		counter;

	counter = 0;
	if (new.specifier == 'c')
		c = va_arg(args, int);
	else if (new.specifier == '%')
		c = '%';
	new.precision = 1;
	if (!new.minus && new.zero)
		counter += ft_putnchar('0', new.width - new.precision);
	else if (!new.minus && new.width > new.precision)
		counter += ft_putnchar(' ', new.width - new.precision);
	counter += (int)write(1, &c, 1);
	if (new.minus && new.width > new.precision)
		counter += ft_putnchar(' ', new.width - new.precision);
	return (counter);
}

int	ft_print_str(t_format new, va_list args)
{
	char	*str;
	int		counter;

	counter = 0;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	if (!new.dot || new.precision > ft_strlen(str) || new.precision < 0)
		new.precision = ft_strlen(str);
	if (!new.minus && new.width > new.precision && new.zero)
		counter += ft_putnchar('0', new.width - new.precision);
	else if (!new.minus && new.width > new.precision)
		counter += ft_putnchar(' ', new.width - new.precision);
	counter += ft_putnstr(str, new.precision);
	if (new.minus && new.width > new.precision)
		counter += ft_putnchar(' ', new.width - new.precision);
	return (counter);
}
