/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 10:16:46 by vserrao-          #+#    #+#             */
/*   Updated: 2021/10/29 18:38:40 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	s;

	i = 0;
	s = 0;
	if (dstsize == 0)
	{
		while (src[s] != '\0')
			s++;
		return (s);
	}
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dest[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dest[i] = '\0';
	while (src[s] != '\0')
		s++;
	return (s);
}

/*
int main(void)
{
	char	str[] = "abcdefgh";
	char	dest[] = "teste";
	size_t	n = ft_strlcpy(dest, str, 6);
	printf("%s\n", dest);
	printf("%zu\n", n);
}
*/
