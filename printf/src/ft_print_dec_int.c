/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 09:42:56 by vserrao-          #+#    #+#             */
/*   Updated: 2022/02/01 15:49:12 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char	sign(t_format new)
{
	if (new.plus)
		return ('+');
	return ('-');
}

static int	ft_print_nbr(t_format new, char *nbr, int len, int neg)
{
	int	counter;

	counter = 0;
	new.width -= (new.space && !neg && !new.plus && new.width);
	if (neg || new.plus)
		counter += ft_putnchar(sign(new), 1);
	if (new.space)
		counter += ft_putnchar(' ', 1);
	if (!new.minus && new.width > new.precision && new.zero)
		counter += ft_putnchar('0', new.width - new.precision - neg - new.plus);
	else if (!new.minus && new.width > new.precision)
		counter += ft_putnchar(' ', new.width - new.precision - neg - new.plus);
	counter += ft_putnchar('0', new.precision - len);
	counter += (int)write(1, nbr, len);
	if (new.minus && new.width > new.precision)
		counter += ft_putnchar(' ', new.width - new.precision - neg - new.plus);
	return (counter);
}

int	ft_print_int(t_format new, va_list args)
{
	char	*nbr;
	int		n;
	int		counter;
	int		len;
	int		neg;

	n = va_arg(args, int);
	neg = (n < 0 && n != MIN_INT && new.specifier != 'u');
	if (neg)
		new.plus = 0;
	if (n < 0 && new.specifier != 'u')
		n *= -1;
	if (n < 0 && new.specifier == 'u')
		nbr = ft_uitoa((unsigned)n);
	else
		nbr = ft_itoa(n);
	len = ft_strlen(nbr);
	if (*nbr == '0' && !new.precision && new.dot)
		len = 0;
	if (new.precision < len || !new.dot)
		new.precision = len;
	counter = ft_print_nbr(new, nbr, len, neg);
	free(nbr);
	return (counter);
}
