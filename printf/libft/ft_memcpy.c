/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:55:45 by vserrao-          #+#    #+#             */
/*   Updated: 2021/10/29 18:14:55 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i++;
	}
	return (dst);
}
/*
int main()
{
    char src[20] = "How Are you ?"; //Source String
    char dst[20] = {0}; //dst buffer
    //copy source buffer int dst
    ft_memcpy(dst,src,sizeof(src));
    printf("dst = %s\n", dst);
    return 0;
}*/
