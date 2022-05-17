/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:43:06 by vserrao-          #+#    #+#             */
/*   Updated: 2021/10/29 17:43:11 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_array(char *res, unsigned int number, long int len)
{
	while (number > 0)
	{
		res[len--] = '0' + (number % 10);
		number = number / 10;
	}
	return (res);
}

static long int	ft_len(int n)
{
	long int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*res;
	long int		len;
	unsigned int	number;
	int				sign;

	sign = 1;
	len = ft_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!(res))
		return (NULL);
	res[len] = '\0';
	len--;
	if (n == 0)
		res[0] = '0';
	if (n < 0)
	{
		sign *= -1;
		number = n * -1;
		res[0] = '-';
	}
	else
		number = n;
	res = ft_array(res, number, len);
	return (res);
}
/*
int	main(void)
{
	int	n = -2147483648;

	printf("%s\n", ft_itoa(n));
}*/
