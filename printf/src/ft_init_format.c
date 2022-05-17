/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 09:40:53 by vserrao-          #+#    #+#             */
/*   Updated: 2022/02/01 15:18:09 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_format	ft_init_format(void)
{
	t_format	new;

	new.minus = 0;
	new.plus = 0;
	new.width = 0;
	new.precision = 0;
	new.specifier = 0;
	new.zero = 0;
	new.dot = 0;
	new.space = 0;
	new.hash = 0;
	new.neg_prec = 0;
	return (new);
}

int	ft_putnchar(char c, int n)
{
	int	counter;

	counter = 0;
	while (n-- > 0)
		counter += (int)write(1, &c, 1);
	return (counter);
}

int	ft_putnstr(char *s, int n)
{
	if (s != NULL)
		return ((int)write(1, s, n));
	return (0);
}

int	ft_nbrlen(long n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= base;
	}
	return (len);
}
