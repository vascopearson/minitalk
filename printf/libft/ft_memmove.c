/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:49:48 by vserrao-          #+#    #+#             */
/*   Updated: 2021/10/29 18:18:46 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	i = 0;
	if (!dst && !src)
		return (0);
	if (dst > src)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dst);
}
/*
int main()
{
    char str1[50] = "I am going from Delhi to Gorakhpur";
    printf("Orignal:\t%s\n",str1);
    printf("Source:\t\t%s\n", str1 + 5);
    printf("Destination:\t%s\n", str1 + 11);
    ft_memmove(str1 + 11, str1 + 5, 29);
    printf("Result:\t\t%s\n", str1);
}
*/
