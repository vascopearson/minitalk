/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:58:41 by vserrao-          #+#    #+#             */
/*   Updated: 2021/10/20 08:42:21 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < size)
	{
		i++;
	}
	while ((src[j] != '\0') && ((j + i + 1) < size))
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
	{
		dst[i + j] = '\0';
	}
	return (i + ft_strlen(src));
}
/*
int main()
{
	char	dst[40] = "abc def";
	char	sr[] = "123";
	size_t	a;
	size_t	b;

	a = 12;
	b = ft_strlcat(dst, sr, a);
	printf("%zu", b);
}
*/
