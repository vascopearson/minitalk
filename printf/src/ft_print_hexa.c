/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 09:47:06 by vserrao-          #+#    #+#             */
/*   Updated: 2022/02/01 15:58:33 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char	*ft_hash(t_format new)
{
	if (new.specifier == 'X')
		return ("0X");
	return ("0x");
}

static int	ft_get_hexa(t_format new, size_t n, size_t iteration)
{
	int		counter;
	int		remainder;
	char	c;

	counter = 0;
	if (n > 0 || (!iteration && (new.specifier != 'p' || !new.dot)))
	{
		remainder = n % 16;
		if (new.specifier != 'X')
			c = HEXALOWER[remainder];
		else
			c = HEXAUPPER[remainder];
		n /= 16;
		iteration = 1;
		counter += ft_get_hexa(new, n, iteration);
		counter += ft_putnchar(c, 1);
	}
	return (counter);
}

int	ft_print_hexa_int(t_format new, va_list args)
{
	int				counter;
	unsigned int	n;
	int				len;

	counter = 0;
	n = va_arg(args, unsigned int);
	len = ft_nbrlen(n, 16);
	if (!n && !new.precision && new.dot)
		len = 0;
	if (new.precision < 0 || new.precision < len || !new.dot)
		new.precision = len;
	if (new.hash && n)
		new.width -= 2;
	counter += ft_putnstr(ft_hash(new), 2 * (new.hash && new.zero && n));
	if (!new.minus && new.width > new.precision && new.zero)
		counter += ft_putnchar('0', (new.width - new.precision));
	else if (!new.minus && new.width > new.precision)
		counter += ft_putnchar(' ', (new.width - new.precision));
	counter += ft_putnstr(ft_hash(new), 2 * (new.hash && !new.zero && n));
	counter += ft_putnchar('0', (new.precision - len));
	if (len)
		counter += ft_get_hexa(new, n, n);
	if (new.minus && new.width > new.precision)
		counter += ft_putnchar(' ', new.width - new.precision);
	return (counter);
}

int	ft_print_hexa_ptr(t_format new, va_list args)
{
	int		counter;
	size_t	address;
	int		len;

	counter = 0;
	address = va_arg(args, size_t);
	len = ft_nbrlen(address, 16);
	len *= !(!address && !new.precision && new.dot);
	if (new.precision < len || !new.dot)
		new.precision = len;
	new.width -= 2;
	counter += write(1, "0x", 2 * new.zero);
	if (!new.minus && !new.dot && new.width > new.precision && new.zero)
		counter += ft_putnchar('0', new.width - new.precision);
	else if (!new.minus && new.width > new.precision)
		counter += ft_putnchar(' ', new.width - new.precision);
	counter += write(1, "0x", 2 * !new.zero);
	counter += ft_putnchar('0', (new.precision - len) * (address != 0));
	counter += ft_putnchar('0', new.precision * (new.dot && !address));
	if (len)
		counter += ft_get_hexa(new, address, address);
	if (new.minus && new.width > new.precision)
		counter += ft_putnchar(' ', new.width - new.precision);
	return (counter);
}
