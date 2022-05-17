/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserrao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:09:24 by vserrao-          #+#    #+#             */
/*   Updated: 2021/10/29 18:29:12 by vserrao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'))
	{
		if (i >= n)
		{
			return (0);
		}
		i++;
	}
	if (i < n)
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	else
		return (0);
}
/*
int main(void)
{
	char	*s1;
	char	*s2;
	int 	ret;

	s1 = "abcdefg";
	s2 = "abcdef";
	ret = ft_strncmp(s1, s2, 8);
	printf("%i\n", ret);
}*/
